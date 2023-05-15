#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    // 代码索引 3-11-4-1
    cout << "代码索引 3-11-4-1:" << endl;
    {
        MatrixXf matA(2, 2);
        matA << 2, 0, 
                0, 2;
        matA = matA * matA;
        cout << matA << endl;
    }

    // 代码索引 3-11-4-2
    cout << "\n代码索引 3-11-4-2:" << endl;
    {
        MatrixXf matA(2,2), matB(2,2); 
        matA << 2, 0,
                0, 2;
        
        // Simple but not quite as efficient
        matB = matA * matA;
        cout << matB << endl << endl;
        
        // More complicated but also more efficient
        matB.noalias() = matA * matA;
        cout << matB << endl;
    }

    // 代码索引 3-11-4-3
    cout << "\n代码索引 3-11-4-3:" << endl;
    {
        MatrixXf A(2,2), B(3,2);
        B << 2, 0,
             0, 3,
             1, 1;
        A << 2, 0,
             0, -2;
        A = (B * A).cwiseAbs();
        cout << A << endl;
    }

    // 代码索引 3-11-4-4
    cout << "\n代码索引 3-11-4-4:" << endl;
    {
        MatrixXf A(2, 2), B(3, 2);
        B << 2, 0,
             0, 3,
             1, 1;
        A << 2, 0,
             0, -2;
        A = (B * A).eval().cwiseAbs();
        cout << A << endl;
    }

    return 0;
}