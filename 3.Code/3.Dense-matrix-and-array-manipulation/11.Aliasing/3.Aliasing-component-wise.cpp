// 代码索引 3-11-3-1
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    MatrixXf mat(2,2); 
    mat << 1, 2,  4, 7;
    cout << "Here is the matrix mat:\n" << mat << endl << endl;
    
    mat = 2 * mat;
    cout << "After 'mat = 2 * mat', mat = \n" << mat << endl << endl;
    
    
    mat = mat - MatrixXf::Identity(2,2);
    cout << "After the subtraction, it becomes\n" << mat << endl << endl;
    
    
    ArrayXXf arr = mat;
    arr = arr.square();
    cout << "After squaring, it becomes\n" << arr << endl << endl;
    
    // Combining all operations in one statement:
    mat << 1, 2,  4, 7;
    mat = (2 * mat - MatrixXf::Identity(2,2)).array().square();
    cout << "Doing everything at once yields\n" << mat << endl << endl;

    return 0;
}