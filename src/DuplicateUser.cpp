#include "../include/Action.h"
#include "../include/Watchable.h"

void DuplicateUser::act(Session &sess) {
    string name = sess.get_command()[1];
    string newone = sess.get_command()[2];
    if (sess.getmap().count(name) == 0) {
        error("The user does not exist");
        cout << getErrorMsg() << endl;
    } else if (sess.getmap().count(newone)) {
        error("The new name is already taken");
        cout << getErrorMsg() << endl;
    } else {
        User *DuplicatedUser = sess.getmap()[name]->clone();
        DuplicatedUser->set_name(newone);
        sess.getmap().insert({newone, DuplicatedUser});
        complete();
    }
}

std::string DuplicateUser::toString() const {
    if (getStatus() == ERROR) {
        return "DupliacteUser " + getErrorMsg();
    }
    if (getStatus() == PENDING)
        return "DupliacteUser PENDING";
    else
        return "DupliacteUser COMPLETED";
}

BaseAction *DuplicateUser::clone() {
    return new DuplicateUser(*this);
}