#include <iostream>
#include <string>
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"

GenreRecommenderUser::GenreRecommenderUser(const std::string &name) : User(name) {} // done , constructor

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {

    int maxTag;
    while (s.getActiveUser()->getUsertags().size() > 0) {
        string mostCommonTag;
        maxTag = 0;
        for (auto i : s.getActiveUser()->getUsertags()) {
            if (i.second > maxTag) {
                maxTag = i.second;
                mostCommonTag = i.first;
            }
        }

        for (auto i : s.getActiveUser()->getUsertags()) {
            if (i.second == maxTag && i.first < mostCommonTag) {
                mostCommonTag = i.first;
            }
        }

        for (auto i: s.getcontent()) {
            for (auto j:i->getTags()) {
                if (j == mostCommonTag && didNotWatch(i)) {
                    return i;
                }
            }
        }
        s.getActiveUser()->getUsertags().erase(mostCommonTag);
    }
    return nullptr;
}

string GenreRecommenderUser::getHisAlgo() {
    hisAlgo = "gen";
    return hisAlgo;
}

User *GenreRecommenderUser::clone() {
    return new GenreRecommenderUser(*this);
}