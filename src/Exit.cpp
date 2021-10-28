#include "../include/Action.h"


void Exit::act(Session &sess) {
    complete();
}


std::string Exit::toString() const {
    return "Exit COMLETED";
}
BaseAction* Exit::clone() {
    return new Exit(*this);
}