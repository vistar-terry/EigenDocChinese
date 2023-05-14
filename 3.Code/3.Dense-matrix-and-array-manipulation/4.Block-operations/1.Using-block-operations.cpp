#include <Eigen/Dense>
#include <iostream>
 
using namespace std;
 
int main()
{
    // 代码索引 3-4-1-1
    cout << "代码索引 3-4-1-1:" << endl;
    {
        Eigen::MatrixXf m(4,4);
        m <<  1, 2, 3, 4,
            5, 6, 7, 8,
            9,10,11,12,
            13,14,15,16;
        cout << "Block in the middle" << endl;
        cout << m.block<2,2>(1,1) << endl << endl;
        for (int i = 1; i <= 3; ++i)
        {
            cout << "Block of size " << i << "x" << i << endl;
            cout << m.block(0,0,i,i) << endl << endl;
        }
    }

    // 代码索引 3-4-1-2
    cout << "\n代码索引 3-4-1-2:" << endl;
    {
        Eigen::Array22f m;
        m << 1,2,
             3,4;
        Eigen::Array44f a = Eigen::Array44f::Constant(0.6);
        std::cout << "Here is the array a:\n" << a << "\n\n";
        a.block<2,2>(1,1) = m;
        std::cout << "Here is now a with m copied into its central 2x2 block:\n" << a << "\n\n";
        a.block(0,0,2,3) = a.block(2,1,2,3);
        std::cout << "Here is now a with bottom-right 2x3 block copied into top-left 2x3 block:\n" << a << "\n\n";
    }
}