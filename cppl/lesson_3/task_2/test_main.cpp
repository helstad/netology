#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include "List.hpp"

TEST_CASE("List operations", "[List]") {
    SECTION("PushBack and PopBack") {
        List list;
        list.PushBack(1);
        REQUIRE(list.Size() == 1);
        list.PushBack(2);
        REQUIRE(list.Size() == 2);

        REQUIRE(list.PopBack() == 2);
        REQUIRE(list.Size() == 1);
        REQUIRE(list.PopBack() == 1);
        REQUIRE(list.Size() == 0);

        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    }

    SECTION("PushFront and PopFront") {
        List list;
        list.PushFront(1);
        REQUIRE(list.Size() == 1);
        list.PushFront(2);
        REQUIRE(list.Size() == 2);

        REQUIRE(list.PopFront() == 2);
        REQUIRE(list.Size() == 1);
        REQUIRE(list.PopFront() == 1);
        REQUIRE(list.Size() == 0);

        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    }

    SECTION("Scenario") {
        List list;
        list.PushBack(1);
        list.PushBack(2);
        list.PushFront(0);
        list.PushFront(-1);

        REQUIRE(list.Size() == 4);
        REQUIRE(list.PopBack() == 2);
        REQUIRE(list.PopFront() == -1);
        REQUIRE(list.Size() == 2);
    }
}

int main() {
    return Catch::Session().run();
}