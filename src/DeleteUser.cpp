#include "../include/Action.h"


void DeleteUser::act(Session &sess) {
    string name = sess.get_command()[1];
    if (sess.getmap().count(name) == 0) {
        error("The user does not exist");
        cout << getErrorMsg() << endl;
    } else {
        delete(sess.getmap()[name]);
        sess.getmap().erase(name);
        complete();
    }
}
std::string DeleteUser::toString() const {
    if(getStatus()==ERROR){
        return "DeleteUser "+getErrorMsg();
    }
    if(getStatus()==PENDING)
        return "DeleteUser PENDING";
    else
        return "DeleteUser COMPLETED";
}
BaseAction* DeleteUser::clone() {
return new DeleteUser(*this);
}