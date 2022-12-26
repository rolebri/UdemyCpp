#include <iostream>

void copy(int v) // copy - Input but modifiable
{
    v *= 2;
    std::cout << "f1: " << v << std::endl;
    std::cout << &v << std::endl;
}

void copy_const(const int v) // const - Input only because of const
{
    std::cout << "f1: " << v << std::endl;
    std::cout << &v << std::endl;
}

void reference_input(const int &v) // Input only because of const
{
    std::cout << "f3: " << v << std::endl;
    std::cout << &v << std::endl;
}

void reference_in_output(int &v) // Input and Output
{
    v = v * 2; // In and Output
    v = 2;     // Output only
    std::cout << "f3: " << v << std::endl;
    std::cout << &v << std::endl;
}

int main()
{
    int a = 2;
    std::cout << a << std::endl;
    std::cout << &a << std::endl;

    copy(a);
    copy_const(a);
    reference_input(a);
    reference_in_output(a);

    std::cout << a << std::endl;
    std::cout << &a << std::endl;

    return 0;
}
