#include <iostream>

// ReturnType FunctionsName(ParameterList - optional)
// {
//    // FunctionCode
// }

int user_input()
{
    std::int32_t number = 0;
    std::cout << "Please enter a number: ";
    std::cin >> number;

    return number;
}

int main()
{
    int my_number = user_input();
    std::cout << my_number << std::endl;

    return 0;
}
