// 代码索引 3-2-5-1
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
    Eigen::Vector3d v(1,2,3);
    Eigen::Vector3d w(0,1,2);
    
    std::cout << "Dot product: " << v.dot(w) << std::endl;
    double dp = v.adjoint()*w; // automatic conversion of the inner product to a scalar
    std::cout << "Dot product via a matrix product: " << dp << std::endl;
    std::cout << "Cross product:\n" << v.cross(w) << std::endl;
}