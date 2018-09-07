# C++-advanced-STL
## C++11和STL
## **1.constexpr用法**

    constexpr表示在“编译时求值”，主要对常量表达式进行说明，作用是允许把数据放在内存中。
    例如：
```
const int rad = 10; //一个const常量
int var = 20; //普通的变量
fun1(const int rad); //计算以rad为半径的圆的面积
fun2(int var); //参数不是常量的函数
    
constexpr int const_square = fun1(rad); //等号的右边是常量表达式，正确
constexpr int square = fun2(var); //错误，fun(var)不是常量表达式
constexpr int nonconst_square = fun1(var); //错误，var不是常量，fun1就不是常量表达式
    
```
    
    函数中只有一条return语句，也可以当成常量表达式
` constexpr double square(double r) { return x * x; } `
    
    
