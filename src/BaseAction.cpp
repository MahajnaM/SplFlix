#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"
using namespace std;

ActionStatus BaseAction::getStatus() const {//done
    return status;
}

void BaseAction::complete() {
    status=COMPLETED;
}


void BaseAction::error( const std::string &errorMsg) {
status=ERROR;
this->errorMsg="ERROR - " + errorMsg; // changed
}


std::string BaseAction::getErrorMsg() const {
    return this->errorMsg;
}

BaseAction::BaseAction():errorMsg(""),status(PENDING){};
