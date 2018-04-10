#include "Member.h"
#include <algorithm>

//constructor
Member::Member() {
    id = idCreator; //create specific id for Member
    ++idCreator;
    ++numUsers;
    v->addToList(id);
}

//destructor
Member::~Member() {
    for (int i = 0; i < v->size(); ++i) {
        if (v->get(i) == id) {
            v->remove(id);
            --numUsers;
        }
    }

    if (v->size() == 0)
        v->deleteInstance();
}


int Member::count() { return numUsers; }

void Member::follow(Member &other) {
    for (int i = 0; i < followList.size(); ++i) {
        if (other.id == (*followList[i]).id || other.id == id) return; //already following member
    }

    //not following Member. Add it to following list
    followList.push_back(&other);
    other.followMeList.push_back(&(*this));
}

void Member::unfollow(Member &other) {
    for (int i = 0; i < followList.size(); ++i) {//find other member
        if (other.id == (*followList[i]).id) {
            followList.erase(followList.begin() + i); //remove Member from my follow list
        }
    }

    for (int i = 0; i < other.followMeList.size(); ++i) {//find me on other's  followMe list
        if (other.followMeList[i]->id == id) {
            other.followMeList.erase(other.followMeList.begin() + i); //remove Member
        }
    }

}

int Member::numFollowers() {
    for (int i = 0; i < followMeList.size(); ++i) {
        if (!v->contains(followMeList[i]->id))
            followMeList.erase(followMeList.begin() + i);
    }
    return followMeList.size();
}

int Member::numFollowing() {
    for (int i = 0; i < followList.size(); ++i) {
        if (!v->contains(followList[i]->id))
            followList.erase(followList.begin() + i);
    }
    return followList.size();
}
