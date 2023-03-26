#include <Eigen/Dense>
#include <iostream>

int main()
{
    Eigen::VectorXf v(2);
    Eigen::MatrixXf m(2, 2), n(2, 2);

    v << -1,
        2;

    m << 1, -2,
        -3, 4;

    std::cout << "v.squaredNorm() = " << v.squaredNorm() << std::endl;
    std::cout << "v.norm() = " << v.norm() << std::endl;
    std::cout << "v.lpNorm<1>() = " << v.lpNorm<1>() << std::endl;
    std::cout << "v.lpNorm<Infinity>() = " << v.lpNorm<Eigen::Infinity>() << std::endl;

    std::cout << std::endl;
    std::cout << "m.squaredNorm() = " << m.squaredNorm() << std::endl;
    std::cout << "m.norm() = " << m.norm() << std::endl;
    std::cout << "m.lpNorm<1>() = " << m.lpNorm<1>() << std::endl;
    std::cout << "m.lpNorm<Infinity>() = " << m.lpNorm<Eigen::Infinity>() << std::endl;

    std::cout << std::endl;
    std::cout << "1-norm(m)     = " << m.cwiseAbs().colwise().sum().maxCoeff()
              << " == " << m.colwise().lpNorm<1>().maxCoeff() << std::endl;

    std::cout << "infty-norm(m) = " << m.cwiseAbs().rowwise().sum().maxCoeff()
              << " == " << m.rowwise().lpNorm<1>().maxCoeff() << std::endl;
}
