#include <iostream>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

int main()
{
    // 代码索引 3-6-1-1
    cout << "代码索引 3-6-1-1:" << endl;
    {
        Matrix3f m;
        m << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;
        std::cout << m << endl;
    }

    // 代码索引 3-6-1-2
    cout << "\n代码索引 3-6-1-2:" << endl;
    {
        RowVectorXd vec1(3);
        vec1 << 1, 2, 3;
        std::cout << "vec1 = " << vec1 << std::endl;
        
        RowVectorXd vec2(4);
        vec2 << 1, 4, 9, 16;
        std::cout << "vec2 = " << vec2 << std::endl;
        
        RowVectorXd joined(7);
        joined << vec1, vec2;
        std::cout << "joined = " << joined << std::endl;
    }

    // 代码索引 3-6-1-3
    cout << "\n代码索引 3-6-1-3:" << endl;
    {
        MatrixXf matA(2, 2);
        matA << 1, 2, 3, 4;
        MatrixXf matB(4, 4);
        matB << matA, matA/10, matA/10, matA;
        std::cout << matB << std::endl;
    }

    // 代码索引 3-6-1-4
    cout << "\n代码索引 3-6-1-4:" << endl;
    {
        Matrix3f m;
        m.row(0) << 1, 2, 3;
        m.block(1,0,2,2) << 4, 5, 7, 8;
        m.col(2).tail(2) << 6, 9;
        std::cout << m << endl;
    }
}