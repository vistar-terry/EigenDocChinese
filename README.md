# EigenDocChinese

本项目基于Eigen3.4.90，对其[英文文档](https://eigen.tuxfamily.org/dox/index.html)进行了中文翻译，暂不包括对Reference和Class List的翻译。

项目链接：[https://github.com/vistar-terry/EigenDocChinese](https://github.com/vistar-terry/EigenDocChinese)

有翻译不对的地方或其他疑问，欢迎提[issues](https://github.com/vistar-terry/EigenDocChinese/issues)。



### 目录说明

1. EigenDocChinese：中文翻译文档
2. EigenDocEnglish：英文文档本地备份
3. Code：文档内示例代码（可根据中文文档内代码索引查找）



### 阅读说明

1. 由于中英文书面语习惯的差异，为了读起来通顺，未逐字逐句翻译，在不改变原有表达的基础上，有适当修改。

2. 对于英文文档表述不明确的地方，在中文文档中以引用说明的格式标注，如下：

> 这里是对英文原文的进一步说明
>
> 这里是对英文原文的进一步说明
>
> 这里是对英文原文的进一步说明

3. 代码索引说明

​		为了方便找到文档中对应的代码，添加了代码索引，如下：

```c++
// 代码索引 3-9-1-3
Matrix2i A = Matrix2i::Random();
cout << "Here are the coeffs of the 2x2 matrix A:\n";
for(auto x : A.reshaped())
  cout << x << " ";
cout << "\n";
```

代码索引共4位，第一位代表章节，第二位代表章节下面的小节，第三位代表该小节下的第几个文件（为了清晰有的小节下有多个文件），第四位代表该文件里的第几段代码。

示例 `3-9-1-3` 即第三章第9节第1个文件中第3段代码：

> .
> ├── 2.Getting-started
> │   ├── 1.A-simple-first-program.cpp
> │   ├── 2.Matrices-and-vectors.cpp
> │   ├── 3.Matrices-and-vectors.cpp
> │   ├── build
> │   └── CMakeLists.txt
> └── **3.Dense-matrix-and-array-manipulation**
>     ├── 8.Reshape
>     │   ├── 1.reshape.cpp
>     │   ├── 2.reshapeInPlace.cpp
>     │   ├── build
>     │   └── CMakeLists.txt
>     └── **9.STL-iterators-and-algorithms**
>         ├── **1.stl.cpp**
>         ├── build
>         └── CMakeLists.txt



