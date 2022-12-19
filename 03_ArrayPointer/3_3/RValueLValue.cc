#include <iostream>

void f(int v)
{
    std::cout << v << std::endl;
}

int main()
{
    int a = 2;
    const int b = 2;
    int &c = a;
    const int &d = b;

    f(a);
    f(b);
    f(c);
    f(d);

    return 0;
}
