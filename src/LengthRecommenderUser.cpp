#include <iostream>
#include <string>
#include <algorithm>
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"
using namespace std;


LengthRecommenderUser::LengthRecommenderUser(const std::string &name):User(name){ // done
}

Watchable* LengthRecommenderUser::getRecommendation(Session &s) {//done
    double average = 0;
    vector<Watchable *> ownHistory = get_history();
    vector<pair<int, int>> NotWatch;
    for (unsigned int i = 0; i < ownHistory.size(); ++i) {
        average += ownHistory.at(i)->get_Length();
    }
    average = (average) / (ownHistory.size());
    for (unsigned int i = 0; i < s.getcontent().size(); ++i) {
        if (find(ownHistory.begin(),ownHistory.end(), s.getcontent().at(i)) == ownHistory.end())
            NotWatch.push_back({abs(s.getcontent().at(i)->get_Length()-average),i});
    }
    sort(NotWatch.begin(),NotWatch.end());
    if(!NotWatch.empty())
        return s.getcontent().at(NotWatch.at(0).second);
    else{
        return nullptr;
    }

}


string LengthRecommenderUser::getHisAlgo() {
   hisAlgo="len";
    return hisAlgo;
}
User* LengthRecommenderUser::clone() {
    return new LengthRecommenderUser(*this);
}

