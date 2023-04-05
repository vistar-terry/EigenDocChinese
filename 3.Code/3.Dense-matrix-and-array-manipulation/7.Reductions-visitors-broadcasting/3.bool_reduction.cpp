// 代码索引 3-7-3-1
#include <Eigen/Dense>
#include <iostream>

int main()
{
    Eigen::ArrayXXf a(2, 2);
    Eigen::ArrayXXf b(2, 2);

    a << 1, 2,
         3, 4;

    std::cout << "b = " << (a > 0) << std::endl;
    std::cout << "(a > 0).all()   = " << (a > 0).all() << std::endl;
    std::cout << "(a > 0).any()   = " << (a > 0).any() << std::endl;
    std::cout << "(a > 0).count() = " << (a > 0).count() << std::endl;
    std::cout << std::endl;
    std::cout << "(a > 2).all()   = " << (a > 2).all() << std::endl;
    std::cout << "(a > 2).any()   = " << (a > 2).any() << std::endl;
    std::cout << "(a > 2).count() = " << (a > 2).count() << std::endl;
}