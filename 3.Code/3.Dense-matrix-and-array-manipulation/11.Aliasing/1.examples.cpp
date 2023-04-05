#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    MatrixXi mat(3, 3);
    mat << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    cout << "Here is the matrix mat:\n" << mat << endl;

    cout << "mat.bottomRightCorner(2,2):\n" << mat.bottomRightCorner(2,2) << endl;
    cout << "mat.topLeftCorner(2,2):\n" << mat.topLeftCorner(2,2) << endl;

    // 代码索引 3-11-1-1
    // This assignment shows the aliasing problem
    mat.bottomRightCorner(2, 2) = mat.topLeftCorner(2, 2);
    cout << "After the assignment(Bug), mat = \n" << mat << endl;

    // 代码索引 3-11-1-2
    // The eval() solves the aliasing problem
    mat.bottomRightCorner(2,2) = mat.topLeftCorner(2,2).eval();
    cout << "After the assignment(Fixed), mat = \n" << mat << endl;

    return 0;
}