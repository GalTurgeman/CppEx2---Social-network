#include <vector>
#include <array>
#include <string>
#include <iostream>
#include "MySingeltonVector.h"

#pragma once

using namespace std;

static int idCreator, numUsers;

class Member {

private:
    vector<Member *> followList; //list of people i follow
    vector<Member *> followMeList; //list of people who follow me
    int id;
    MySingeltonVector *v = MySingeltonVector::getInstance(); //list of all members in the system


public:

    void follow(Member &other);

    void unfollow(Member &other);

    int numFollowers();

    int numFollowing();

    static int count();

    Member();

    ~Member();


};

