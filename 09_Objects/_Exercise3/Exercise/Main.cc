#include <iostream>

#include "Matrix.h"

int main()
{
    auto m1 = Matrix<double>(1.0, 2.0, 3.0, 4.0);
    std::cout << "M1: " << &m1 << std::endl;
    m1.print_matrix();

    // Copy Constructor
    auto m2 = Matrix<double>(m1);
    std::cout << "M2 (copy from M1): " << &m2 << std::endl;
    m2.print_matrix();

    // Copy Assignment
    auto m3 = Matrix<double>{};
    m3 = m1;
    std::cout << "M3 (copy from M1): " << &m3 << std::endl;
    m3.print_matrix();

    return 0;
}
