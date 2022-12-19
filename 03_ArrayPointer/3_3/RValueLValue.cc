#include <iostream>

void f(int v)
{
    std::cout << v << std::endl;
}

int main()
{
    int a = 2;  // lvalue
    const int b = 2; // const lvalue
    int &c = a; // lvalue reference
    const int &d = b; // const lvalue reference

    f(a);
    f(b);
    f(c);
    f(d);
    f(2); // rvalue

    return 0;
}
