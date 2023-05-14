#include <iostream>
#include <vector>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

int main()
{
    // 代码索引 3-5-2-1
    cout << "代码索引 3-5-2-1" << endl;
    {
        std::vector<int> ind{4, 2, 5, 5, 3};
        MatrixXi A = MatrixXi::Random(4, 6);
        cout << "Initial matrix A:\n" << A << "\n\n";

        // 输入的也可以是ArrayXi, std::vector<int>, std::array<int,N>等
        // 建议使用Eigen::all替换Eigen::placeholders::all，下同
        cout << "A(all,ind):\n" << A(Eigen::all, ind) << "\n\n";
    }

    // 代码索引 3-5-2-2
    cout << "代码索引 3-5-2-2" << endl;
    {
        MatrixXi A = MatrixXi::Random(4,6);
        cout << "Initial matrix A:\n" << A << "\n\n";

        // 也可以直接传递一个静态数组
        cout << "A(all,{4,2,5,5,3}):\n" << A(Eigen::all,{4,2,5,5,3}) << "\n\n";
    }

    // 代码索引 3-5-2-3
    cout << "代码索引 3-5-2-3" << endl;
    {
        ArrayXi ind(5);
        ind << 4, 2, 5, 5, 3;
        MatrixXi A = MatrixXi::Random(4,6);
        cout << "Initial matrix A:\n" << A << "\n\n";

        // 也可以传递一个表达式
        cout << "A(all,ind-1):\n" << A(Eigen::all,ind-1) << "\n\n";
    }

    return 0;
}
