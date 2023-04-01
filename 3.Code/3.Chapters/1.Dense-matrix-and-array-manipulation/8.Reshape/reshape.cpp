#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::Matrix4i m = Eigen::Matrix4i::Random();
    std::cout << "Here is the matrix m:" << std::endl
              << m << std::endl;
    std::cout << "Here is m.reshaped(2, 8):" << std::endl
              << m.reshaped(2, 8) << std::endl;
}