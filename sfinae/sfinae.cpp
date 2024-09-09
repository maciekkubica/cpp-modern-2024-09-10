#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std::literals;

template <typename T>
bool is_power_of_two(T value)
{
    return (value != 0) && ((value & (value - 1)) == 0);
}

TEST_CASE("SFINAE")
{
    CHECK(is_power_of_two(1));
    CHECK(is_power_of_two(2));
    CHECK_FALSE(is_power_of_two(3));
    CHECK(is_power_of_two(8));
    CHECK_FALSE(is_power_of_two(9));
    CHECK(is_power_of_two(64));
    CHECK_FALSE(is_power_of_two(65));

    // CHECK(is_power_of_two(8.0));
    // CHECK(is_power_of_two(64.0f));
}