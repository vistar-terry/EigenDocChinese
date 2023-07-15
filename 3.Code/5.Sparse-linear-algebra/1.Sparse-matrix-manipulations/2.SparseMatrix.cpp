#include <Eigen/Sparse>
#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
    // 构建稀疏矩阵
    Eigen::Matrix3f A;
    A << 1, 0, 0,
        0, 1, 4,
        3, 0, 0;
    int rows = A.rows();
    int cols = A.cols();

    // 代码索引 5-1-2-1
    /******* 填充稀疏矩阵 *******/
    // 填充稀疏矩阵，示例1
    int estimation_of_entries = 50;

    typedef Eigen::Triplet<double> T;
    std::vector<T> tripletList;
    tripletList.reserve(estimation_of_entries);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            double v_ij = A(i, j);
            if (v_ij != 0.0)
            {
                tripletList.push_back(T(i, j, v_ij));
            }
        }
    }
    Eigen::SparseMatrix<double> mat(rows, cols);
    mat.setFromTriplets(tripletList.begin(), tripletList.end());

    // 填充稀疏矩阵，示例2
    // Eigen::SparseMatrix<double> mat(rows, cols);
    // mat.reserve(Eigen::VectorXi::Constant(cols, 6));
    // for (int i = 0; i < rows; ++i)
    // {
    //     for (int j = 0; j < cols; ++j)
    //     {
    //         double v_ij = A(i, j);
    //         if (v_ij != 0)
    //         {
    //             mat.insert(i, j) = v_ij; // alternative: mat.coeffRef(i,j) += v_ij;
    //         }
    //     }
    // }
    // mat.makeCompressed(); // optional

    // 代码索引 5-1-2-2
    /******* 迭代非零系数 *******/
    std::cout << mat << std::endl;
    // 迭代稀疏矩阵的非零系数
    for (int k = 0; k < mat.outerSize(); ++k)
    {
        for (Eigen::SparseMatrix<double>::InnerIterator it(mat, k); it; ++it)
        {
            std::cout << "value: " << it.value();
            std::cout << " row: " << it.row();                  // row index
            std::cout << " col: " << it.col();                  // col index (here it is equal to k)
            std::cout << " index: " << it.index() << std::endl; // inner index, here it is equal to it.row()
        }
    }

    // 构建稀疏向量
    Eigen::VectorXf v{{2, 0, 0, 2, 4, 0, 0, 8, 6}}; // col vector
    int size = v.size();
    Eigen::SparseVector<double> vec(size);
    // 填充稀疏向量
    for (int i = 0; i < size; ++i)
    {
        double v_ij = v(i);
        if (v_ij != 0)
        {
            vec.insert(i) = v_ij; // alternative: vec.coeffRef(i,j) += v_ij;
        }
    }
    std::cout << vec << std::endl;
    // 迭代稀疏向量的非零系数
    for (Eigen::SparseVector<double>::InnerIterator it(vec); it; ++it)
    {
        std::cout << "value: " << it.value(); // == vec[ it.index() ]
        std::cout << " index: " << it.index() << std::endl;
    }

    return 0;
}
