#include <iostream>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

int main()
{
    MatrixXi A = MatrixXi::Random(7, 6);
    cout << "Initial matrix A:\n"
         << A << "\n\n";

    // 包含从第i行到最后一行，从第0列开始，共n列的块(i: 2, n: 3)
    cout << "A(seq(i,Eigen::last), seqN(0,n)): (i: 2, n: 3)\n"
         << A(seq(2, Eigen::last), seqN(0, 3)) << "\n\n";

    // 包含从第i行到第m行，从第j列开始，共n列的块(i: 1, m: 2, j: 2, n: 4)
    cout << "A(seq(i,m), seqN(j,n)): (i: 1, m: 2, j: 2, n: 4)\n"
         << A(seqN(1, 2), seqN(2, 4)) << "\n\n";

    // 包含从第i0行到第i1行，从第j0列到第j1列的块(i0: 1, i1: 2, j0: 2, j1: 4)
    cout << "A(seq(i0,i1), seq(j0,j1)): (i0: 1, i1: 2, j0: 2, j1: 4)\n"
         << A(seq(1, 2), seq(2, 4)) << "\n\n";

    // A的偶数列
    cout << "A的偶数列: \n"
         << A(Eigen::all, seq(0, Eigen::last, 2)) << "\n\n";

    // A的前n个奇数行 (n: 3)
    cout << "A的前n个奇数行: (n: 3)\n"
         << A(seqN(1, 3, 2), Eigen::all) << "\n\n";

    // A的倒数第二列
    cout << "A的倒数第二列: \n"
         << A(Eigen::all, Eigen::last-1) << "\n\n";

    // A的中间一行
    cout << "A的中间一行: \n"
         << A(Eigen::last/2, Eigen::all) << "\n\n";


    Eigen::VectorXi v{{4,2,5,8,3}};
    cout << "Initial vector v:\n"
         << v << "\n\n";

    // 向量v从第i个元素到最后一个元素 (i: 2)
    cout << "向量v从第i个元素到最后一个元素: (i: 2)\n"
         << v(seq(2, Eigen::last)) << "\n\n";

    // 向量v最后n个元素
    cout << "向量v最后n个元素: (n: 3)\n"
         << v(seq(Eigen::last-3+1, Eigen::last)) << "\n\n";

    // Eigen提供最后几个元素的提取函数
    cout << "\n\nEigen提供最后几个元素的提取函数:" << "\n\n";
    // 向量v最后n个元素
    cout << "向量v最后n个元素: (n: 3)\n"
         << v(Eigen::lastN(3)) << "\n\n";

    // A右下角m行n列的块
    cout << "A右下角m行n列的块: (m: 3, n: 2)\n"
         << A(Eigen::lastN(3), Eigen::lastN(2)) << "\n\n";

    // A的最后n列，步长为m
    cout << "A的最后n列, 步长为m: (n: 3, m: 2)\n"
         << A(Eigen::all, Eigen::lastN(3, 2)) << "\n\n";

}