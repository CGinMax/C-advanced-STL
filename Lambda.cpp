#include <iostream>
#include <string>
#include <functional>


//lambda作为实参，需借助template

template<typename T>
void realRef(T lamRef)
{
	//auto tem = lamRef("yes");

	std::cout << "template方法将lambda表达式做为实参 " << lamRef("yes") << std::endl;
}
void test()
{
	//基础语法
	[](double value){ return value * 2; };//返回值为void
	//指定返回值类型
	auto its = [](int m_code) ->std::string { return std::to_string(m_code); };
	//字符串转int,std::int stoi(const wstring& _Str, size_t *_Idx = 0, int _Base = 10)
	//标准库atoi(str.c_str())
	std::cout << "int tranform to string " << its(1000) << std::endl;

	auto lam = [] (int age) { return age; };
	std::cout << "My age is " << lam(20) << std::endl;

	//lambda作为实参，需借助template
	//template<typename T>
	realRef([](std::string str) { return str; });

	//用function方法，包含functional
	std::function<std::string(std::string)> fun_lamb = [](const std::string str) { return str; };
	//问题funtion参数列表里面没有const，而lambda参数列表有，但不影响？
	std::cout << "functional lambda:" << fun_lamb("It is ture!") << std::endl;

	//[捕获列表] (参数列表) "mutable"可选 -> type{ return }
	/*捕获内容：
		=，表达示里面能访问所有的变量，不论privated还是proteced，但不能改变该变量的值，除非加mutable。 官方解释：能以值的方式访问所有封闭范围内的自动变量，
		&，所有变量以引用方式使用，省去mutable
		捕获某个特定的变量：&var，在变量名前加&即可
		*/
}


int main()
{
	test();
	return 0;
}