#include "../include/Watchable.h"
#include "../include/User.h"
#include "../include/Session.h"

using namespace std;

Watchable::Watchable(long id, int length, const std::vector<std::string> &tags) :
        id(id), length(length), tags(tags) {} // constructor of watchable


long Watchable::get_id() {//done
    return id;
}

int Watchable::get_Length() const { // done
    return length;
}

vector<string> Watchable::getTags() const { // done
    return tags;
}





//MOVIE
//--------------------------------------------------------------------------------------------------

Movie::Movie(long id, const std::string &name, int length, const std::vector<std::string> &tags)
        : Watchable(id, length, tags), name(name) {}


std::string Movie::toString() const { // not yet
    return name;

}

string Movie::tostring1() const {
    string s = " " + to_string(get_Length()) + " minutes" + "[";
    for (unsigned int i = 0; i < getTags().size(); ++i) {
        if (i < getTags().size() - 1)
            s = s + getTags().at(i) + ", ";
        else
            s = s + getTags().at(i);
    }
    return s + "]";
}

Watchable *Movie::getNextWatchable(Session &sess) const { //done
    Watchable *nextMovie = sess.getActiveUser()->getRecommendation(sess);
    return nextMovie;
}

Watchable *Movie::clone() { // added
    return new Movie(*this);
}

string Movie::getType() const { //added done
    return "Movie";
}

string Movie::getName() const { //added done
    return name;
}


//EPISODE
//-------------------------------------------------------------------------------------------------
Episode::Episode(long id, const std::string &seriesName, int length, int season, int episode,
                 const std::vector<std::string> &tags)
        : Watchable(id, length, tags), seriesName(seriesName), season(season), episode(episode) {
    this->nextEpisodeId = id + 1;
}

std::string Episode::toString() const {// done //
    return seriesName + " S" + to_string(season) + "E" + to_string(episode);

}

string Episode::tostring1() const {
    string s = " " + to_string(get_Length()) + " minutes" + "[";
    for (unsigned int i = 0; i < getTags().size(); ++i) {
        if (i < getTags().size() - 1)
            s = s + getTags().at(i) + ", ";
        else
            s = s + getTags().at(i);
    }
    return s + "]";
}

Watchable *Episode::getNextWatchable(Session &sess) const {
    for (unsigned int i = 0; i < sess.getcontent().size(); ++i) {
        if (sess.getcontent().at(i)->get_id() == getNextID())
            if (sess.getcontent().at(i)->getType() == "Episode")
                if (sess.getcontent().at(i)->getName() == getName())
                    return sess.getcontent().at(i);
    }
    return sess.getActiveUser()->getRecommendation(sess);
}

Watchable *Episode::clone() { // added done
    return new Episode(*this);
}

string Episode::getType() const { //added done
    return "Episode";
}

long Episode::getNextID() const { // added done
    return nextEpisodeId;
}

string Episode::getName() const {//added done
    return seriesName;
}