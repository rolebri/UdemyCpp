#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    auto numbers = std::vector<std::int32_t>{1, 2, 3, 4, 5, 6};

    for (auto v : numbers)
        std::cout << v << " ";
    std::cout << std::endl;

    auto results1 = numbers |
                    std::views::transform([](const auto n) { return n * 3; }) |
                    std::views::filter([](const auto n) { return n % 2 == 0; });

    for (auto v : results1)
        std::cout << v << " ";
    std::cout << std::endl;

    auto results2 = std::views::reverse(numbers) | std::views::drop(2) |
                    std::views::take(3) |
                    std::views::transform([](const auto n) { return n * 2; }) |
                    std::views::filter([](const auto n) { return n % 2 == 0; });

    for (auto v : results2)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}
