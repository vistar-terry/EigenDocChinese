#include <iostream>
#include <Eigen/Dense>

using namespace std;
int main()
{
    Eigen::MatrixXf mat(2, 4);
    Eigen::VectorXf v(2);

    mat << 1, 2, 6, 9,
        3, 1, 7, 2;

    v << 0,
         1;

    // 代码索引 3-7-6-1
    // add v to each column of m
    mat.colwise() += v;
    
    std::cout << "3-7-6-1 column Broadcasting result: " << std::endl;
    std::cout << mat << std::endl;

    v << 0, 1, 2, 3;

    // 代码索引 3-7-6-2
    // add v to each row of m
    mat.rowwise() += v.transpose();

    std::cout << "3-7-6-2 row Broadcasting result: " << std::endl;
    std::cout << mat << std::endl;
}