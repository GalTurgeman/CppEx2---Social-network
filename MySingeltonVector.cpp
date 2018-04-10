#include <clocale>
#include <iostream>
#include "MySingeltonVector.h"

bool MySingeltonVector::instanceFlag = false;
MySingeltonVector *MySingeltonVector::instance = NULL;

MySingeltonVector::MySingeltonVector() {}

MySingeltonVector::~MySingeltonVector() {}

void MySingeltonVector::deleteInstance() {
    instanceFlag = false;
    delete instance;
    instance = NULL;
}

MySingeltonVector *MySingeltonVector::getInstance() {

    if (!instanceFlag) {
        instance = new MySingeltonVector();
        instanceFlag = true;
        return instance;
    }

    return instance;

}

int MySingeltonVector::get(int i) {
    return v[i];
}

bool MySingeltonVector::contains(int id) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == id)
            return true;
    }
    return false;
}

void MySingeltonVector::addToList(int id) {
    v.push_back(id);
}

void MySingeltonVector::remove(int id) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == id) {
            v.erase(v.begin() + i);
        }
    }
}

int MySingeltonVector::size() {
    return v.size();
}

