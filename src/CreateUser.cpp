#include "../include/Action.h"

using namespace std;

void CreateUser::act(Session &sess) {
    string name = sess.get_command()[1];
    string algo = sess.get_command()[2];
    if (sess.getmap().count(name)) {
        error("The user is already exist");
        cout << getErrorMsg() << endl;
    } else {
        if (algo == "len") {
            sess.getmap().insert({name, new LengthRecommenderUser(name)});
            complete();
        } else if (algo == "rer") {
            sess.getmap().insert({name, new RerunRecommenderUser(name)});
            complete();
        } else if (algo == "gen") {
            sess.getmap().insert({name, new GenreRecommenderUser(name)});
            complete();
        } else {
            error("invaild recommendation algorithm");
            cout << getErrorMsg() << endl;
        }
    }
}

std::string CreateUser::toString() const {
    if (getStatus() == ERROR) {
        return "CreateUser " + getErrorMsg();
    }
    if (getStatus() == PENDING)
        return "CreateUser PENDING";
    else
        return "CreateUser COMPLETED";
}

BaseAction *CreateUser::clone() {
    return new CreateUser(*this);
}