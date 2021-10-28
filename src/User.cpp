#include <iostream>
#include "../include/User.h"
#include "../include/Watchable.h"
#include <vector>
#include <iterator>

using namespace std;

User::User(const std::string &name) : history(),hisAlgo(),name(name),Usertags() {

}

std::vector<Watchable *> User::get_history() const {
    return history;
}

std::string User::getName() const {
    return name;
}

// done , default destructor

string User::getHisAlgo() { //done
    return hisAlgo;
}

void User::addToHistory(Watchable *added) {//done
    history.push_back(added);
}

map<string, int> &User::getUsertags() {
    return Usertags;
}

void User::addtoTags(string &s) {//added
    bool flag = false;
    for (auto i : Usertags) {
        if (i.first == s) {
            i.second++;
            flag = true;
        }
    }
    if (!flag)
        Usertags.insert({s, 1});
}

bool User::didNotWatch(Watchable *w) {
    for (unsigned int i = 0; i < get_history().size(); ++i) {
        if (get_history().at(i) == w) {
            return false;
        }
    }
    return true;
}

void User::fixHistory(vector<Watchable *> & content) {
    for (size_t i = 0; i < history.size(); ++i) {
        history[i]=content[history[i]->get_id()-1];
    }
}

void User::set_name(string nename) {
    this->name=nename;
}
