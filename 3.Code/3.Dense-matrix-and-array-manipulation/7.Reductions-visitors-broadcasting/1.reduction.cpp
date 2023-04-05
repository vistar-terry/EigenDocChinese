#include <iostream>
#include <Eigen/Dense>

using namespace std;
int main()
{
    // 代码索引 3-7-1-1
    Eigen::Matrix2d mat;
    mat << 1, 2,
           3, 4;
    cout << "Here is mat.sum():       " << mat.sum() << endl;
    cout << "Here is mat.prod():      " << mat.prod() << endl;
    cout << "Here is mat.mean():      " << mat.mean() << endl;
    cout << "Here is mat.minCoeff():  " << mat.minCoeff() << endl;
    cout << "Here is mat.maxCoeff():  " << mat.maxCoeff() << endl;
    cout << "Here is mat.trace():     " << mat.trace() << endl;
}
