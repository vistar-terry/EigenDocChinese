#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    // 代码索引 3-11-2-1
    cout << "代码索引 3-11-2-1:" << endl;
    {
        Matrix2i a;
        a << 1, 2, 3, 4;
        cout << "Here is the matrix a:\n" << a << endl;
        
        a = a.transpose(); // !!! do NOT do this !!!
        cout << "and the result of the aliasing effect:\n" << a << endl;
    }

    // 代码索引 3-11-2-2
    cout << "\n代码索引 3-11-2-2:" << endl;
    {
        MatrixXf a(2,3); 
        a << 1, 2, 3, 4, 5, 6;
        cout << "Here is the initial matrix a:\n" << a << endl;

        a.transposeInPlace();
        cout << "and after being transposed:\n" << a << endl;
    }

    return 0;
}