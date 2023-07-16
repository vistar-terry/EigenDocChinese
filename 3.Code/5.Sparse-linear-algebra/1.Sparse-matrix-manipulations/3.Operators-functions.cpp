// 代码索引 5-1-2-3
#include <Eigen/Sparse>
#include <Eigen/Dense>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // 构建稀疏矩阵
    Eigen::Matrix3d A;
    A << 1, 0, 1,
         0, 2, 0,
         0, 1, 3;
    //  SparseMatrix存储稀疏矩阵 sm1
    int rows = A.rows();
    int cols = A.cols();
    Eigen::SparseMatrix<double> sm1(rows, cols);
    // sm1.reserve(Eigen::VectorXi::Constant(cols, 6));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            double v_ij = A(i, j);
            if (v_ij != 0)
            {
                sm1.insert(i, j) = v_ij;
            }
        }
    }
    sm1.makeCompressed();

    // Eigen::SparseMatrix<double> sm1(rows, cols);
    // sm1.insert(0, 0) = 1;
    // sm1.insert(1, 1) = 2;
    // sm1.insert(2, 2) = 3;
    // sm1.makeCompressed();
    // 构建稠密矩阵 dm1
    Eigen::MatrixXd dm1 = Eigen::MatrixXd::Random(rows, cols);

    // 构建稀疏向量
    Eigen::VectorXd v{{2, 0, 0, 2, 4, 0, 0, 8, 6}};
    // SparseVector存储稀疏向量 sv1
    int size = v.size();
    Eigen::SparseVector<double> sv1(size);
    for (int i = 0; i < size; ++i)
    {
        double v_ij = v(i);
        if (v_ij != 0)
        {
            sv1.insert(i) = v_ij;
        }
    }
    // 构建稠密向量 dv1
    Eigen::VectorXd dv1 = Eigen::VectorXd::Random(size);

    // 构建复数矩阵 smc
    Eigen::MatrixXcf smc(rows, cols);
    smc << std::complex<float>(1,2), std::complex<float>(-3,1), 0,
           0, 0, std::complex<float>(2,1),
           0, std::complex<float>(4,2), 0;

    // real() 返回复数矩阵的实部。如果矩阵元素是实数，则返回值等于原始矩阵
    // 如果矩阵元素是复数，则返回值是一个新的实数矩阵，其中包含原始矩阵的实部
    cout << "The real part of smc is:\n" << smc.real() << endl;

    // imag() 返回复数矩阵的虚部。如果矩阵元素是实数，则返回值为0
    // 如果矩阵元素是复数，则返回值是一个新的实数矩阵，其中包含原始矩阵的虚部
    cout << "The imaginary part of smc is:\n" << smc.imag() << endl;

    // cwiseProduct() 用于对两个矩阵进行逐元素相乘（也称为Hadamard乘积）,生成一个新的矩阵
    cout << "The sparse matrix sm1 is:\n" << sm1.toDense() << endl;
    cout << "The dense matrix dm1 is:\n" << dm1 << endl;
    Eigen::SparseMatrix<double> m = sm1.cwiseProduct(dm1);
    cout << "The sm1.cwiseProduct(dm1) is:\n" << m.toDense() << endl;

    // transpose() 用于计算矩阵的转置
    Eigen::SparseMatrix<double> smt = sm1.transpose();
    cout << "The transpose of sm1 is:\n" << smt << endl;

    // 计算稀疏矩阵的行列式
    // 利用LU分解，QR分解等
    // Eigen::SparseLU<Eigen::SparseMatrix<double>> solver(sm1); // LU分解
    // double det = solver.determinant();
    // cout << det << endl;
    // 转为稠密矩阵再求行列式
    cout << "The determinant of smt is: " << smt.toDense().determinant() << endl;

    // inverse() 用于计算矩阵的逆矩阵
    Eigen::Matrix3d smi = sm1.toDense().inverse();
    cout << "The inverse of sm1 is:\n" << smi << endl;

    // adjoint() 用于计算矩阵的伴随矩阵
    // 对于一个复矩阵A，其伴随矩阵为A的共轭转置矩阵的转置
    // 对于实矩阵A，其伴随矩阵等于其转置矩阵的行列式乘以其逆矩阵
    cout << "The adjoint of sm1 in math is:\n" << smt.toDense().determinant()*smi << endl;
    // 这里按照数学定义的计算结果和使用adjoint函数计算的结果不一样
    // 如果你知道原因请在博客留言
    // https://blog.csdn.net/maizousidemao/article/details/131340191?spm=1001.2014.3001.5501
    cout << "The adjoint of sm1 in Eigen is:\n" << sm1.adjoint() << endl;

    // selfadjointView函数用于创建一个对称矩阵视图，通过Eigen::Upper和Eigen::Lower枚举类型，可以选择返回上三角矩阵或下三角矩阵
    Eigen::SparseMatrix<double> sm1Upper = sm1.selfadjointView<Eigen::Upper>();
    Eigen::SparseMatrix<double> sm1Lower = sm1.selfadjointView<Eigen::Lower>();
    cout << "The upper of sm1 is:\n" << sm1Upper.toDense() << endl;
    cout << "The lower of sm1 is:\n" << sm1Lower.toDense() << endl;

    // pruned() 删除绝对值等于0的系数
    // pruned(ref) 删除绝对值小于等于ref的系数
    // 经测试以上两种用法没有生效，如果你知道原因请在博客留言：
    // https://blog.csdn.net/maizousidemao/article/details/131340191?spm=1001.2014.3001.5501
    // pruned(ref,epsilon) 删除绝对值小于等于ref*epsilon的系数
    cout << "sm1Upper*sm1Lower is:\n" << sm1Upper*sm1Lower << endl;
    cout << "sm1Upper*sm1Lower is:\n" << (sm1Upper*sm1Lower).pruned(2,1) << endl;

    // 构建一个置换矩阵
    Eigen::PermutationMatrix<3> perm;
    perm.indices() << 2, 1, 0;
    // 使用置换矩阵对矩阵sm1进行行重排，交换第1行和第3行
    cout << "The raw Permutation of sm1 is:\n" << perm*sm1 << endl;
    // 使用置换矩阵对矩阵sm1进行列重排，交换第1列和第3列
    cout << "The col Permutation of sm1 is:\n" << sm1*perm << endl;


    return 0;
}

