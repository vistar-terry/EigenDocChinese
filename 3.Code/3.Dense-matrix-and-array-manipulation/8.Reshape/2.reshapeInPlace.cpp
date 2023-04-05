#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
     // 代码索引 3-8-2-1
     std::cout << "3-8-2-1:" << std::endl;
     {
          MatrixXi m = Matrix4i::Random();
          cout << "Here is the matrix m:" << endl << m << endl;
          cout << "Here is m.reshaped(2, 8):" << endl << m.reshaped(2, 8) << endl;
          m.resize(2,8);
          cout << "Here is the matrix m after m.resize(2,8):" << endl << m << endl;
     }
     std::cout << std::endl;

     // 代码索引 3-8-2-2
     std::cout << "3-8-2-2:" << std::endl;
     {
          Matrix<int, Dynamic, Dynamic, RowMajor> m = Matrix4i::Random();
          cout << "Here is the matrix m:" << endl << m << endl;
          cout << "Here is m.reshaped(2, 8):" << endl << m.reshaped(2, 8) << endl;
          cout << "Here is m.reshaped<AutoOrder>(2, 8):" << endl << m.reshaped<AutoOrder>(2, 8) << endl;
          m.resize(2, 8);
          cout << "Here is the matrix m after m.resize(2,8):" << endl << m << endl;
     }

     return 0;
}