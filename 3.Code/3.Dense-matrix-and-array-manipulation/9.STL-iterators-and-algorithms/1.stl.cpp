#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
     // 3-9-1-1 use range-for-loop
     cout << "3-9-1-1 use range-for-loop:" << endl;
     {
          VectorXi v = VectorXi::Random(4);
          cout << "Here is the vector v:\n";
          for (auto x : v)
               cout << x << " ";
          cout << "\n";
     }
     cout << endl;

     // 3-9-1-2 use STL algorithms
     cout << "3-9-1-2 use STL algorithms:" << endl;
     {
          Array4i v = Array4i::Random().abs();
          cout << "Here is the initial vector v:\n"
               << v.transpose() << "\n";
          std::sort(v.begin(), v.end());
          cout << "Here is the sorted vector v:\n"
               << v.transpose() << "\n";
     }
     cout << endl;

     // 3-9-1-3 Iterating over coefficients of 2D arrays and matrices
     cout << "3-9-1-3 Iterating over coefficients of 2D arrays and matrices:" << endl;
     {
          Matrix2i A = Matrix2i::Random();
          cout << "Here are the coeffs of the 2x2 matrix A:\n";
          for (auto x : A.reshaped())
               cout << x << " ";
          cout << "\n";
     }
     cout << endl;

     // 3-9-1-4 Iterating over rows or columns of 2D arrays and matrices
     cout << "3-9-1-4 Iterating over rows or columns of 2D arrays and matrices:" << endl;
     {
          ArrayXXi A = ArrayXXi::Random(4, 4).abs();
          cout << "Here is the initial matrix A:\n"
               << A << "\n";
          for (auto row : A.rowwise())
               std::sort(row.begin(), row.end());
          cout << "Here is the sorted matrix A:\n"
               << A << "\n";
     }

     return 0;
}