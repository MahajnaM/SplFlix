#include "../include/Action.h"


void ChangeActiveUser::act(Session &sess) {
    string name = sess.get_command()[1];
    if (sess.getmap().count(name) == 0) {
        error("The user does not exist");
        cout << getErrorMsg() << endl;
    } else {
        sess.setActiveUser(name);
        complete();
    }
}

std::string ChangeActiveUser::toString() const {
    if (getStatus() == ERROR)
        return "ChangeUser " + getErrorMsg();
    else if (getStatus() == PENDING)
        return "ChangeUser PENDING";
    else
        return "ChangeUser COMPLETED";
}

BaseAction *ChangeActiveUser::clone() {
    return new ChangeActiveUser(*this);
}