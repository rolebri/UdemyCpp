#include <cstdint>
#include <iostream>

int main()
{
    const char last_name[] = "Schaffranek";
    std::cout << last_name << std::endl;

    const std::int32_t values[]{1, 2, 3};
    std::cout << values << std::endl;

    for (std::size_t i = 0; i < 4; i++)
    {
        std::cout << values[i] << std::endl;
    }

    return 0;
}
