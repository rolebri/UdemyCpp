#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t sum = 10;

    do
    {
        std::cout << "\nCurrent sum: " << sum << " Enter the next value: ";
        std::int32_t input;
        std::cin >> input;

        sum += input;
    } while (sum < 10);

    return 0;
}
