#include <iostream>
#include <Eigen/Dense>
 
using namespace std;
int main()
{
    // 代码索引 3-2-6-1
    cout << "代码索引 3-2-6-1" << endl;
    {
        Eigen::Matrix2d mat;
        mat << 1, 2,
            3, 4;
        cout << "Here is mat.sum():       " << mat.sum()       << endl;
        cout << "Here is mat.prod():      " << mat.prod()      << endl;
        cout << "Here is mat.mean():      " << mat.mean()      << endl;
        cout << "Here is mat.minCoeff():  " << mat.minCoeff()  << endl;
        cout << "Here is mat.maxCoeff():  " << mat.maxCoeff()  << endl;
        cout << "Here is mat.trace():     " << mat.trace()     << endl;
    }

    // 代码索引 3-2-6-2
    cout << "\n代码索引 3-2-6-2" << endl;
    {
        Eigen::Matrix3f m = Eigen::Matrix3f::Random();
        std::ptrdiff_t i, j;
        float minOfM = m.minCoeff(&i,&j);
        cout << "Here is the matrix m:\n" << m << endl;
        cout << "Its minimum coefficient (" << minOfM 
             << ") is at position (" << i << "," << j << ")\n\n";

        Eigen::RowVector4i v = Eigen::RowVector4i::Random();
        int maxOfV = v.maxCoeff(&i);
        cout << "Here is the vector v: " << v << endl;
        cout << "Its maximum coefficient (" << maxOfV 
             << ") is at position " << i << endl;
    }
}