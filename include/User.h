#ifndef USER_H_
#define USER_H_

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

class Watchable;

class Session;

//rule of 3
class User {
public:
    User(const std::string &name); //done
    virtual Watchable *getRecommendation(Session &s) = 0; // no need
    std::string getName() const;//done
    std::vector<Watchable *> get_history() const;//done
    virtual ~User() = default;//done // added
    virtual string getHisAlgo();//done //added
    void addToHistory(Watchable *); //added
    map<string, int> &getUsertags();//added
    void addtoTags(string &s);//added
    bool didNotWatch(Watchable *); //added
    virtual User *clone() = 0;

    virtual void fixHistory(vector<Watchable *> &s);

    virtual void set_name(string nename);

protected:
    std::vector<Watchable *> history; //done
    string hisAlgo;//done // added
private:
    std::string name; // done
    map<string, int> Usertags;//added
};


class LengthRecommenderUser : public User {
public:
    LengthRecommenderUser(const std::string &name); // done
    virtual Watchable *getRecommendation(Session &s); // done
    virtual string getHisAlgo();//done //added
    virtual User *clone();
};

//-----------------------------------------------------------------


class RerunRecommenderUser : public User {
public:
    RerunRecommenderUser(const std::string &name); //done
    virtual Watchable *getRecommendation(Session &s);// done
    virtual string getHisAlgo();//done //added
    virtual User *clone();

private:
    unsigned int i;
};


//-----------------------------------------------------------------

class GenreRecommenderUser : public User {
public:
    GenreRecommenderUser(const std::string &name); // done
    virtual Watchable *getRecommendation(Session &s); // not yet
    virtual string getHisAlgo();//done //added
    virtual User *clone();
};

#endif
