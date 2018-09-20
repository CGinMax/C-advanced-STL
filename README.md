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
    
## **3.把vector和string数据传给旧API**

因为vector跟数组在内存的存储上都是通过连续排布的，所以访问vector对象的第一个元素的地址，相当于访问该vector对象。因此我们可以用一个指向vector对象的第一个元素来表示指向整个vector对象，有

```
std::vector<int> v;
void doSomething(const int* pInt, size_t numInt);
doSomething(&v[0], v.size());
```

如果避免出现空vector对象，导致指针指向错误，则加个判断条件

```if(!v.empty()) { doSomething(&v[0],v.size()); }```

string对象利用旧API的方法
```
std::string s;
doSomething(const char* pString);
doSomething(s.c_str());
```

### **用C API初始化vector 等容器**
```
size_t InitContainer(char* pContainer, size_t containerSize)
std::vector<char> v();//创建一个vector
v.resize(InitContainer(&v[0], v.size()));//初始化v中的大小

//通过该方法初始化其他容器
std::string s(v.begin(), v.end());
std::deque<char> d(v.begin(), v.end());
std::list<char> l(v.begin(), v.end());
std::set<char> s(v.begin(), v.end());
```

## **4.使用swap技巧除去多余的容器容量**
通过利用临时变量在程序结束后被析构掉的特点，将临时变量做为交换swap对象

```
class Contestant{...};
std::vector<Contestant> contestants;
//临时变量调用拷贝构造，拷贝contestants中，它只需要为想要拷贝的元素分配所需要的内存。所以它的内存会比原先的contestants少。
std::vector<Contestant>(contestants).swap(contestants);//swap之后，减去了不必要的空间
```
