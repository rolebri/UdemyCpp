#include <iostream>

void f1(int v)
{
    std::cout << "f1: " << v << std::endl;
    std::cout << &v << std::endl;
}

void f2(int *const v)
{
    std::cout << "f2: " << *v << std::endl;
    std::cout << v << std::endl;
}

void f3(int &v)
{
    std::cout << "f3: " << v << std::endl;
    std::cout << &v << std::endl;
}

int main()
{
    int a = 2;
    std::cout << &a << std::endl;

    f1(a);
    f2(&a);
    f3(a);

    return 0;
}
