#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <iostream>
#include <vector>
#include "../include/User.h"
#include "../include/Session.h"
using namespace std;
class Session;

enum ActionStatus{
	PENDING, COMPLETED, ERROR
};


class BaseAction{
public:
	BaseAction();
	virtual ~BaseAction() = default;
	ActionStatus getStatus() const; // done; -----------------
	virtual void act(Session& sess)=0; // virtual , no need;---------------
	virtual std::string toString() const=0; // virtual , no need;----------------
	virtual BaseAction* clone()=0;
    protected:
	void complete(); // done -------------
	void error(const std::string& errorMsg); // done-----
    std::string getErrorMsg() const; // done

private:
	std::string errorMsg;//done -------- // changed
	ActionStatus status;//done --------------

};



class CreateUser  : public BaseAction { // done
public:
	virtual void act(Session& sess); // done
	virtual std::string toString() const; // done
    virtual BaseAction* clone();
private:
};



class ChangeActiveUser : public BaseAction { // done
public:
	virtual void act(Session& sess);//done
	virtual std::string toString() const;//done
    virtual BaseAction* clone();
private:
};




class DeleteUser : public BaseAction {//done
public:
	virtual void act(Session & sess);//done
	virtual std::string toString() const; // done
    virtual BaseAction* clone();
private:
};




class DuplicateUser : public BaseAction {//done
public:
	virtual void act(Session & sess);
	virtual std::string toString() const;
    virtual BaseAction* clone();
private:
};




class PrintContentList : public BaseAction {//done
public:
	virtual void act (Session& sess); // done
	virtual std::string toString() const; //done
    virtual BaseAction* clone();
};




class PrintWatchHistory : public BaseAction {//done
public:
	virtual void act (Session& sess);//done
	virtual std::string toString() const;//done
    virtual BaseAction* clone();
private:
};





class Watch : public BaseAction {//done
public:
	virtual void act(Session& sess);
	virtual std::string toString() const;
    virtual BaseAction* clone();
private:
};


class PrintActionsLog : public BaseAction { //done
public:
	virtual void act(Session& sess);//done
	virtual std::string toString() const;//done
    virtual BaseAction* clone();
};

class Exit : public BaseAction {//done
public:
	virtual void act(Session& sess);
	virtual std::string toString() const;
    virtual BaseAction* clone();
};
#endif
