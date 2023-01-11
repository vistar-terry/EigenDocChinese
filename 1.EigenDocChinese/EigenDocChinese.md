# Eigen中文文档

英文原文链接[http://eigen.tuxfamily.org/dox/index.html](http://eigen.tuxfamily.org/dox/index.html)

## 一、概述

这是Eigen3的API文档，你可以[下载](http://eigen.tuxfamily.org/dox/eigen-doc.tgz)它以便于离线阅读。

### 入门

对于第一次接触Eigen，学习Eigen最好的方法就是阅读该章节，这可以让你学会如何使用Eigen编写你的代码。

然后，快速参考页面以非常简洁的格式提供了API的相当完整的描述，这对于回忆特定特性的语法或快速浏览API非常有用。它们目前涵盖了以下两个特性集，将来还会有更多：

- 稠密矩阵和数组操作
- 稀疏线性代数

如果你会使用MATLAB，[这里](http://eigen.tuxfamily.org/dox/AsciiQuickReference.txt)有一个Eigen与MATLAB操作对照文档。

### 章节

章节是按照不同特性领域来划分的，他们由两个部分组成：用户手册页面、参考页面，前者综合性的描述了不同的特性，后者可以通过相关Eigen模块和类访问 API 文档。

### 扩展/自定义Eigen

在扩展/自定义Eigen部分，你可以找到有关扩展 Eigen 的功能和支持自定义标量类型的讨论和示例。

### 常见话题

你可以看到诸如预处理指令、控制断言、多线程、MKL使用和Eigen的内部见解等。

最后，使用搜索引擎可以让你快速的找到相关的类或者函数。



## 二、入门

这是一个非常简短的Eigen入门文章。该文章有两层目的。对于想要尽快开始编码的人来说，该文章是对[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)库的最简单介绍。你可以把该文章作为教程的第一部分，这更加详细的解释了Eigen库。看完这个教程后可以继续阅读 [The Matrix class](http://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html)教程。

### 如何安装Eigen

为了使用Eigen，你仅仅需要下载和解压Eigen的源码（有关下载说明，请参阅[wiki ](http://eigen.tuxfamily.org/index.php?title=Main_Page#Download)）。在Eigen的子目录中有头文件，这是你唯一需要的文件。这些文件在所有平台下都是通用的，无需使用Cmake或者安装什么。

### 第一个简单的程序

这是一个非常简单的程序。

```c++
#include <iostream>
#include <Eigen/Dense>
 
using Eigen::MatrixXd;
 
int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}
```

在告诉您如何编译之后，我们将解释该程序。

### 编译和运行第一个程序

不需要链接任何库。编译上述程序时唯一需要记住的是编译器必须能够找到[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)头文件。放置[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)源代码的路径必须在 `include` 路径中。使用GCC编译器时，需要用```-I```选项达到这一目的，因此可以使用如下命令编译程序：

```shell
g++ -I /path/to/eigen/ my_program.cpp -o my_program
```

在linux或者Mac OS X中，你也可以使用符号链接或者复制Eigen文件夹到```/usr/local/include/```。这样，你就可以使用下列命令来编译程序：

```shell
g++ my_program.cpp -o my_program
```

当你运行该程序时，将产生以下输出：

```
  3  -1
2.5 1.5
```

### 第一个程序的解释

```c++
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}
```

Eigen头文件定义了很多类型，但对于简单的应用程序，仅使用类型`MatrixXd`可能就足够了。它代表任意大小的矩阵，其中`X`代表任意大小，`d`代表元素的类型是`double`。有关可用于表示矩阵的不同类型的概述，请参阅[快速参考指南](http://eigen.tuxfamily.org/dox/group__QuickRefPage.html#QuickRef_Types)。

头文件`Eigen/Dense`定义了关于`MatrixXd`类型及相关类型的成员函数（另请参阅[头文件表](http://eigen.tuxfamily.org/dox/group__QuickRefPage.html#QuickRef_Headers)）。头文件中定义的所有的类和函数都在`Eigen`命名空间中。

上述`main`函数的第一行声明了一个`MatrixXd`类型的矩阵`m`，然后指定了该矩阵的大小为`2*2`，但没有初始化该矩阵。语句`m(0,0) = 3`代表将该`2*2`矩阵的左上角元素设置为`3`。你可以使用圆括号去访问矩阵中对应的元素，如`m(0,0)`。按照计算机科学中的惯例，第一个元素的索引为 0。

下面的三行代码设置其它三个元素。最后一行代码把矩阵`m`输送给标准的输出流。

### 示例2：矩阵和向量

这是另一个例子，它结合了矩阵和向量。包括以下两个版本的程序，输出一样：

版本一：

```c++
#include <iostream>
#include <Eigen/Dense>
 
using Eigen::MatrixXd;
using Eigen::VectorXd;
 
int main()
{
  MatrixXd m = MatrixXd::Random(3,3);
  m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
  std::cout << "m =" << std::endl << m << std::endl;
  VectorXd v(3);
  v << 1, 2, 3;
  std::cout << "m * v =" << std::endl << m * v << std::endl;
}
```

版本二：

```c++
#include <iostream>
#include <Eigen/Dense>

using Eigen::Matrix3d;
using Eigen::Vector3d;

int main()
{
  Matrix3d m = Matrix3d::Random();
  m = (m + Matrix3d::Constant(1.2)) * 50;
  std::cout << "m =" << std::endl << m << std::endl;
  Vector3d v(1,2,3);

  std::cout << "m * v =" << std::endl << m * v << std::endl;
}
```

输出：

```c++
m =
  94 89.8 43.5
49.4  101 86.8
88.3 29.8 37.8
m * v =
404
512
261
```

### 解释第二个例子

版本一首先使用`Random()`函数初始化了一个`3*3`的矩阵，其中每一个元素的值都在`-1`和`1`之间。下一行使用了一个线性变换，这让所有的值都在`10`到`110`之间。函数`MatrixXd::Constant(3,3,1.2)`返回一个所有元素都是`1.2`的`3*3`矩阵。其余部分是标准计算。

`main`函数的下一行引入了一个新类型`VectorXd`。它代表一个任意大小的列向量。向量`v`大小为`3`并且未初始化。倒数第二行使用了逗号初始化器，解释见[高级初始化](http://eigen.tuxfamily.org/dox/group__TutorialAdvancedInitialization.html)，此处将向量`v`初始化为：
$$
v=\begin{bmatrix} 1 \\ 2 \\ 3 \end{bmatrix}.
$$
最后一行让矩阵`m`和向量`v`相乘然后输出结果。



现在来解释版本二。

版本一中的`MatrixXd`表示任意大小的矩阵，版本二中的`Matrix3d`表示固定大小的矩阵（此处为 3*3）。因为类型已经固定了矩阵的大小，所以没有必要在构造函数中指定大小，只需要对其初始化即可。

同理，`VectorXd`代表任意大小的列向量，`Vector3d`代表固定大小的列向量（此处为 3）。同样因为类型已经固定了向量的大小，所以没有必要在构造函数中指定大小，只需要对其初始化即可。

使用固定大小的矩阵和向量有两个优点。编译器会编译出更好（更快）的代码，因为它知道矩阵和向量的大小。在类型中指定大小还允许在编译时进行更严格的检查。例如，如果你尝试将一个 `Matrix4d`（4*4 矩阵）与 一个 `Vector3d`（大小为 3 的向量）相乘，编译器会报错。然而，使用太多类型会增加编译时间和可执行文件的大小。矩阵的大小在编译时也可能是未知的。经验法则是对大小为 `4*4 `或更小的矩阵使用固定大小的类型，其他使用任意大小的类型`MatrixXd`。



## 三、章节







## 四、扩展/自定义Eigen









## 五、常见话题

