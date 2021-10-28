#ifndef SESSION_H_
#define SESSION_H_
#include <vector>
#include <unordered_map>
#include <string>
#include "Action.h"
#include "User.h"
using namespace std;
class User;
class Watchable;
class BaseAction;

class Session{
public:
    Session(const std::string &configFilePath);//constructor done
   ~Session();//destructor
    Session(const Session& other);// copy constructor
   Session& operator=( const Session &other);//copy assigment operator
   Session(Session && other);//move constructor
    Session& operator=(Session &&other);; //move assigment operator*/
    void clean();
    void start(); //done
   unordered_map<std::string,User*>& getmap(); // done - added
    User* getActiveUser();// done-added
    vector<BaseAction*>& getactionsLog();//added //done
    void setActiveUser(string &name); // added // done
    vector<Watchable*>& getcontent(); // added
    vector<string> split(const string& str);
    std::vector<std::string> get_command() const;
    void setCommand(string);
private:
    std::vector<Watchable*> content; // content's vector // done
    std::vector<BaseAction*> actionsLog; // actionslog map // done
    std::unordered_map<std::string,User*> userMap; // the users map // done
    User* activeUser;//done
    std::vector<std::string> command;
};
#endif
