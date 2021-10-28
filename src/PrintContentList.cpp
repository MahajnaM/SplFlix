#include "../include/Action.h"
#include "../include/Watchable.h"
using namespace std;

void PrintContentList::act(Session &sess) {
    if (sess.getcontent().empty()) {
        error("The ContentList is empty");
        cout << getErrorMsg() << endl;
    } else {
        for (unsigned int i = 0; i < sess.getcontent().size(); ++i) {
            cout << sess.getcontent().at(i)->get_id() << ". " << sess.getcontent().at(i)->toString()<<sess.getcontent().at(i)->tostring1() << endl;
        }
        complete();
    }
}
std::string PrintContentList::toString() const {
    if(getStatus()==ERROR){
        return "PrintContentList "+getErrorMsg();
    }
    if(getStatus()==PENDING)
        return "PrintContentList PENDING";
    else
        return "PrintContentList COMPLETED";
}
BaseAction* PrintContentList::clone() {
return new PrintContentList(*this);
}