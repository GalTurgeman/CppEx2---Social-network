#include <vector>

#pragma once

class MySingeltonVector {

private:
    std::vector<int> v;

    MySingeltonVector();

    static MySingeltonVector *instance;
    static bool instanceFlag;

public:
    static MySingeltonVector *getInstance();

    void addToList(int id);

    void remove(int id);

    int size();

    int get(int i);

    bool contains(int id);

    ~MySingeltonVector();

    void deleteInstance();

};