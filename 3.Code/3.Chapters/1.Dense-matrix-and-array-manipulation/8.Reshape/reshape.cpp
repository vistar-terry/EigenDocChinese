#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    // 2D reshape
    Matrix4i m = Matrix4i::Random();
    cout << "Here is the matrix m:" << endl
         << m << endl;
    cout << "Here is m.reshaped(2, 8):" << endl
         << m.reshaped(2, 8) << endl;

    cout << endl;
    // 1D reshape
    cout << "Here is the matrix m:" << endl
         << m << endl;
    cout << "Here is m.reshaped().transpose():" << endl
         << m.reshaped().transpose() << endl;
    cout << "Here is m.reshaped<RowMajor>().transpose():  " << endl
         << m.reshaped<RowMajor>().transpose() << endl;
}