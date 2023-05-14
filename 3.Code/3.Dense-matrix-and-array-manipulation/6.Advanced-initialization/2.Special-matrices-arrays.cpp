#include <iostream>
#include <Eigen/Core>

using namespace Eigen;

int main()
{
    // 代码索引 3-6-2-1
    std::cout << "代码索引 3-6-1-1:" << std::endl;
    {
        std::cout << "A fixed-size array:\n";
        Array33f a1 = Array33f::Zero();
        std::cout << a1 << "\n\n";
        
        
        std::cout << "A one-dimensional dynamic-size array:\n";
        ArrayXf a2 = ArrayXf::Zero(3);
        std::cout << a2 << "\n\n";
        
        
        std::cout << "A two-dimensional dynamic-size array:\n";
        ArrayXXf a3 = ArrayXXf::Zero(3, 4);
        std::cout << a3 << "\n";
    }

    // 代码索引 3-6-2-2
    std::cout << "\n代码索引 3-6-1-2:" << std::endl;
    {
        ArrayXXf table(10, 4);
        table.col(0) = ArrayXf::LinSpaced(10, 0, 90);
        table.col(1) = M_PI / 180 * table.col(0);
        table.col(2) = table.col(1).sin();
        table.col(3) = table.col(1).cos();
        std::cout << "   Degrees        Radians        Sine        Cosine\n";
        std::cout << table << std::endl;
    }

    // 代码索引 3-6-2-3
    std::cout << "\n代码索引 3-6-1-3:" << std::endl;
    {
        const int size = 6;
        MatrixXd mat1(size, size);
        mat1.topLeftCorner(size/2, size/2)     = MatrixXd::Zero(size/2, size/2);
        mat1.topRightCorner(size/2, size/2)    = MatrixXd::Identity(size/2, size/2);
        mat1.bottomLeftCorner(size/2, size/2)  = MatrixXd::Identity(size/2, size/2);
        mat1.bottomRightCorner(size/2, size/2) = MatrixXd::Zero(size/2, size/2);
        std::cout << mat1 << std::endl << std::endl;
        
        MatrixXd mat2(size, size);
        mat2.topLeftCorner(size/2, size/2).setZero();
        mat2.topRightCorner(size/2, size/2).setIdentity();
        mat2.bottomLeftCorner(size/2, size/2).setIdentity();
        mat2.bottomRightCorner(size/2, size/2).setZero();
        std::cout << mat2 << std::endl << std::endl;
        
        MatrixXd mat3(size, size);
        mat3 << MatrixXd::Zero(size/2, size/2), MatrixXd::Identity(size/2, size/2),
                MatrixXd::Identity(size/2, size/2), MatrixXd::Zero(size/2, size/2);
        std::cout << mat3 << std::endl;
    }

    return 0;
}