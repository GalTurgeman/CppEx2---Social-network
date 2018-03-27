#include "Member.h"

void Member::follow(Member &other) {

    for (int i = 0; i < followList.size(); ++i) {
        if (other.id == (*followList[i]).id) return; //already following member
    }

    //not following Member. Add it to following list
    followList.push_back(&other);
    other.followMeList.push_back(&(*this));
}

void Member::unfollow(Member &other) {

    for (int i = 0; i < followList.size(); ++i) {
        if (other.id == (*followList[i]).id) {
            followList.erase(followList.begin() + i); //remove Member
        }
    }

    for (int i = 0; i < other.followMeList.size(); ++i) {
        if (other.followMeList[i]->id==id) {
            other.followMeList.erase(other.followMeList.begin() + i); //remove Member
        }
    }

}

int Member::numFollowers() {
    return followMeList.size();
}

int Member::numFollowing() {
    return followList.size();
}
