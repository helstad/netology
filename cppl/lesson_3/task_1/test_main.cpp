#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include "List.hpp"

TEST_CASE("Empty list is empty", "[Empty]") {
    List list;
    REQUIRE(list.Empty());
}

TEST_CASE("Size of empty list is zero", "[Size]") {
    List list;
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Size of list after adding elements", "[Size]") {
    List list;
    list.PushFront(42);
    list.PushBack(17);
    REQUIRE(list.Size() == 2);
}

TEST_CASE("Clear empties the list", "[Clear]") {
    List list;
    list.PushFront(42);
    list.PushBack(17);
    list.Clear();
    REQUIRE(list.Empty());
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Clear doesn't affect other lists", "[Clear]") {
    List list1;
    list1.PushFront(42);
    list1.PushBack(17);

    List list2;
    list2.PushBack(99);

    list1.Clear();

    REQUIRE(list1.Empty());
    REQUIRE(list1.Size() == 0);

    REQUIRE(!list2.Empty());
    REQUIRE(list2.Size() == 1);
}

int main() {
    return Catch::Session().run();
}