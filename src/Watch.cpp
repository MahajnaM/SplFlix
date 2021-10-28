#include "../include/Action.h"
#include "../include/Watchable.h"

using namespace std;


void Watch::act(Session &sess) {
    string content_id = sess.get_command()[1];

    unsigned long c_id = stol(content_id);
    if (c_id > (sess.getcontent().size())) {
        error("The content is not exist");
        cout << getErrorMsg() << endl;
    } else {
        cout << "Watching " + sess.getcontent().at(c_id - 1)->toString() << endl;
        sess.getActiveUser()->addToHistory(sess.getcontent().at(stol(content_id) - 1));
        for (unsigned int i = 0; i < sess.getcontent().at(stol(content_id) - 1)->getTags().size(); ++i) {
            sess.getActiveUser()->addtoTags(sess.getcontent().at(stol(content_id) - 1)->getTags().at(i));
        }
        complete();
        cout << "We recommend watching " << sess.getcontent().at(c_id - 1)->getNextWatchable(sess)->toString()
             << ",continue watching? [y/n]" << endl;
        string input;
        getline(cin, input);
        if (input == "y") {
            string s = to_string(sess.getcontent().at(c_id - 1)->getNextWatchable(sess)->get_id());
            sess.setCommand("rewatch " + s);
        }
    }

}


std::string Watch::toString() const {
    if (getStatus() == ERROR) {
        return "Watch " + getErrorMsg();
    }
    if (getStatus() == PENDING)
        return "Watch PENDING";
    else
        return "Watch COMPLETED";
}

BaseAction *Watch::clone() {
    return new Watch(*this);
}