# C++-advanced-STL
## C++11和STL
## **1.value_type意义及用法**
value_type表示容器里的数据的数据类型，例如：
```
template <typename T>
typename T::value_type sum(const T& args)//容器类型为T
{
	typename T::value_type total = 0;//将total定义为跟容器数据同样的数据类型
	for (const auto& e : args)//迭代args容器里的每个元素
	{
		total += e;
	}
	return total;//输出1+2+3+4+5+6=21
}
int main()
{ 
    //定义一个vector容器
	std::vector<int> a_vec = { 1, 2, 3, 4, 5, 6 };
    //函数模板参数为vector<int>，而sum的返回值类型和sum里定义的total变量的数据类型，都为int(相当于vector<int>::int total)
	std::cout << "It is " << sum<std::vector<int>>(a_vec) << std::endl;
	return 0;
}
```

如果不加上value_type，则函数返回值类型和total变量类型，都会是vector<int>，没有该数据类型。
    
总结：当模板函数的返回值类型是模板容器类型的下一级时，利用T::value_type可以实现完整的效果。

## **2.constexpr用法**

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
    
