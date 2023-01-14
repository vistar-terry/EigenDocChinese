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

>Eigen源码下载链接：[https://gitlab.com/libeigen/eigen/-/releases](https://gitlab.com/libeigen/eigen/-/releases)，选择你需要的版本下载。
>
>解压后，将其中的Eigen文件夹放到你的头文件目录，即可在你的工程中使用Eigen。

### 第一个简单的程序

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

### 3.1 稠密矩阵与数组操作

#### 3.1.1 矩阵类

在Eigen中，所有矩阵和向量都是[Matrix](http://eigen.tuxfamily.org/dox/classEigen_1_1Matrix.html)模板类的对象。向量只是行数或者列数为`1`的特殊矩阵。

```c++
template<typename Scalar_, int Rows_, int Cols_, int Options_, int MaxRows_, int MaxCols_>
class Eigen::Matrix< Scalar_, Rows_, Cols_, Options_, MaxRows_, MaxCols_ >
```

##### Matrix前三个模板参数

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

##### 向量

如上所述，在Eigen中，向量是一种特殊的矩阵，把只有`1`列的矩阵叫做`列向量`，通常把列向量称为`向量`。行数为`1`的矩阵叫做`行向量`。

例如，`Vector3f`是有3个`float`元素的列向量。在Eigen中这样定义：

```c++
typedef Matrix<float, 3, 1> Vector3f;
```

也提供了行向量的类型定义，如下表示有2个`int`元素的行向量：

```c++
typedef Matrix<int, 1, 2> RowVector2i;
```

##### 动态的特殊值

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

##### 构造函数

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













# 访问系数

在Eigen中主要的系数访问方法是重载括号运算符。对于矩阵，行索引总是优先传递的。对于向量，只需要传递一个索引。索引从0开始。下面例子很清楚的解释了这一点。

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

Here is the matrix m:
  3  -1
2.5 1.5
Here is the vector v:
4
3
```

请注意m(index)不只是只能用在向量，对普通的矩阵同样可以使用，在系数行列式中点访问是基于索引的。但是，索引取决于矩阵的存储顺序。在Eigen中，矩阵默认是列优先进行存储，但是这也可以改变，详情请查阅 [Storage orders](http://eigen.tuxfamily.org/dox/group__TopicStorageOrders.html)。

运算符**[ ]**同样也被重载用于基于索引的向量访问，但是请记住，C++只允许远算符**[ ]**最多传入1个参数。我们限制了运算符**[ ]**只能在vector上的使用，因为C++语言的笨拙，会把matrix[i,j]编译成matrix[j]。

# 逗号初始化

矩阵和向量系数可以使用逗号进行初始化。如下：

```C++
Matrix3f m;
m << 1, 2, 3,
     4, 5, 6,
     7, 8, 9;
std::cout << m;

Output:
1 2 3
4 5 6
7 8 9
```

# 重置大小

矩阵当前的大小可以通过函数rows(),cols(),size()来返回。这些方法分别返回函数、列数、系数的数量。对于动态大小的矩阵，可以使用函数resize()来重新调整大小。

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

Output:
The matrix m is of size 4x3
It has 12 coefficients
The vector v is of size 5
As a matrix, v is of size 5x1
```

如果矩阵的大小没有改变，那么resize()方法不做任何操作。否则，该返回会破坏当前的矩阵，矩阵的系数可能会改变。如果你不想改变矩阵的系数，可以使用resize()的变体[conservativeResize()](http://eigen.tuxfamily.org/dox/classEigen_1_1PlainObjectBase.html#a712c25be1652e5a64a00f28c8ed11462)。

所有的这些方法都可以对固定大小的矩阵使用。当然，你不能对一个固定大小的矩阵使用resize。试图对一个固定大小的矩阵进行改变大小会触发断言。但是下列的代码是合法的。

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
Output:
The matrix m is of size 4x4
```

# 赋值和重置大小

赋值是使用操作符=来完成复制的操作。Eigen将会自动调整等式左边的大小以便与和等式右边的大小做一个匹配，例如：

```C++
MatrixXf a(2,2);
std::cout << "a is of size " << a.rows() << "x" << a.cols() << std::endl;
MatrixXf b(3,3);
a = b;
std::cout << "a is now of size " << a.rows() << "x" << a.cols() << std::endl;
Output:
a is of size 2x2
a is now of size 3x3
```

当然如果，等式左边的大小是固定大小，重置大小是不被允许的。

如果你不想自动重置大小的操作发生，你可以关闭它，详情请参考[this page](http://eigen.tuxfamily.org/dox/TopicResizing.html)。

# 固定和动态大小的比较

如何选择使用固定大小还是动态大小呢？对于非常小的矩阵应该选择固定大小，当面对大矩阵的时候应该使用动态大小。对于小的大小，特别是对于大小小于16时，使用固定大小效率更高，因为它允许Eigen避免动态分配内存和展开循环。一个固定大小Eigen矩阵仅仅是一个纯数组。例如，`Matrix4f mymatrix`等同于`float mymatrix[16]`，所以这没有没有运行的成本。而动态矩阵需要在堆中分配空间，例如：`MatrixXf mymatrix(rows,columns)`等价于`float *mymatrix = new float[rows*columns]`，除此之外，MatrixXf对象还存储了其行数和列数。

使用固定大小的限制就是在要求你在编译的时候就知道大小，而且对于大的矩阵，例如大于32的矩阵，使用固定大小的矩阵带来的优势可以忽略不计。更糟糕的是，试图使用固定大小的矩阵创建一个非常大的矩阵可能会导致栈溢出，因为Eigen使用分配一个很大的栈空间来存储这个局部变量。最后，看情况，如果使用动态大小，Eigen可以更加积极的去向量化操作，具体请查看 [Vectorization](http://eigen.tuxfamily.org/dox/TopicVectorization.html)。

# 可选择的其他模板参数

在开始的时候，我们提及Matrix类有6个模板参数，但是，目前我们只讨论了前三个，剩下的三个参数是可供选择的。下面是完整的模板参数：

```C++
Matrix<typename Scalar,
       int RowsAtCompileTime,
       int ColsAtCompileTime,
       int Options = 0,
       int MaxRowsAtCompileTime = RowsAtCompileTime,
       int MaxColsAtCompileTime = ColsAtCompileTime>
```

- Options 是一个位域。这里，我们只讨论一个位RowMajor。它指定了矩阵是按照行优先进行存储的。默认情况下，存储顺序是按照列存储的。例如```Matrix<float, 3, 3, RowMajor>```是指一个行优先3*3矩阵。
- MaxRowsAtCompileTime 和 MaxColsAtCompileTime 是矩阵大小的上界，这让在编译前不知道矩阵的具体大小，就可以分配最大多少的内存，例如，```Matrix<float, Dynamic, Dynamic, 0, 3, 4>``` 会在编译的时候就使用一个大小为12个float的纯数组，而不需要动态分配内存。

# 常用的类型

- MatrixNt **<=>** Matrix<type, N, N>. **例如** Matrix<int, Dynamic, Dynamic>.
- MatrixXNt  **<=>** Matrix<type, Dynamic, N>.**例如**Matrix<int, Dynamic, 3>.
- MatrixNXt **<=>** Matrix<type, N, Dynamic>. **例如** Matrix<d, 4, Dynamic>.
- VectorNt  **<=>** Matrix<type, N, 1>. **例如** Vector2f for Matrix<float, 2, 1>.
- RowVectorNt  **<=>** Matrix<type, 1, N>.  **例如** Matrix<double, 1, 3>.

上述：

- **N**代表2、3、4或者X
- **t**代表任何一个i(int)、f(float)、d(double)、cf(complex<float>)、cd(complex<double>)。事实上，typedefs只定义了5种类型，但是这并不意味着，他们仅仅支持标量。例如，标准整形是支持的。

































## 四、扩展/自定义Eigen









## 五、常见话题

