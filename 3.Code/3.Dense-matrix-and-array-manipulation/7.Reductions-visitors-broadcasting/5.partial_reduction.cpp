#include <iostream>
#include <Eigen/Dense>

using namespace std;
int main()
{
    Eigen::MatrixXf mat(2, 4);
    mat << 1, 2, 6, 9,
        3, 1, 7, 2;


    // 代码索引 3-7-5-1
    std::cout << "3-7-5-1:" << std::endl;
    std::cout << "Column's maximum: " << std::endl
              << mat.colwise().maxCoeff() << std::endl;
    std::cout << std::endl;

    // 代码索引 3-7-5-2
    std::cout << "3-7-5-2:" << std::endl;
    std::cout << "Row's maximum: " << std::endl
              << mat.rowwise().maxCoeff() << std::endl;
    std::cout << std::endl;

    // 代码索引 3-7-5-3 Combining partial reductions with other operations
    std::cout << "3-7-5-3:" << std::endl;
    Eigen::Index maxIndex;
    float maxNorm = mat.colwise().sum().maxCoeff(&maxIndex);
    std::cout << "Maximum sum at position " << maxIndex << std::endl;
    std::cout << "The corresponding vector is: " << std::endl;
    std::cout << mat.col(maxIndex) << std::endl;
    std::cout << "And its sum is is: " << maxNorm << std::endl;
}