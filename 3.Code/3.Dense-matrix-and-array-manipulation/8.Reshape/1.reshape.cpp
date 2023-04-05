#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
     Matrix4i m = Matrix4i::Random();

     // 代码索引 3-8-1-1
     // 2D reshape
     cout << "2D reshape:" << endl;
     cout << "Here is the matrix m:" << endl
          << m << endl;
     cout << "Here is m.reshaped(2, 8):" << endl
          << m.reshaped(2, 8) << endl;
     cout << endl;

     // 代码索引 3-8-1-2
     // 1D reshape
     cout << "1D reshape:" << endl;
     cout << "Here is the matrix m:" << endl
          << m << endl;
     cout << "Here is m.reshaped().transpose():" << endl
          << m.reshaped().transpose() << endl;
     cout << "Here is m.reshaped<RowMajor>().transpose():  " << endl
          << m.reshaped<RowMajor>().transpose() << endl;

     return 0;
}