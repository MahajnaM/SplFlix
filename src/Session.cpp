#include "../include/Session.h"
#include "../include/Watchable.h"
#include "../include/Action.h"
#include "../include/User.h"
#include "../include/json.hpp"
#include <fstream>
#include <iterator>
#include <unordered_map>

using namespace std;
using json = nlohmann::json;

Session::Session(const std::string &configFilePath) { //done
    activeUser = new LengthRecommenderUser("default"); // should delete it after end // pointer
    userMap.insert({"default", activeUser});
    json Json;
    ifstream i(configFilePath);
    i >> Json;
    long ID = 1;
    for (unsigned int i = 0; i < Json["movies"].size(); ++i) {
        string movieName = Json["movies"][i]["name"];
        int movieLength = Json["movies"][i]["length"];
        vector<string> tags = Json["movies"][i]["tags"];
        Movie *addedMovies = new Movie(ID, movieName, movieLength, tags);
        content.push_back(addedMovies);
        ++ID;
    }

    for (unsigned int i = 0; i < Json["tv_series"].size(); ++i) {
        string seriesName = Json["tv_series"][i]["name"];
        int movieLength = Json["tv_series"][i]["episode_length"];
        vector<string> tags = Json["tv_series"][i]["tags"];
        int season = 0;
        for (unsigned int j = 0; j < Json["tv_series"][i]["seasons"].size(); ++j) {
            season++;
            for (unsigned int x = 0; x < Json["tv_series"][i]["seasons"][j]; ++x) {
                Episode *addedEpisode =
                        new Episode(ID,
                                    seriesName, movieLength, season, x + 1, tags);
                content.push_back(addedEpisode);
                ++ID;
            }
        }


    }
}

//done -----------------------------------
Session::~Session() { // destructor//done 100%
    for (auto i : actionsLog) {
        delete i;
    }
    actionsLog.clear();
    for (auto i: content) {
        delete i;
    }
    content.clear();

    for (auto x : userMap) {
        delete x.second;
    }
    userMap.clear();
    command.clear();
    activeUser = nullptr;
}

//----------------------------------------------------------------------------------------------------------------------
Session::Session(const Session &other):content(),actionsLog(),userMap(),activeUser(nullptr),command(other.command) { //copy constructor // done 100%
    for (auto x :other.content) {
        content.push_back(x->clone());
    }
    for (auto x : other.actionsLog) {
        actionsLog.push_back(x->clone());
    }
    for (auto x : other.userMap) {
        userMap.insert({x.first, x.second->clone()});
    }
    for (auto& x :userMap) {
        x.second->fixHistory(content);
    }
    activeUser = userMap[other.activeUser->getName()];
}

//----------------------------------------------------------------------------------------------------------------------
Session &Session::operator=(const Session &other) { // copy assigment operator // done 100%
    if (this == &other) {
        return *this;
    }
    this->clean();
    for (unsigned int i = 0; i < other.content.size(); ++i) {
        content.push_back(other.content.at(i)->clone());
    }
    for (unsigned int i = 0; i < other.actionsLog.size(); ++i) {
        actionsLog.push_back(other.actionsLog.at(i)->clone());
    }
    for (auto iter = other.userMap.begin(); iter != other.userMap.end(); ++iter) {
        userMap.insert({iter->first, iter->second->clone()});
    }
    activeUser = other.activeUser->clone();
    return *this;
}

//----------------------------------------------------------------------------------------------------------------------
Session::Session(Session &&other) { // move constructor//done 100%
    for (unsigned i = 0; i < other.content.size(); i++) {
        content.push_back(other.content.at(i));
        other.content.at(i)= nullptr;
    }
    for (unsigned i = 0; i < other.actionsLog.size(); i++) {
        actionsLog.push_back(other.actionsLog.at(i));
        other.actionsLog.at(i)= nullptr;
    }
    for (auto x : other.userMap) {
        userMap.insert({x.first, x.second});
        x.second= nullptr;

    }
    activeUser = other.activeUser;
}

//----------------------------------------------------------------------------------------------------------------------
Session &Session::operator=(Session &&other) {// move assigment operator//done 100%
    if (this != &other) {
        this->clean();
        vector<Watchable *>::iterator iter;
        for (iter = other.content.begin(); iter != other.content.end(); ++iter) {
            content.push_back((*iter));
            *iter = nullptr;
        }
        vector<BaseAction *>::iterator it;
        for (it = other.actionsLog.begin(); it != other.actionsLog.end(); ++it) {
            actionsLog.push_back((*it));
            *it = nullptr;
        }
        for (auto x : other.userMap) {
            userMap.insert({x.first, x.second});
            x.second= nullptr;
        }
        activeUser = userMap.at(other.getActiveUser()->getName());
    }
    return *this;
}
//copied: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
vector<string> Session::split(const string& str)
{

    vector<string> tokens;
    if(str.empty()){
        tokens.emplace_back();
        return tokens;
    }
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(' ', prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + 1;//plus " "(space) length
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void Session::start() {
    cout << "SPLFLIX is now on!" << endl;
    command=split("");
    while (command[0] != "exit") {
        string input;

        if(command[0]!="rewatch") {
            getline(cin, input);
            command = split(input);
        }
        else
            command[0]="watch";

        BaseAction *action;
        if (command[0] == "createuser")
            action = new CreateUser();
        else if (command[0] == "changeuser")
            action  = new ChangeActiveUser();
        else if (command[0] == "deleteuser")
            action = new DeleteUser();
        else if (command[0] == "dupuser")
            action = new DuplicateUser();
        else if (command[0] == "content")
            action = new PrintContentList();
        else if (command[0] == "watchhist")
            action = new PrintWatchHistory();
        else if (command[0] == "watch")
            action = new Watch();
        else if (command[0] == "log")
            action = new PrintActionsLog();
        else if (command[0] == "exit")
            action = new Exit();
        else{
            cout << "invalid input" << endl;
            continue;
        }
        action->act(*this);
        actionsLog.push_back(action);;
    }
}


unordered_map<std::string, User *> &Session::getmap() {
    return userMap;
}

User *Session::getActiveUser() {
    return activeUser;
}


vector<BaseAction *> &Session::getactionsLog() {
    return this->actionsLog;
}


void Session::setActiveUser(string &name) {
    activeUser = userMap.find(name)->second;
}


vector<Watchable *> &Session::getcontent() {
    return content;
}

std::vector<std::string> Session::get_command() const {
    return command;
}

void Session::setCommand(string cd) {
    command=split(cd);
}

void Session::clean() {
    for (auto i : actionsLog) {
        delete i;
    }
    actionsLog.clear();
    for (auto i: content) {
        delete i;
    }
    content.clear();

    for (auto x : userMap) {
        delete x.second;
    }
    userMap.clear();
    command.clear();
    activeUser = nullptr;
}
