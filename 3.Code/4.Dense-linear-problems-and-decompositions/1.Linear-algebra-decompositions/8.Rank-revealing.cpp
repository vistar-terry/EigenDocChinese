#include <iostream>
#include <Eigen/Dense>
 
int main()
{
    // 代码索引 4-1-8-1
    std::cout << "代码索引 4-1-8-1:" << std::endl;
    {
        Eigen::Matrix3f A;
        A << 1, 2, 5,
             2, 1, 4,
             3, 0, 3;
        std::cout << "Here is the matrix A:\n" << A << std::endl;
        Eigen::FullPivLU<Eigen::Matrix3f> lu_decomp(A);
        std::cout << "The rank of A is " << lu_decomp.rank() << std::endl;
        std::cout << "Here is a matrix whose columns form a basis of the null-space of A:\n"
                << lu_decomp.kernel() << std::endl;
        std::cout << "Here is a matrix whose columns form a basis of the column-space of A:\n"
                << lu_decomp.image(A) << std::endl; // yes, have to pass the original A
    }

    // 代码索引 4-1-8-2
    std::cout << "\n代码索引 4-1-8-2:" << std::endl;
    {
        Eigen::Matrix2d A;
        A << 2, 1,
                2, 0.9999999999;
        Eigen::FullPivLU<Eigen::Matrix2d> lu(A);
        std::cout << "By default, the rank of A is found to be " << lu.rank() << std::endl;
        lu.setThreshold(1e-5);
        std::cout << "With threshold 1e-5, the rank of A is found to be " << lu.rank() << std::endl;
    }
}