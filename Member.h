#include <vector>
#include <array>
#include <string>
#include <iostream>

#pragma once

static int numUsers, idCreator;

using namespace std;

class Member {

private:
    vector<Member*> followList; //list of people i follow
    vector<Member*> followMeList; //list of people who follow me
    int id;

public:

    void follow(Member &other);

    void unfollow(Member &other);

    int numFollowers();

    int numFollowing();

    static int count() { return numUsers; }

    //constructor
    Member() {
        id = idCreator; //create specific id for Member
        ++idCreator;
        ++numUsers;
//        cout << "number of users: " << numUsers << endl;
//        cout << "idCreator: " << idCreator << endl;
    }

    //destructor
    ~Member() {
        --numUsers;
    }

};

