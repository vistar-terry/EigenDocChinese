// 代码索引 3-1-1-1
#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << "Here is the matrix m:\n" << m << std::endl;

    Eigen::Matrix3f n;
    n << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;
    std::cout << "Here is the matrix n:\n" << n << std::endl;

    Eigen::VectorXd v(2);
    v(0) = 4;
    v(1) = v(0) - 1;
    std::cout << "Here is the vector v:\n" << v << std::endl;

    return 0;
}