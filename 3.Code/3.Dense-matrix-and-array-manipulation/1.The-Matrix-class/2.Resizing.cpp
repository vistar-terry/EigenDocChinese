#include <iostream>
#include <Eigen/Dense>

int main()
{
    // 代码索引 3-1-2-1
    std::cout << "3-1-2-1:" << std::endl << std::endl;
    {
        Eigen::MatrixXd m(2, 5);
        m.resize(4, 3);
        std::cout << "The matrix m is of size "
                  << m.rows() << "x" << m.cols() << std::endl;
        std::cout << "It has " << m.size() << " coefficients" << std::endl;

        Eigen::VectorXd v(2);
        v.resize(5);
        std::cout << "The vector v is of size " << v.size() << std::endl;
        std::cout << "As a matrix, v is of size "
                  << v.rows() << "x" << v.cols() << std::endl;
    }
    std::cout << std::endl;

    // 代码索引 3-1-2-2
    std::cout << "3-1-2-2:" << std::endl << std::endl;
    {
        Eigen::MatrixXd m{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        std::cout << "Before resize, the matrix m is: \n" << m << std::endl;
        m.resize(3, 4);
        std::cout << "After resize, the matrix m is: \n" << m << std::endl;

        Eigen::MatrixXd n{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        std::cout << "Before conservativeResize, the matrix n is: \n" << n << std::endl;
        n.conservativeResize(5, 3);
        std::cout << "After conservativeResize, the matrix n is: \n" << n << std::endl;
    }

    return 0;
}