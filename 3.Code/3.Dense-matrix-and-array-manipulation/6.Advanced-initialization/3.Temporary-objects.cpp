#include <iostream>
#include <Eigen/Dense>
 
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::MatrixXf;
 
int main()
{
    // 代码索引 3-6-3-1
    std::cout << "代码索引 3-6-3-1:" << std::endl;
    {
        MatrixXd m = MatrixXd::Random(3,3);
        m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
        std::cout << "m =" << std::endl << m << std::endl;
        VectorXd v(3);
        v << 1, 2, 3;
        std::cout << "m * v =" << std::endl << m * v << std::endl;
    }

    // 代码索引 3-6-3-2
    std::cout << "\n代码索引 3-6-3-2:" << std::endl;
    {
        MatrixXf mat = MatrixXf::Random(2, 3);
        std::cout << mat << std::endl << std::endl;
        mat = (MatrixXf(2,2) << 0, 1, 1, 0).finished() * mat;
        std::cout << mat << std::endl;
    }
}