#include <iostream>
#include <Eigen/Dense>

int main()
{
    // 代码索引 3-2-3-1
    std::cout << "代码索引 3-2-3-1" << std::endl;
    {
        Eigen::MatrixXcf a = Eigen::MatrixXcf::Random(2,2);
        std::cout << "Here is the matrix a\n" << a << std::endl;
        std::cout << "Here is the matrix a^T\n" << a.transpose() << std::endl;
        std::cout << "Here is the conjugate of a\n" << a.conjugate() << std::endl;
        std::cout << "Here is the matrix a^*\n" << a.adjoint() << std::endl;
    }

    // 代码索引 3-2-3-3
    std::cout << "\n代码索引 3-2-3-3" << std::endl;
    {
        Eigen::MatrixXf a(2,3); a << 1, 2, 3, 4, 5, 6;
        std::cout << "Here is the initial matrix a:\n" << a << std::endl;

        a.transposeInPlace();
        std::cout << "and after being transposed:\n" << a << std::endl;
    }

    // 代码索引 3-2-3-2
    std::cout << "\n代码索引 3-2-3-2" << std::endl;
    {
        Eigen::Matrix2i a; a << 1, 2, 3, 4;
        std::cout << "Here is the matrix a:\n" << a << std::endl;
        
        a = a.transpose(); // !!! do NOT do this !!!
        std::cout << "and the result of the aliasing effect:\n" << a << std::endl;
    }

}