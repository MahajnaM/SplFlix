#include "../include/Action.h"

using namespace std;

void PrintActionsLog::act(Session &sess) {
    if (sess.getactionsLog().empty()) {
        error("The ActionLogList is empty");
        cout << getErrorMsg() << endl;
    } else {
        vector<BaseAction *> actionsLog = sess.getactionsLog();
        for (size_t i = 0; i < actionsLog.size(); ++i) {
            size_t pos = actionsLog.size() - 1 - i;
            cout << actionsLog.at(pos)->toString() << endl;
        }
        complete();
    }
}
std::string PrintActionsLog::toString() const {
    if(getStatus()==ERROR){
        return "PrintActionsLog "+getErrorMsg();
    }
    if(getStatus()==PENDING)
        return "PrintActionsLog PENDING";
    else
        return "PrintActionsLog COMPLETED";
}
BaseAction* PrintActionsLog::clone() {
return new PrintActionsLog(*this);
}