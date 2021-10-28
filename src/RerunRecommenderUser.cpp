#include <iostream>
#include <string>
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"


RerunRecommenderUser::RerunRecommenderUser(const std::string &name) : User(name), i(0) {
} // done , constructor

Watchable *RerunRecommenderUser::getRecommendation(Session &s) { // done
    Watchable *recoWatch = s.getActiveUser()->get_history().at((i + 1) % history.size());
    i = (i + 1) % history.size();
    return recoWatch;
}

string RerunRecommenderUser::getHisAlgo() {
    hisAlgo = "rer";
    return hisAlgo;
}

User *RerunRecommenderUser::clone() {
    return new RerunRecommenderUser(*this);
}
