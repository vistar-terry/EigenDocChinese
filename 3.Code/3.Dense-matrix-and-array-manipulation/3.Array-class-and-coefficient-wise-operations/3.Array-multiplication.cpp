// 代码索引 3-3-3-1
#include <Eigen/Dense>
#include <iostream>
 
int main()
{
    Eigen::ArrayXXf a(2,2);
    Eigen::ArrayXXf b(2,2);
    a << 1,2,
         3,4;
    b << 5,6,
         7,8;
    std::cout << "a * b = " << std::endl << a * b << std::endl;
}