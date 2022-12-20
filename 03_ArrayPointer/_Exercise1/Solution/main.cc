#include <cstdint>
#include <iostream>

#include "exercise.h"

int main()
{
    // Exercise 1
    auto array_length = std::size_t{100};
    auto sum = 0.0;

    auto *array1 = new double[array_length];

    for (std::size_t i = 0; i < array_length; i++)
    {
        array1[i] = i;
    }

    sum = array_sum(array1, array_length);
    std::cout << "(Exercise 1) Array Sum = " << sum << std::endl;
    delete[] array1;
    array1 = nullptr;

    // Exercise 2
    auto input_array_length = std::size_t{0};
    auto input_array_value = std::int32_t{0};

    std::cout << std::endl << "Enter the array length: " << std::endl;
    std::cin >> input_array_length;
    std::cout << std::endl << "Enter the array value: " << std::endl;
    std::cin >> input_array_value;
    std::cout << std::endl;

    auto *array2 = array_constructor(input_array_value, input_array_length);

    for (std::size_t i = 0; i < input_array_length; i++)
    {
        std::cout << array2[i] << std::endl;
    }

    delete[] array2;
    array2 = nullptr;

    return 0;
}
