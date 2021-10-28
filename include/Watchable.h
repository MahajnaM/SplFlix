#ifndef WATCHABLE_H_
#define WATCHABLE_H_

#include <string>
#include <vector>
using namespace std;

class Session;
// rule of 3
class Watchable{ // done
public:
    Watchable(long id, int length, const std::vector<std::string>& tags); // done
    virtual ~Watchable() = default; // destructor
    virtual std::string toString() const = 0;//no need
    virtual string tostring1() const =0;//added
    virtual Watchable* getNextWatchable(Session&) const = 0; // no need
    long get_id();//added // done
    virtual string getType() const=0 ;//done
    virtual string getName() const=0; //done
    int get_Length() const ;//added // done
    virtual vector<string> getTags() const; //done
    virtual Watchable* clone()=0;//added
private:
    const long id; //done
    int length;//done
    std::vector<std::string> tags; // done

};


//MOVIE
//---------------------------------------------------------------------------------------------------
class Movie : public Watchable{ // done
public:
    Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags);//done
    virtual std::string toString() const;//done
    virtual string tostring1() const;//added
    virtual Watchable* getNextWatchable(Session&) const; // done
    virtual Watchable* clone();//added
    virtual string getType() const;// done
    virtual string getName() const; // done

private:
    std::string name;//done
};

//EPISODE
//-----------------------------------------------------------------------------------------------------

class Episode: public Watchable{
public:
    Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags);//done
    virtual std::string toString() const; // done
    virtual string tostring1() const;//added
    virtual Watchable* getNextWatchable(Session&) const; // done // must delete pointer
    virtual Watchable* clone();//added
    virtual string getType() const;// done
    long getNextID() const ;//done
    virtual string getName() const; // done
private:
    string seriesName;//done
    int season;//done
    int episode;//done
    long nextEpisodeId;//done
};

#endif
