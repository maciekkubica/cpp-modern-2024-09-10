#include <catch2/catch_test_macros.hpp>
#include <vector>

template <typename T>
auto multiply(T a, T b) -> decltype(a * b)
{
    return a * b;
}

TEST_CASE("functions with auto")
{
    auto result = multiply(2, 3);
}

//////////////////////////////////////////////////////////////////////////////////////

template <typename TContainer>
auto get_nth_element(TContainer& container, size_t index) 
{
    return container[index];
}

TEST_CASE("functions with decltype(auto)")
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto&& element = get_nth_element(v, 2);
    REQUIRE(element == 3);

    element = 10;
    // REQUIRE(v[2] == 10);
}