#include "../include/Action.h"
#include "../include/Watchable.h"
using namespace std;

void PrintWatchHistory::act(Session &sess) {
    if (sess.getActiveUser()->get_history().empty()) {
        error("The WatchList is empty");
        cout << getErrorMsg()<<endl;
    } else {
        vector<Watchable *> WatchList = sess.getActiveUser()->get_history();
        cout << "Watch history for " + sess.getActiveUser()->getName() << endl;

        for (size_t i = 0; i < WatchList.size(); ++i) {
            cout << to_string(i+1) + ". " + WatchList.at(i)->toString() << endl;
        }
        complete();
    }
}

std::string PrintWatchHistory::toString() const {
    if(getStatus()==ERROR){
        return "PrintWatchHistory "+getErrorMsg();
    }
    if(getStatus()==PENDING)
        return "PrintWatchHistory PENDING";
    else
        return "PrintWatchHistory COMPLETED";
}

BaseAction* PrintWatchHistory::clone() {
return new PrintWatchHistory(*this);
}