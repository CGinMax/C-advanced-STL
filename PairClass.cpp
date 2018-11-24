#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <algorithm>
#include <vector>
#include <functional>
#include <exception>

class C
{
public:
	C() {};
	C(C& obj);
};

void PairCreate()
{
	//默认构造
	std::pair<int, std::string> pa1;

	//有参构造
	std::pair<int, std::string> pa2(10, "CGinMax");

	//拷贝构造
	std::pair<int, std::string> pa3(pa2);

	//move构造
	std::pair<int, std::string> pa4(std::move(pa3));

	//=操作符构造
	std::pair<int, std::string> pa5 = pa4;//C++11，开始支持该隐示转换
	//move =
	std::pair<int, std::string> pa6 = std::move(pa5);//C++11，开始支持该隐示转换

	//pair做为初值列赋值
	std::vector<std::pair<int, std::string>> vec{ { 1, "CGinMax" }, { 2, "Elliot" } };

	//make_pair
	//创建临时pair对象
	std::make_pair("Name", 21);

	f(std::make_pair("Address", 10));
	//用pair初始化列表做为pair参数
	f({ "Age", 11 });


	//自定义类型做为模板参数
	//当该类只有一个 nonconstant cop构造函数 时，在C++11是不允许的，会报错
	//应该在自定义类中添加const copy构造
	std::pair<C, int>my_pair;

}
std::pair<std::string, int> f(std::pair<std::string, int> p)
{
	return p;
}

void PairOperator()
{
	std::pair<std::string, int> a_pair("Age", 20);
	//获取第一第二元素的经典方法
	std::cout << "The first element of a_pair is " << a_pair.first << std::endl;
	std::cout << "The second element of a_pair is " << a_pair.second;

	//C++11之后获取第一第二元素的方法
	std::cout << "The first element of a_pair is " << std::get<0>(a_pair) << std::endl;
	std::cout << "The second element of a_pair is " << std::get<1>(a_pair) << std::endl;


	//判断操作
	std::pair<std::string, int> his_pair("Age", 30);
	
	try
	{
		if (a_pair == his_pair)
		{
			std::cout << "You enter the same on.\n";
		}
		else if(a_pair > his_pair)
		{
			throw "a_pair > his_pair.\n";
		}
		else if (a_pair < his_pair)
		{
			throw "a_pair < his_pair.\n";
		}
		else if (a_pair >= his_pair)
		{
			throw "a_pair >= his_pair.\n";
		}
		else if (a_pair <= his_pair)
		{
			throw "a_pair <= his_pair.\n";
		}
		else
		{
			throw "You enter is not same.\n";
		}

	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}


	//swap
	a_pair.swap(his_pair);
}

//实现<<
//template<typename T1, typename T2>
//std::ostream& operator << (ostream& strm, const std::pair<T1, T2>& p)
//{
//	return strm << "[" << p.first << ", " << p.second << "]";
//}

void Tuple_Pair()
{
	std::pair<float, std::string> p(9.16, "台风");
	//用tuple获取pair元素个数和类型
	std::cout << std::tuple_size<std::pair<float, std::string>>::value << std::endl;//2个元素
	
	std::tuple_element<1, std::pair<float, std::string>>::type str = "CGinMax";//string变量类型

	std::pair<char, char> p = std::make_pair('a', 'b');
	char c, d;
	std::tie(c, d) = p;
	std::cout << c << std::endl;
}

int main()
{
	//PairCreate();
	//PairOperator();
	Tuple_Pair();

	return 0;
}