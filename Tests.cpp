#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Member.h"

TEST_CASE("Testing the follow function") {
    Member m1, m2, m3;
    m1.follow(m2);
    m1.follow(m3);
    CHECK(m1.numFollowing() == 2);
    CHECK(m2.numFollowers() == 1);
    CHECK(m3.numFollowers() == 1);
}
TEST_CASE("Testing the unfollow funtion"){
    Member m1, m2, m3;
    m1.follow(m2);
    m1.follow(m3);
    m1.unfollow(m2);
    m1.unfollow(m3);
    CHECK(m1.numFollowing() == 0);
    CHECK(m2.numFollowers() == 0);
    CHECK(m3.numFollowers() == 0);
}
TEST_CASE("Testing the count function"){
    Member m1, m2, m3;
    CHECK(Member::count() == 3);
}

