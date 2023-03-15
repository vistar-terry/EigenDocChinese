

# 一、概述

[英文原文链接](http://eigen.tuxfamily.org/dox/index.html)

这是Eigen3的API文档，你可以[下载](http://eigen.tuxfamily.org/dox/eigen-doc.tgz)它以便于离线阅读。

## 入门

对于第一次接触Eigen，学习Eigen最好的方法就是阅读该章节，这可以让你学会如何使用Eigen编写你的代码。

然后，快速参考页面以非常简洁的格式提供了API的相当完整的描述，这对于回忆特定特性的语法或快速浏览API非常有用。它们目前涵盖了以下两个特性集，将来还会有更多：

- 稠密矩阵和数组操作
- 稀疏线性代数

如果你会使用MATLAB，[这里](http://eigen.tuxfamily.org/dox/AsciiQuickReference.txt)有一个Eigen与MATLAB操作对照文档。

## 章节

章节是按照不同特性领域来划分的，他们由两个部分组成：用户手册页面、参考页面，前者综合性的描述了不同的特性，后者可以通过相关Eigen模块和类访问 API 文档。

## 扩展/自定义Eigen

在扩展/自定义Eigen部分，你可以找到有关扩展 Eigen 的功能和支持自定义标量类型的讨论和示例。

## 常见话题

你可以看到诸如预处理指令、控制断言、多线程、MKL使用和Eigen的内部见解等。

最后，使用搜索引擎可以让你快速的找到相关的类或者函数。



# 二、入门

[英文原文链接](http://eigen.tuxfamily.org/dox/GettingStarted.html)

这是一个非常简短的Eigen入门文章。该文章有两层目的。对于想要尽快开始编码的人来说，该文章是对[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)库的最简单介绍。你可以把该文章作为教程的第一部分，这更加详细的解释了Eigen库。看完这个教程后可以继续阅读 [The Matrix class](http://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html)教程。

## 如何安装Eigen

为了使用Eigen，你仅仅需要下载和解压Eigen的源码（有关下载说明，请参阅[wiki ](http://eigen.tuxfamily.org/index.php?title=Main_Page#Download)）。在Eigen的子目录中有头文件，这是你唯一需要的文件。这些文件在所有平台下都是通用的，无需使用Cmake或者安装什么。

>Eigen源码下载链接：[https://gitlab.com/libeigen/eigen/-/releases](https://gitlab.com/libeigen/eigen/-/releases)，选择你需要的版本下载。
>
>解压后，将其中的Eigen文件夹放到你的头文件目录，即可在你的工程中使用Eigen。

## 第一个简单的程序

这是一个非常简单的程序。

```c++
// 代码索引 2-1
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

## 编译和运行第一个程序

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

## 第一个程序的解释

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

## 示例2：矩阵和向量

这是另一个例子，它结合了矩阵和向量。包括以下两个版本的程序，输出一样：

版本一：

```c++
// 代码索引 2-2
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
// 代码索引 2-3
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

## 解释第二个例子

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



# 三、章节

## 3.1 稠密矩阵与数组操作

### 3.1.1 矩阵类

[英文原文链接](http://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html)

在Eigen中，所有矩阵和向量都是[Matrix](http://eigen.tuxfamily.org/dox/classEigen_1_1Matrix.html)模板类的对象。向量只是行数或者列数为`1`的特殊矩阵。

```c++
template<typename Scalar_, int Rows_, int Cols_, int Options_, int MaxRows_, int MaxCols_>
class Eigen::Matrix< Scalar_, Rows_, Cols_, Options_, MaxRows_, MaxCols_ >
```

#### Matrix前三个模板参数

Matrix类有`6`个模板参数，但现在了解前3个参数就足够了，剩下的3个参数有默认值，以后再讨论他们。

Matrix类3个强制模板参数是：

```C++
Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
```

- `Scalar`是标量的类型，例如系数的类型。如果你想要一个`float`类型的矩阵，那么你可以在这里填写`float`。有关所有支持的标量类型以及如何添加新类型，请参阅[标量类型](http://eigen.tuxfamily.org/dox/TopicScalarTypes.html)。
- `RowsAtCompileTime`和`ColsAtCompileTime`是矩阵的行数和列数，这是在编译时就知道的。如果在编译时不知道矩阵大小，请参阅下文“动态的特殊值”一节。

我们提供了很多常用的类型。例如，`Matrix4f`是`4*4`的`float`矩阵，这在Eigen中定义为：

```C++
typedef Matrix<float, 4, 4> Matrix4f;
```

下文会讨论这些常用类型的定义。

#### 向量

如上所述，在Eigen中，向量是一种特殊的矩阵，把只有`1`列的矩阵叫做`列向量`，通常把列向量称为`向量`。行数为`1`的矩阵叫做`行向量`。

例如，`Vector3f`是有3个`float`元素的列向量。在Eigen中这样定义：

```c++
typedef Matrix<float, 3, 1> Vector3f;
```

也提供了行向量的类型定义，如下表示有2个`int`元素的行向量：

```c++
typedef Matrix<int, 1, 2> RowVector2i;
```

#### 动态的特殊值

当然，Eigen不局限于处理编译时维度已知的矩阵。模板参数`RowsAtCompileTime`和`ColsAtCompileTime`可以是一个动态值，这表明在编译时矩阵大小是未知的，必须当作运行时的变量进行处理。在Eigen的术语中，这叫做动态大小；在编译期间就知道大小叫做固定大小。例如，`MatrixXd`是`double`类型的动态大小矩阵，定义如下：

```C++
typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
```

类似的，定义`int`类型的动态大小向量`VectorXi`如下：

```c++
typedef Matrix<int, Dynamic, 1> VectorXi;
```

也可以定义一个固定行数和一个动态列数的矩阵，如下：

```c++
Matrix<float, 3, Dynamic>
```

#### 构造函数

默认的构造函数始终可用，它不执行任何动态内存分配，也不初始化矩阵元素。例如：

```c++
Matrix3f a;
MatrixXf b;
```

- `a`是一个`3*3`的矩阵，实际上是一个`float[9]`的数组，而且没有初始化。
    - `b`是一个动态大小的矩阵，它的初始大小是0*0，而且没有开辟内存。


也有指定大小的构造函数。对于矩阵来说，第一个参数总是行，第二个参数是列，对于向量来说，只需要传入向量的大小即可。构造函数按照给定的大小开辟内存，但不会初始化内存。

```C++
MatrixXf a(10,15);
VectorXf b(30);
```

- `a`是一个动态大小为`10*15`的矩阵，开辟了内存但是没有初始化。
- `b`是一个动态大小为`30`的向量，同样开辟了内存但是没有初始化。

为了提供动态大小和固定大小矩阵统一的API，可以向固定大小矩阵的构造函数传递大小，虽然这是无效的，但是合法的：

```C++
Matrix3f a(3,3);
```

这并没有任何操作。

> `Matrix3f` 的定义是 `typedef Matrix<float, 3, 3> Matrix3f;` ，如果传入构造函数的大小不符合该定义就会报错，如`Matrix3f a(2, 3);`

矩阵和向量也可以从列表初始化。在C++11之前，此功能仅限于固定大小且不超过 `4` 的向量，如：

```C++
Vector2d a(5.0, 6.0);
Vector3d b(5.0, 6.0, 7.0);
Vector4d c(5.0, 6.0, 7.0, 8.0);
```

如果使用C++11编译，则可以通过列表来初始化任意固定大小的列或行向量，如：

```C++
Vector2i a(1, 2);                      // 包含 {1, 2} 的列向量
Matrix<int, 5, 1> b {1, 2, 3, 4, 5};   // 包含 {1, 2, 3, 4, 5} 的行向量
Matrix<int, 1, 5> c = {1, 2, 3, 4, 5}; // 包含 {1, 2, 3, 4, 5} 的列向量
```

初始化固定大小或者运行时大小固定的矩阵和向量时，必须将元素按照行进行分组，编译器会使用该分组一行一行的初始化矩阵，如下：

```C++
MatrixXi a {      // 构造一个 2*2 的矩阵
      {1, 2},     // 第一行
      {3, 4}      // 第二行
};
Matrix<double, 2, 3> b { // 构造一个 2*3 的矩阵
      {2, 3, 4},
      {5, 6, 7},
};
```

对于列或者行向量，允许隐式的转置。这意味着可以使用一个行分组对一个列向量初始化。

```C++
VectorXd a {{1.5, 2.5, 3.5}};             // 包含3个元素的列向量，行向量隐式转换成列向量
RowVectorXd b {{1.0, 2.0, 3.0, 4.0}};     // 包含4个元素的行向量，本来就是行向量
```

#### 访问元素

在Eigen中主要的元素访问与修改方法是重载括号运算符。对于矩阵，行索引总是优先传递的。对于向量，只需要传递一个索引，索引从0开始。如下：

```C++
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << "Here is the matrix m:\n" << m << std::endl;
  Eigen::VectorXd v(2);
  v(0) = 4;
  v(1) = v(0) - 1;
  std::cout << "Here is the vector v:\n" << v << std::endl;
}
```

输出：

```
Here is the matrix m:
  3  -1
2.5 1.5
Here is the vector v:
4
3
```

请注意 `m(index)` 不只用于向量，也可用于普通矩阵，这意味在元素数组中访问是基于索引的。但是，索引取决于矩阵的存储顺序。在Eigen中，矩阵默认列优先进行存储，也可以更改为行优先，详情查阅 [存储顺序](http://eigen.tuxfamily.org/dox/group__TopicStorageOrders.html)。

运算符`[]`同样也被重载用于基于索引的向量访问，但C++不允许运算符`[]`传入多个参数。所以Eigen限制了运算符`[]`只能用于`vector`，因为C++语言的笨拙，会把 `matrix[i,j]` 编译成 `matrix[j]`。

#### 逗号初始化

可以使用所谓的`逗号初始化`语法初始化矩阵和向量。如下：

```C++
Matrix3f m;
m << 1, 2, 3,
     4, 5, 6,
     7, 8, 9;
std::cout << m;
```

输出：

```c++
1 2 3
4 5 6
7 8 9
```

#### 重置大小

矩阵的当前大小可以通过 [rows()](https://eigen.tuxfamily.org/dox/structEigen_1_1EigenBase.html#ac22eb0695d00edd7d4a3b2d0a98b81c2)、[cols()](https://eigen.tuxfamily.org/dox/structEigen_1_1EigenBase.html#a2d768a9877f5f69f49432d447b552bfe) 和 [size()](https://eigen.tuxfamily.org/dox/structEigen_1_1EigenBase.html#ae106171b6fefd3f7af108a8283de36c9) 来检索。这些方法分别返回行数、列数和元素个数。调整动态大小矩阵的大小可以使用 [resize()](https://eigen.tuxfamily.org/dox/classEigen_1_1PlainObjectBase.html#a9fd0703bd7bfe89d6dc80e2ce87c312a) 方法。

```C++
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::MatrixXd m(2,5);
  m.resize(4,3);
  std::cout << "The matrix m is of size "
            << m.rows() << "x" << m.cols() << std::endl;
  std::cout << "It has " << m.size() << " coefficients" << std::endl;
  Eigen::VectorXd v(2);
  v.resize(5);
  std::cout << "The vector v is of size " << v.size() << std::endl;
  std::cout << "As a matrix, v is of size "
            << v.rows() << "x" << v.cols() << std::endl;
}
```

输出：

```
The matrix m is of size 4x3
It has 12 coefficients
The vector v is of size 5
As a matrix, v is of size 5x1
```

如果矩阵的大小没有改变，那么 `resize()` 方法是空操作。否则，该方法会破坏当前的矩阵，矩阵的元素可能会改变。如果你不想改变矩阵的系数，可以使用resize()的变体 [conservativeResize()](http://eigen.tuxfamily.org/dox/classEigen_1_1PlainObjectBase.html#a712c25be1652e5a64a00f28c8ed11462)。

> 这里进一步解释一下，如果矩阵的大小没有改变， `resize()` 不执行内存分配并且保持矩阵元素值不变，如果矩阵的大小改变了（行数、列数、元素数至少任意一个改变）  ，数据被重新分配并且丢失矩阵所有值初始化为0，如下：
>
> ```c++
> #include <iostream>
> #include <Eigen/Dense>
>  
> int main()
> {
>   Eigen::MatrixXd m{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
>   std::cout << "Before resize, the matrix m is: \n" << m << std::endl;
>   m.resize(3, 4);
>   std::cout << "After resize, the matrix m is: \n" << m << std::endl;
> }
> ```
>
> 输出：
>
> ```
> Before resize, the matrix m is: 
>  1  2  3  4
>  5  6  7  8
>  9 10 11 12
> 13 14 15 16
> After resize, the matrix m is: 
> 0 0 0 0
> 0 0 0 0
> 0 0 0 0
> ```

为了 API 统一，所有这些方法在固定大小的矩阵上仍然可用。当然，实际上无法调整固定大小的矩阵。尝试将固定大小更改为实际不同的值将触发断言失败，但代码在语法上是合法的，如下：

```C++
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::Matrix4d m;
  m.resize(4,4); // no operation
  std::cout << "The matrix m is of size "
            << m.rows() << "x" << m.cols() << std::endl;
}
```

输出：

```
The matrix m is of size 4x4
```

#### 赋值和重置大小

赋值是使用操作符 `=` 将一个矩阵复制到另一个矩阵的操作。Eigen会自动调整 `=` 左边的矩阵大小以便与和 `=` 右边的矩阵大小相匹配，例如：

```C++
MatrixXf a(2,2);
std::cout << "a is of size " << a.rows() << "x" << a.cols() << std::endl;
MatrixXf b(3,3);
a = b;
std::cout << "a is now of size " << a.rows() << "x" << a.cols() << std::endl;
```

输出：

```
a is of size 2x2
a is now of size 3x3
```

当然，如果 `=` 左边的矩阵大小是固定大小，重置大小是不被允许的。

如果不想这种自动调整大小的操作发生，可以禁用它，详情参考[this page](http://eigen.tuxfamily.org/dox/TopicResizing.html)。

#### 固定大小与动态大小

什么时候应该使用固定大小（例如`Matrix4f`），什么时候应该使用动态大小（例如`MatrixXf`）？

简单的答案是：尽可能对非常小的矩阵使用固定大小，对较大的矩阵必须使用动态尺寸。对于小矩阵，尤其是小于（大约）`16` 的矩阵，使用固定尺寸对性能非常有利，因为它允许[Eigen](https://eigen.tuxfamily.org/dox/namespaceEigen.html)避免动态内存分配和展开循环。在内部，固定大小的Eigen矩阵是一个普通数组，例如：

`Matrix4f mymatrix` 

等价于

`float mymatrix[16]`，

所以这没有没有运行成本。而动态矩阵需要在堆中分配空间，例如：

`MatrixXf mymatrix(rows,columns)` 

等价于

`float *mymatrix = new float[rows*columns]` ,

除此之外，`MatrixXf` 对象还存储了其行数和列数。

使用固定大小的限制就是要求在编译的时候就知道大小，而且对于大矩阵，例如大于`32`的矩阵，使用固定大小的矩阵带来的优势可以忽略不计。更糟糕的是，试图在函数内部使用固定大小的矩阵创建一个非常大的矩阵可能会导致栈溢出，因为[Eigen](https://eigen.tuxfamily.org/dox/namespaceEigen.html)会尝试将数组自动分配为局部变量，而这通常是在栈上完成的。最后，根据情况，当使用动态大小时， [Eigen](https://eigen.tuxfamily.org/dox/namespaceEigen.html)也可以更积极地尝试向量化（使用 SIMD 指令），请参阅[矢量化](https://eigen.tuxfamily.org/dox/TopicVectorization.html)。

#### 可选模板参数

在开始的时候，我们提及`Matrix`类有6个模板参数，但是，目前只讨论了前三个，剩下的三个参数是可供选择的。下面是完整的模板参数：

```C++
Matrix<typename Scalar,
       int RowsAtCompileTime,
       int ColsAtCompileTime,
       int Options = 0,
       int MaxRowsAtCompileTime = RowsAtCompileTime,
       int MaxColsAtCompileTime = ColsAtCompileTime>
```

- `Options `是一个位域。这里以`RowMajor`为例，它指定了矩阵按照行优先进行存储。默认情况下，存储顺序是按照列存储的。例如 `Matrix<float, 3, 3, RowMajor>` 是指一个行优先的`3*3`矩阵。

    > `Options` 是一个枚举，具体见 [Eigen::StorageOptions](https://eigen.tuxfamily.org/dox/group__enums.html#gaacded1a18ae58b0f554751f6cdf9eb13) 。
- `MaxRowsAtCompileTime` 和 `MaxColsAtCompileTime` 是矩阵大小的上界，这让即使在编译时不知道矩阵的确切大小，但已知固定的上限，可以避免动态内存分配。例如，```Matrix<float, Dynamic, Dynamic, 0, 3, 4>``` 会在编译时使用一个大小为`12`的`float`类型的数组，而不需要动态分配内存。

#### 其他常用Matrix类型

[Eigen](https://eigen.tuxfamily.org/dox/namespaceEigen.html) 定义了以下 [Matrix](https://eigen.tuxfamily.org/dox/classEigen_1_1Matrix.html) 类型：

|           类型           |  类型别名   |                   示例                    |
| :----------------------: | :---------: | :---------------------------------------: |
|    Matrix<type, N, N>    |  MatrixNt   | MatrixXi -> Matrix<int, Dynamic, Dynamic> |
| Matrix<type, Dynamic, N> |  MatrixXNt  |   MatrixX3i -> Matrix<int, Dynamic, 3>    |
| Matrix<type, N, Dynamic> |  MatrixNXt  |    Matrix4Xd -> Matrix<d, 4, Dynamic>     |
|    Matrix<type, N, 1>    |  VectorNt   |      Vector2f -> Matrix<float, 2, 1>      |
|    Matrix<type, 1, N>    | RowVectorNt |    RowVector3d -> Matrix<double, 1, 3>    |

- `N`可以是`2`, `3`, `4` 或`X`(意思是`Dynamic`) 中的任何一个。
- `t`可以是`i(int)`、`f(float)`、`d(double)`、`cf(complex<float>)` 或`cd(complex<double>)` 中的任何一个。虽然这里只定义了五种类型，但并不意味只支持这五种。例如，还支持所有标准整数类型，请参阅[标量类型](https://eigen.tuxfamily.org/dox/TopicScalarTypes.html)。

### 3.1.2 矩阵与向量运算

[英文原文(Matrix and vector arithmetic)](http://eigen.tuxfamily.org/dox/group__TutorialMatrixArithmetic.html)

本文章旨在提供有关如何使用 [Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html) 在矩阵、向量和标量之间执行算术操作的概述和一些详细信息。

#### 介绍

[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html) 通过重载常见的 C++ 算术运算符（如 `+`、`-`、`*`）或通过特殊方法（如 `dot()`、`cross()` 等）提供矩阵/向量算术运算。对于 [Matrix](http://eigen.tuxfamily.org/dox/classEigen_1_1Matrix.html) 类（矩阵和向量），重载运算符仅支持线性代数运算。例如，`matrix1 * matrix2` 代表矩阵乘法，`vector + scalar` 向量与标量的加法是不合法的。如果想执行各种数组运算，而不是线性代数，请参阅 [数组类与元素操作](http://eigen.tuxfamily.org/dox/group__TutorialArrayClass.html)。

#### 加法与减法

操作符左右两侧的矩阵必须有相同的行数和列数，且它们的元素必须是同种类型，因为Eigen不支持自动类型转换。目前支持的运算符示例如下：

|            | 运算符 | 示例 |
| :--------: | :----: | :--: |
| 二元运算符 |   +    | a+b  |
| 二元运算符 |   -    | a-b  |
| 一元运算符 |   -    |  -a  |
| 复合运算符 |   +=   | a+=b |
| 复合运算符 |   -=   | a-=b |

代码示例：

```c++
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::Matrix2d a;
  a << 1, 2,
       3, 4;
  Eigen::MatrixXd b(2,2);
  b << 2, 3,
       1, 4;
  std::cout << "a + b =\n" << a + b << std::endl;
  std::cout << "a - b =\n" << a - b << std::endl;
  std::cout << "Doing a += b;" << std::endl;
  a += b;
  std::cout << "Now a =\n" << a << std::endl;
  Eigen::Vector3d v(1,2,3);
  Eigen::Vector3d w(1,0,0);
  std::cout << "-v + w - v =\n" << -v + w - v << std::endl;
}
```

输出：

```c++
a + b =
3 5
4 8
a - b =
-1 -1
 2  0
Doing a += b;
Now a =
3 5
4 8
-v + w - v =
-1
-4
-6
```

#### 标量的标量乘法与除法

标量的乘法和除法也非常简单。目前支持的运算符示例如下：

|            | 运算符 |                示例                |
| :--------: | :----: | :--------------------------------: |
| 二元运算符 |   *    |  matrix * scalar<br>(矩阵 * 标量)  |
| 二元运算符 |   *    |  scalar * matrix<br>(标量 * 矩阵)  |
| 二元运算符 |   /    |  matrix / scalar<br>(矩阵 / 标量)  |
| 复合运算符 |   *=   | matrix *= scalar<br>(矩阵 *= 标量) |
| 复合运算符 |   /=   | matrix /= scalar<br>(矩阵 /= 标量) |

代码示例：

```c++
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::Matrix2d a;
  a << 1, 2,
       3, 4;
  Eigen::Vector3d v(1,2,3);
  std::cout << "a * 2.5 =\n" << a * 2.5 << std::endl;
  std::cout << "0.1 * v =\n" << 0.1 * v << std::endl;
  std::cout << "Doing v *= 2;" << std::endl;
  v *= 2;
  std::cout << "Now v =\n" << v << std::endl;
}
```

输出：

```
a * 2.5 =
2.5   5
7.5  10
0.1 * v =
0.1
0.2
0.3
Doing v *= 2;
Now v =
2
4
6
```

#### 表达式模板

这是一个比较高级的话题，但在这里提出是比较有用的。在Eigen中，诸如`+`之类的算术运算符，他们自己不执行任何操作，只是返回一个表达式对象，该对象描述了将要执行的计算操作。实际的计算发生在后面整个表达式被求值的时侯，比如使用`=`运算符时。虽然这听起来很繁琐，但任何现代优化编译器都能优化掉这种抽象，从而得到完美优化代码。例如：

```c++
VectorXf a(50), b(50), c(50), d(50);
...
a = 3*b + 4*c + 5*d;
```

Eigen会把上述表达式编译成一个循环，这个数组只遍历一次。数组循环如下所示：

```C++
for(int i = 0; i < 50; ++i)
  a[i] = 3*b[i] + 4*c[i] + 5*d[i];
```

因此，你不要害怕使用相对较大的运算表达式，这只会给Eigen更多机会进行优化。

#### 转置与共轭

矩阵或向量 $a$ 的转置($a^T$)、共轭($\overline{a}$)和伴随($a^*$ ，如共轭转置)可以分别通过函数`transpose()`、 `conjugate()`、`adjoint()`求得。

示例如下：

```c++
MatrixXcf a = MatrixXcf::Random(2,2);
cout << "Here is the matrix a\n" << a << endl;

cout << "Here is the matrix a^T\n" << a.transpose() << endl;
 
cout << "Here is the conjugate of a\n" << a.conjugate() << endl;
 
cout << "Here is the matrix a^*\n" << a.adjoint() << endl;
```

输出如下：

```c++
Here is the matrix a
 (-0.211,0.68) (-0.605,0.823)
 (0.597,0.566)  (0.536,-0.33)
Here is the matrix a^T
 (-0.211,0.68)  (0.597,0.566)
(-0.605,0.823)  (0.536,-0.33)
Here is the conjugate of a
 (-0.211,-0.68) (-0.605,-0.823)
 (0.597,-0.566)    (0.536,0.33)
Here is the matrix a^*
 (-0.211,-0.68)  (0.597,-0.566)
(-0.605,-0.823)    (0.536,0.33)
```

对于实数矩阵，共轭函数`conjugate()`是空操作，所以共轭转置函数`adjoint()`相当于转置`transpose()`。

作为基本的操作运算，`transpose()`和`adjoint()`函数只返回一个代理对象而没有做任何操作。如果执行`b = a.transpose()`，真正的转置计算是在写入`b`的时候发生的。然而，这有一个复杂的问题，如果执行`a = a.transpose()`，Eigen在转置计算完全完成之前就开始写入a，所以指令`a = a.transpose()`不会得到预期的结果。

示例如下：

```c++
Matrix2i a; a << 1, 2, 3, 4;
cout << "Here is the matrix a:\n" << a << endl;
 
a = a.transpose(); // !!! do NOT do this !!!
cout << "and the result of the aliasing effect:\n" << a << endl;
```

输出为：

```c++
Here is the matrix a:
1 2
3 4
and the result of the aliasing effect:
1 2
2 4
```

上述的问题就是所谓的混淆问题，在`debug`模式下，当`assertion`打开，这个问题可以自动检测到。（g++编译默认是debug模式，关闭需要使用`-DNDEBUG`选项）。

对于就地转置，可以使用`transposeInPlace()`函数：

示例如下：

```c++
MatrixXf a(2,3); a << 1, 2, 3, 4, 5, 6;
cout << "Here is the initial matrix a:\n" << a << endl;

a.transposeInPlace();
cout << "and after being transposed:\n" << a << endl;
```

输出为：

```c++
Here is the initial matrix a:
1 2 3
4 5 6
and after being transposed:
1 4
2 5
3 6
```

同样，对于复杂矩阵的就地共轭也有`adjointInPlace()`函数。

#### (矩阵与矩阵)和(矩阵与向量)的乘积

矩阵与矩阵间的乘积是通过运算符`*`来完成的。由于向量是特殊的矩阵，所以向量和矩阵的乘积实际上只是矩阵与矩阵乘积的特例，向量与向量的外积也是如此。所有的情况都会被处理成两类：

|            | 运算符 |      示例       |
| :--------: | :----: | :-------------: |
| 二元运算符 |   *    |      a * b      |
| 混合运算符 |   \*=   | a*=b<br>(即a=a\*b) |

示例如下：

```c++
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::Matrix2d mat;
  mat << 1, 2,
         3, 4;
  Eigen::Vector2d u(-1,1), v(2,0);
  std::cout << "Here is mat*mat:\n" << mat*mat << std::endl;
  std::cout << "Here is mat*u:\n" << mat*u << std::endl;
  std::cout << "Here is u^T*mat:\n" << u.transpose()*mat << std::endl;
  std::cout << "Here is u^T*v:\n" << u.transpose()*v << std::endl;
  std::cout << "Here is u*v^T:\n" << u*v.transpose() << std::endl;
  std::cout << "Let's multiply mat by itself" << std::endl;
  mat = mat*mat;
  std::cout << "Now mat is mat:\n" << mat << std::endl;
}
```

输出为：

```
Here is mat*mat:
 7 10
15 22
Here is mat*u:
1
1
Here is u^T*mat:
2 2
Here is u^T*v:
-2
Here is u*v^T:
-2 -0
 2  0
Let's multiply mat by itself
Now mat is mat:
 7 10
15 22
```

注意：如果你阅读过上面的关于表达式模板的段落并且担心 `m = m * m` 会引发混淆问题，这里请放心，Eigen把矩阵乘法作为一个特殊的例子，并在此引入了一个临时变量，所以它会编译为：

```c++
tmp = m*m;
m = tmp;
```

如果你知道你的矩阵乘法可以安全的计算并且没有混淆问题，那么你可以使用`noalias()`函数来避免编译临时变量，例如：

```C++
c.noalias() += a * b;
```

更多细节请参考 [aliasing](http://eigen.tuxfamily.org/dox/group__TopicAliasing.html)

注意：对于担心性能的 BLAS 用户，表达式如：`c.noalias() -= 2 * a.adjoint() * b;`可以完全的优化并触发一个类似矩阵乘法的函数调用。

#### 点积和叉积

对于点积和叉积，需要使用 [dot()](http://eigen.tuxfamily.org/dox/classEigen_1_1MatrixBase.html#adfd32bf5fcf6ee603c924dde9bf7bc39) 和 [cross() ](http://eigen.tuxfamily.org/dox/group__Geometry__Module.html#ga0024b44eca99cb7135887c2aaf319d28)方法。当然，点积也可以像 `u.adjoint()*v` 一样得到一个1x1的矩阵。

示例如下：

```c++
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
```

输出为：

```
Dot product: 8
Dot product via a matrix product: 8
Cross product:
 1
-2
 1
```

注意，叉积仅适用于大小为 `3` 的向量。点积适用于任何大小的向量。使用复数时，Eigen的点积在第一个变量中是共轭线性的，在第二个变量中是线性的。



#### 基本算术的简化运算

Eigen还提供了一些简单操作来将给定的矩阵或向量计算为标量，例如求和（[sum()](http://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#addd7080d5c202795820e361768d0140c)）、乘积 ( [prod()](http://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#af119d9a4efe5a15cd83c1ccdf01b3a4f) ) 、最大值 ( [maxCoeff()](http://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#a7e6987d106f1cca3ac6ab36d288cc8e1) ) 和最小值 ( [minCoeff()](http://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#a0739f9c868c331031c7810e21838dcb2) ) 。

示例如下：

```c++
#include <iostream>
#include <Eigen/Dense>
 
using namespace std;
int main()
{
  Eigen::Matrix2d mat;
  mat << 1, 2,
         3, 4;
  cout << "Here is mat.sum():       " << mat.sum()       << endl;
  cout << "Here is mat.prod():      " << mat.prod()      << endl;
  cout << "Here is mat.mean():      " << mat.mean()      << endl;
  cout << "Here is mat.minCoeff():  " << mat.minCoeff()  << endl;
  cout << "Here is mat.maxCoeff():  " << mat.maxCoeff()  << endl;
  cout << "Here is mat.trace():     " << mat.trace()     << endl;
}
```

输出为：

```c++
Here is mat.sum():       10
Here is mat.prod():      24
Here is mat.mean():      2.5
Here is mat.minCoeff():  1
Here is mat.maxCoeff():  4
Here is mat.trace():     5
```

矩阵的迹（对角线系数的总和）可以通过函数[trace()](http://eigen.tuxfamily.org/dox/classEigen_1_1MatrixBase.html#a544b609f65eb2bd3e368b3fc2d79479e)计算，也可以使用更高效的方法`a.diagonal().sum()`。

也存在`minCoeff`和`maxCoeff`函数的变体，通过参数返回相应系数的坐标：

```c++
  Matrix3f m = Matrix3f::Random();
  std::ptrdiff_t i, j;
  float minOfM = m.minCoeff(&i,&j);
  cout << "Here is the matrix m:\n" << m << endl;
  cout << "Its minimum coefficient (" << minOfM 
       << ") is at position (" << i << "," << j << ")\n\n";
 
  RowVector4i v = RowVector4i::Random();
  int maxOfV = v.maxCoeff(&i);
  cout << "Here is the vector v: " << v << endl;
  cout << "Its maximum coefficient (" << maxOfV 
       << ") is at position " << i << endl;
```

输出为：

```c++ 
Here is the matrix m:
  0.68  0.597  -0.33
-0.211  0.823  0.536
 0.566 -0.605 -0.444
Its minimum coefficient (-0.605) is at position (2,1)

Here is the vector v:  1  0  3 -3
Its maximum coefficient (3) is at position 2
```



#### 操作的有效性

Eigen会检查操作的有效性，如果有错误，它会在编译的时候产生错误提示。这些错误提示可能又长又难看，但Eigen会把重要的信息写成大写，以使其更加显眼，例如：

```c++
Matrix3f m;
Vector4f v;
v = m*v;      // Compile-time error: YOU_MIXED_MATRICES_OF_DIFFERENT_SIZES
```

当然，在很多情况下，如检查动态矩阵的大小时，无法在编译时进行检查，Eigen会使用运行时的断言。这意味如果程序在debug模式下运行，遇到非法操作时会终止运行并打印出错误信息。如果关闭断言，程序可能会崩溃。

```c++
MatrixXf m(3,3);
VectorXf v(4);
v = m * v; // Run-time assertion failure here: "invalid matrix product"
```



### 3.1.3 数组类与元素操作

[英文原文链接](http://eigen.tuxfamily.org/dox/group__TutorialArrayClass.html)

本页旨在提供有关如何使用[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)的[Array](http://eigen.tuxfamily.org/dox/classEigen_1_1Array.html)类的概述和说明。

#### 什么是数组类？

与`Matrix`类用于线性代数计算不同的是，`Array`类提供了通用目的数组。此外，[Array](http://eigen.tuxfamily.org/dox/classEigen_1_1Array.html)类提供了一种执行按系数运算的简单方法，这可能没有线性代数意义，例如对每一个元素都加一个常数或按系数将两个数组相乘。

#### 数组类型

`Array`是一个类模板，采用与`Matrix`相同的模板参数。与`Matrix`一样，前三个模板参数是必需的：

```c++
Array<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
```

最后三个模板参数是可选的。由于这与`Matrix`完全相同，因此不再在此解释，仅参考[Matrix 类](http://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html)。

Eigen还提供了一些常见的类型定义，其方式类似于`Matrix`类型定义，但有一些细微差别，因为`Array`一词用于一维和二维数组。使用`ArrayNt`代表一维N个大小的标量，其中 N 和 t 是大小和标量类型，详见[矩阵与向量运算](# 3.1.2 矩阵与向量运算)。对于二维数组类型，使用 `ArrayNNt `表示。示例如下：

|             类型              | 类型定义 |
| :---------------------------: | :------: |
|    Array<float,Dynamic,1>     | ArrayXf  |
|       Array<float,3,1>        | Array3f  |
| Array<double,Dynamic,Dynamic> | ArrayXXd |
|       Array<double,3,3>       | Array33d |



#### 访问数组中的值

就像矩阵一样，使用括号运算符可以访问数组中的值。另外，`<<`运算符可用于初始化数组（使用逗号初始化）或打印它们。

例如：

```c++
#include <Eigen/Dense>
#include <iostream>
 
int main()
{
  Eigen::ArrayXXf  m(2,2);
  
  // assign some values coefficient by coefficient
  m(0,0) = 1.0; m(0,1) = 2.0;
  m(1,0) = 3.0; m(1,1) = m(0,1) + m(1,0);
  
  // print values to standard output
  std::cout << m << std::endl << std::endl;
 
  // using the comma-initializer is also allowed
  m << 1.0,2.0,
       3.0,4.0;
     
  // print values to standard output
  std::cout << m << std::endl;
}
```

输出如下：

```c++
1 2
3 5

1 2
3 4
```

有关逗号初始化的更多信息，请参阅[高级初始化](http://eigen.tuxfamily.org/dox/group__TutorialAdvancedInitialization.html)。



#### 加法与减法

两个数组的加减法与矩阵相同。如果两个数组的大小相同，并且加法或减法是按系数进行的，则该操作有效。

`Array` 还支持 `array + scalar` 的表达形式，这实现了对数组的每个系数都加一个常数。并且这是在`Matrix`类中不能直接使用的功能。

示例如下：

```c++
#include <Eigen/Dense>
#include <iostream>
 
int main()
{
  Eigen::ArrayXXf a(3,3);
  Eigen::ArrayXXf b(3,3);
  a << 1,2,3,
       4,5,6,
       7,8,9;
  b << 1,2,3,
       1,2,3,
       1,2,3;
       
  // Adding two arrays
  std::cout << "a + b = " << std::endl << a + b << std::endl << std::endl;
 
  // Subtracting a scalar from an array
  std::cout << "a - 2 = " << std::endl << a - 2 << std::endl;
}
```

输出如下：

```c++
a + b = 
 2  4  6
 5  7  9
 8 10 12

a - 2 = 
-1  0  1
 2  3  4
 5  6  7
```



#### 数组乘法

当然你可以将一个数组乘以一个标量，这与矩阵相同。数组与矩阵不同的地方在于自身相乘，矩阵将乘法解释为矩阵乘积，而数组将乘法解释为系数乘积。因此，两个数组相乘时它们必须具有相同的维度。

示例如下：

```c++
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
```

输出如下：

```c++
a * b = 
 5 12
21 32
```



#### 其他按元素操作的运算

除了上述的加法、减法和乘法运算符之外，`Array` 类还定义了其他按系数计算的运算。例如，`abs()` 方法对每个元素取绝对值，而`sqrt()`计算每个系数的平方根。如果你有两个相同大小的数组，你可以调用`min(.)`来构造一个数组，其元素是两个给定数组对应元素的最小值。这些操作在以下示例中进行了说明：

```c++
#include <Eigen/Dense>
#include <iostream>
 
int main()
{
  Eigen::ArrayXf a = Eigen::ArrayXf::Random(5);
  a *= 2;
  std::cout << "a =" << std::endl
            << a << std::endl;
  std::cout << "a.abs() =" << std::endl
            << a.abs() << std::endl;
  std::cout << "a.abs().sqrt() =" << std::endl
            << a.abs().sqrt() << std::endl;
  std::cout << "a.min(a.abs().sqrt()) =" << std::endl
            << a.min(a.abs().sqrt()) << std::endl;
}
```

输出如下：

```c++
a =
  1.36
-0.422
  1.13
  1.19
  1.65
a.abs() =
 1.36
0.422
 1.13
 1.19
 1.65
a.abs().sqrt() =
1.17
0.65
1.06
1.09
1.28
a.min(a.abs().sqrt()) =
  1.17
-0.422
  1.06
  1.09
  1.28
```



#### array和matrix表达式之间的转换

什么时候应该使用`Matrix` 类的对象，什么时候应该使用 `Array` 类的对象呢？

首先， `Matrix` 类和`Array`类的方法不通用。如果需要进行线性代数运算，例如矩阵乘法，那么应该使用 `Matrix` 类；如果需要做元素运算，那么应该使用`Array`类。然而，有时并没有那么简单，而是需要同时使用`Matrix` 类和`Array`类。这种情况下，需要将`Matrix` 转换为`Array`或相反。这样就可以使用所有操作，而不管对象声明为`Matrix` 还是`Array`。

`Matrix` 类有一个 [.array()](http://eigen.tuxfamily.org/dox/classEigen_1_1MatrixBase.html#a354c33eec32ceb4193d002f4d41c0497) 方法可以将`Matrix` 转换为`Array`。同样，`Array`有一个 [.matrix()](http://eigen.tuxfamily.org/dox/classEigen_1_1ArrayBase.html#af01e9ea8087e390af8af453bbe4c276c) 方法。由于Eigen表达式的抽象，这些转换发生在编译的时候，所以不需要任何运行时间成本。`.array()`和`.matrix()`既可以作为左值，也可以作为右值。

Eigen 禁止在表达式中混合使用`Matrix` 和`Array`。例如，不能将`Matrix` 和`Array`直接相加；运算符的操作对象要么都是`Matrix`，要么都是`Array`，但转换后是可以的。此规则的例外是赋值运算符，允许将`Matrix` 赋值给`Array`，或将将 `Array` 赋值给`Matrix`。

以下示例展示了如何通过使用`.array()`方法对 `Matrix` 对象使用`Array`的方法。例如，语句 `result = m.array() * n.array()` 将两个矩阵`m`和`n`都转换为数组，并使它们按系数相乘，再将结果分配给矩阵变量（这是合法的，因为Eigen允许将数组表达式赋值给矩阵变量）。

事实上，这种用例非常普遍，以至于Eigen为矩阵提供了一个 [const .cwiseProduct(.)](http://eigen.tuxfamily.org/dox/group__TutorialArrayClass.html) 方法来满足按元素相乘的需求。

示例如下：

```c++
#include <Eigen/Dense>
#include <iostream>
 
using Eigen::MatrixXf;
 
int main()
{
  MatrixXf m(2,2);
  MatrixXf n(2,2);
  MatrixXf result(2,2);
 
  m << 1,2,
       3,4;
  n << 5,6,
       7,8;
 
  result = m * n;
  std::cout << "-- Matrix m*n: --\n" << result << "\n\n";
  result = m.array() * n.array();
  std::cout << "-- Array m*n: --\n" << result << "\n\n";
  result = m.cwiseProduct(n);
  std::cout << "-- With cwiseProduct: --\n" << result << "\n\n";
  result = m.array() + 4;
  std::cout << "-- Array m + 4: --\n" << result << "\n\n";
}
```

输出如下：

```c++
-- Matrix m*n: --
19 22
43 50

-- Array m*n: --
 5 12
21 32

-- With cwiseProduct: --
 5 12
21 32

-- Array m + 4: --
5 6
7 8
```



同样，如果`array1`和`array2`是数组，则表达式`array1.matrix() * array2.matrix()`可以计算他们的矩阵乘积。

接下来是一个更复杂一点的示例，表达式`(m.array() + 4).matrix() * m`对每一个元素都加`4`，然后计算表达式结果与矩阵`m`的矩阵乘积。类似的，表达式`(m.array() * n.array()).matrix() * m`按元素计算矩阵`m`和`n`的乘积，然后计算其结果与`m`的矩阵乘法。

示例如下：

```c++
#include <Eigen/Dense>
#include <iostream>
 
using Eigen::MatrixXf;
 
int main()
{
  MatrixXf m(2,2);
  MatrixXf n(2,2);
  MatrixXf result(2,2);
 
  m << 1,2,
       3,4;
  n << 5,6,
       7,8;
  
  result = (m.array() + 4).matrix() * m;
  std::cout << "-- Combination 1: --\n" << result << "\n\n";
  result = (m.array() * n.array()).matrix() * m;
  std::cout << "-- Combination 2: --\n" << result << "\n\n";
}
```

输出如下：

```
-- Combination 1: --
23 34
31 46

-- Combination 2: --
 41  58
117 170
```



### 3.1.4 块操作

[英文原文链接](http://eigen.tuxfamily.org/dox/group__TutorialBlockOperations.html)

本文介绍了块操作。块是`matrix`或`array`的部分矩形元素。块表达式既可以用作右值也可以用作左值。与Eigen表达式一样，如果让编译器进行优化，则块操作的运行时间成本为零。



#### 使用块操作

在Eigen中最常见的块操作是`.block()` ，这有两个版本，语法如下：

|块操作| 构建一个动态大小的块表达式         | 构建一个固定大小的块表达式 |
| :--------------------------------- | :------------------------- | : |
| 大小为 `(p,q)`, 起始于 `(i,j)`的块 | matrix.block(i,j,p,q);     | matrix.block<p,q>(i,j); |

Eigen的索引是以0开始的。

这两个版本都可以用在固定大小和动态大小的`matrices`和`array`上。两种表达式在语义上是一致的，唯一的区别是，固定大小的版本会在块比较小的时候快一点，但要求块大小在编译的时候就知道。

以下程序使用动态大小和固定大小版本打印matrix中的几个块：

```c++
#include <Eigen/Dense>
#include <iostream>
 
using namespace std;
 
int main()
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
```

输出如下：

```
Block in the middle
 6  7
10 11

Block of size 1x1
1

Block of size 2x2
1 2
5 6

Block of size 3x3
 1  2  3
 5  6  7
 9 10 11
```

在上述的例子中`.block()`函数被用作右值，即它只被读取。但块也可以用作*左值*，这意味着可以给块赋值。

以下示例中进行了说明。此示例还演示了数组中的块，其工作方式与上面演示的矩阵中的块完全相同。

 ```c++
#include <Eigen/Dense>
#include <iostream>
 
int main()
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
 ```

输出如下：

```c++
Here is the array a:
0.6 0.6 0.6 0.6
0.6 0.6 0.6 0.6
0.6 0.6 0.6 0.6
0.6 0.6 0.6 0.6

Here is now a with m copied into its central 2x2 block:
0.6 0.6 0.6 0.6
0.6   1   2 0.6
0.6   3   4 0.6
0.6 0.6 0.6 0.6

Here is now a with bottom-right 2x3 block copied into top-left 2x3 block:
  3   4 0.6 0.6
0.6 0.6 0.6 0.6
0.6   3   4 0.6
0.6 0.6 0.6 0.6
```

虽然 `.block()` 方法可用于任何块操作，但还有其他方法用于特殊情况，可以提供更好的性能。在性能表现上，最重要的是能在编译时给Eigen尽可能多的信息。例如，所使用的块是矩阵的一整列，那么使用`.col()`函数可以让Eigen知道这只是一列，从而给更多的优化机会。

以下部分描述了这些特殊方法。



#### 列和行

单独的列和行是特殊的块，Eigen提供了更便捷的方法`.col()`和`.row()`处理这些块。

| 块操作  | 方法           |
| :------ | :------------- |
| 第 i 行 | matrix.row(i); |
| 第 i 列 | matrix.col(j); |

`row()`和`col()`的参数是需要访问的行和列的索引，在Eigen中是从0开始的。

示例如下：

```c++
#include <Eigen/Dense>
#include <iostream>
 
using namespace std;
 
int main()
{
  Eigen::MatrixXf m(3,3);
  m << 1,2,3,
       4,5,6,
       7,8,9;
  cout << "Here is the matrix m:" << endl << m << endl;
  cout << "2nd Row: " << m.row(1) << endl;
  m.col(2) += 3 * m.col(0);
  cout << "After adding 3 times the first column into the third column, the matrix m is:\n";
  cout << m << endl;
}
```

输出如下：

```c++
Here is the matrix m:
1 2 3
4 5 6
7 8 9
2nd Row: 4 5 6
After adding 3 times the first column into the third column, the matrix m is:
 1  2  6
 4  5 18
 7  8 30
```

如该示例所示块表达式可以像任何其他表达式一样用于算术。



#### 关于角的操作

Eigen还对位于矩阵或数组的角或边的块提供了特殊方法，例如：`.topLeftCorner()` 可以用于引用一个矩阵左上角的块。

下表列出了各种各样的可能：

| 块操作                       | 构建一个动态大小的块表达式     | 构建一个固定大小的块表达式       |
| :--------------------------- | :----------------------------- | :------------------------------- |
| 左上角的一个大小为p*q的块    | matrix.topLeftCorner(p,q);     | matrix.topLeftCorner<p,q>();     |
| 左下角的一个大小为p*q的块    | matrix.bottomLeftCorner(p,q);  | matrix.bottomLeftCorner<p,q>();  |
| 右上角的一个大小为p*q的块    | matrix.topRightCorner(p,q);    | matrix.topRightCorner<p,q>();    |
| 右下角的一个大小为p*q的块    | matrix.bottomRightCorner(p,q); | matrix.bottomRightCorner<p,q>(); |
| 包含前 q 行的块              | matrix.topRows(q);             | matrix.topRows<q>();             |
| 包含后 q 行的块              | matrix.bottomRows(q);          | matrix.bottomRows<q>();          |
| 包含前 p 列的块              | matrix.leftCols(p);            | matrix.leftCols<p>();            |
| 包含后 p 列的块              | matrix.rightCols(q);           | matrix.rightCols<q>();           |
| 包含从第 i 列开始的 q 列的块 | matrix.middleCols(i,q);        | matrix.middleCols<q>(i);         |
| 包含从第 i 行开始的 q 行的块 | matrix.middleRows(i,q);        | matrix.middleRows<q>(i);         |

下面是一个简单的例子，描述了上面介绍的操作的使用：

```c++
#include <Eigen/Dense>
#include <iostream>
 
using namespace std;
 
int main()
{
  Eigen::Matrix4f m;
  m << 1, 2, 3, 4,
       5, 6, 7, 8,
       9, 10,11,12,
       13,14,15,16;
  cout << "m.leftCols(2) =" << endl << m.leftCols(2) << endl << endl;
  cout << "m.bottomRows<2>() =" << endl << m.bottomRows<2>() << endl << endl;
  m.topLeftCorner(1,3) = m.bottomRightCorner(3,1).transpose();
  cout << "After assignment, m = " << endl << m << endl;
}
```

输出如下：

```c++
m.leftCols(2) =
 1  2
 5  6
 9 10
13 14

m.bottomRows<2>() =
 9 10 11 12
13 14 15 16

After assignment, m = 
 8 12 16  4
 5  6  7  8
 9 10 11 12
13 14 15 16
```



#### 向量的块操作

Eigen提供了一组专门为向量和一维数组的特殊情况设计的块操作：

| 块操作                               | 构建一个动态大小的块表达式 | 构建一个固定大小的块表达式 |
| :----------------------------------- | :------------------------- | :------------------------- |
| 包含前`n`个元素的块                  | vector.head(n);            | vector.head<n>();          |
| 包含后`n`个元素的块                  | vector.tail(n);            | vector.tail<n>();          |
| 包含从第 i 个元素开始的 n 个元素的块 | vector.segment(i,n);       | vector.segment<n>(i);      |

示例如下：

```c++
#include <Eigen/Dense>
#include <iostream>
 
using namespace std;
 
int main()
{
  Eigen::ArrayXf v(6);
  v << 1, 2, 3, 4, 5, 6;
  cout << "v.head(3) =" << endl << v.head(3) << endl << endl;
  cout << "v.tail<3>() = " << endl << v.tail<3>() << endl << endl;
  v.segment(1,4) *= 2;
  cout << "after 'v.segment(1,4) *= 2', v =" << endl << v << endl;
}
```

输出如下：

```
v.head(3) =
1
2
3

v.tail<3>() = 
4
5
6

after 'v.segment(1,4) *= 2', v =
 1
 4
 6
 8
10
 6
```



### 3.1.5 切片和索引

[英文原文链接](http://eigen.tuxfamily.org/dox/group__TutorialSlicingIndexing.html)

本文介绍了如何使用操作运算符`operator()`索引行和列的子集。该 API 在 Eigen 3.4 中引入。它支持 [block API](http://eigen.tuxfamily.org/dox/group__TutorialBlockOperations.html) 提供的所有功能。特别是，它支持切片，即获取一组行、列或元素，以及等间隔的从矩阵或者数组中提取元素。

#### 概述

所有上述操作都是通过`DenseBase::operator()(const RowIndices&, const ColIndices&)`来完成的，每一个参数可以是：

- 索引单行或列的整数，包括符号索引
- 符号`Eigen::all`表示按递增顺序排列的所有行或列
- 由 `Eigen::seq`,` Eigen::seqN`或者` Eigen::placeholders::lastN` 函数构造的[算数序列](http://eigen.tuxfamily.org/dox/classEigen_1_1ArithmeticSequence.html)
- 任意一维整数向量、数组，形式如Eigen `向量`、`数组`、`表达式`、`std::vector`、`std::array` 、 C的数组`int[N]`

更一般的，该函数可以接受任何有下列两个成员函数接口的对象

```c++
<integral type> operator[](<integral type>) const;
<integral type> size() const;
```

其中`<integral type>` 代表任何可以与`Eigen::index`兼容的整数，如`std::ptrdiff_t`



#### 基本的切片

通过`Eigen::seq`或`Eigen::seqN`函数，取矩阵或向量中均匀间隔的一组行、列或元素，其中`seq`代表算数序列。他们的用法如下：

| 方法                                                         | 描述                                        | 示例                                                         |
| :----------------------------------------------------------- | :------------------------------------------ | :----------------------------------------------------------- |
| [seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)(firstIdx,lastIdx) | 返回从`firstIdx` 到 `lastIdx`的整数序列     | [seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)(2,5) <=> {2,3,4,5} |
| [seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)(firstIdx,lastIdx,incr) | 同上，但是索引步长为incr                    | [seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)(2,8,2) <=> {2,4,6,8} |
| [seqN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a3a3c346d2a61d1e8e86e6fb4cf57fbda)(firstIdx,size) | 从`firstIdx`开始，索引步长1，总的个数为size | [seqN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a3a3c346d2a61d1e8e86e6fb4cf57fbda)(2,5) <=> {2,3,4,5,6} |
| [seqN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a3a3c346d2a61d1e8e86e6fb4cf57fbda)(firstIdx,size,incr) | 同上，索引步长为incr                        | [seqN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a3a3c346d2a61d1e8e86e6fb4cf57fbda)(2,3,3) <=> {2,5,8} |

一旦算术序列通过`operator()`传递给它，`firststidx`和`lasttidx`参数也可以用`Eigen::last`符号来定义，该符号表示矩阵/向量的最后一行、最后一列或元素的索引，使用如下：

| Intent                                                   | Code                                                         | Block-API equivalence            |
| :------------------------------------------------------- | :----------------------------------------------------------- | :------------------------------- |
| Bottom-left corner starting at row `i` with `n` columns  | A([seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)(i,[last](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga66661a473fe06e47e3fd5c591b6ffe8d)), [seqN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a3a3c346d2a61d1e8e86e6fb4cf57fbda)(0,n)) | A.bottomLeftCorner(A.rows()-i,n) |
| Block starting at `i`,j having `m` rows, and `n` columns | A([seqN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a3a3c346d2a61d1e8e86e6fb4cf57fbda)(i,m), [seqN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a3a3c346d2a61d1e8e86e6fb4cf57fbda)(i,n)) | A.block(i,j,m,n)                 |
| Block starting at `i0`,j0 and ending at `i1`,j1          | A([seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)(i0,i1), [seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)(j0,j1) | A.block(i0,j0,i1-i0+1,j1-j0+1)   |
| Even columns of A                                        | A([all](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga4abe6022fbef6cda264ef2947a2be1a9), [seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)(0,[last](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga66661a473fe06e47e3fd5c591b6ffe8d),2)) |                                  |
| First `n` odd rows A                                     | A([seqN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a3a3c346d2a61d1e8e86e6fb4cf57fbda)(1,n,2), [all](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga4abe6022fbef6cda264ef2947a2be1a9)) |                                  |
| The last past one column                                 | A([all](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga4abe6022fbef6cda264ef2947a2be1a9), [last](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga66661a473fe06e47e3fd5c591b6ffe8d)-1) | A.col(A.cols()-2)                |
| The middle row                                           | A([last](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga66661a473fe06e47e3fd5c591b6ffe8d)/2,[all](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga4abe6022fbef6cda264ef2947a2be1a9)) | A.row((A.rows()-1)/2)            |
| Last elements of v starting at i                         | v([seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)(i,[last](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga66661a473fe06e47e3fd5c591b6ffe8d))) | v.tail(v.size()-i)               |
| Last `n` elements of v                                   | v([seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)([last](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga66661a473fe06e47e3fd5c591b6ffe8d)+1-n,[last](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga66661a473fe06e47e3fd5c591b6ffe8d))) | v.tail(n)                        |

正如在上一个示例中看到的，引用最后n个元素(或行/列)编写起来有点麻烦。使用非默认增量时，这将变得更加棘手和容易出错。因此，Eigen提供了[Eigen::placeholders::lastN(size)](http://eigen.tuxfamily.org/dox/group__TutorialSlicingIndexing.html)和[Eigen::placeholders::lastN(size,incr) ](http://eigen.tuxfamily.org/dox/group__TutorialSlicingIndexing.html)函数来完成最后几个元素的提取，用法如下：

|                                                |                                                              |                          |
| :--------------------------------------------- | :----------------------------------------------------------- | :----------------------- |
| Intent                                         | Code                                                         | Block-API equivalence    |
| Last `n` elements of v                         | v(lastN(n))                                                  | v.tail(n)                |
| Bottom-right corner of A of size `m` times `n` | v(lastN(m), lastN(n))                                        | A.bottomRightCorner(m,n) |
| Bottom-right corner of A of size `m` times `n` | v(lastN(m), lastN(n))                                        | A.bottomRightCorner(m,n) |
| Last `n` columns taking 1 column over 3        | A([all](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga4abe6022fbef6cda264ef2947a2be1a9), lastN(n,3)) |                          |







## 四、扩展/自定义Eigen









## 五、常见话题

