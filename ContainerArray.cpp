#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <array>
#include <iterator>
#include <numeric>

void test()
{
	std::array<double, 100> data{};//第一个参数传类型。第二个参数传数据个数，或size
	//std::array<int, 100> data {};//初始化为0

	//赋一部分的值
	std::array<int, 10> age = {11, 20, 30 ,5};

	//at()访问元素
	age.at(4) = age.at(1) + age.at(2);
	std::cout << "age[4] = " << age.at(4) << std::endl;

	if (age.empty())
	{
		std::cout << "The container has no elements.\n";

	}
	else
	{
		std::cout << "The container has " << age.size() << " elements.\n";
		//std::cout << "The container has no elements.\n";
	}

	//get<n>(const array)，返回第n个元素
	std::array<std::string, 5> name = { "CGinMax", "Elliot", "Hao", "Fei", "Edison" };
	std::cout << "I thought " << std::get<2>(name) << " god is DaShen.\n";
	std::cout << "I printing 3th elements " << std::get<4>(name) << std::endl;

	std::array<std::string, 5>name2 = { "CGinMax", "Elliot", "Hao", "Fei", "Edison" };
	if (name2 == name)//还支持< , >，没有&& , ||
	{
		std::cout << "Two arraies are the same.\n";
	}
	else if (name2 != name)
	{
		std::cout << "They are different!\n";
	}
	


	std::array<int, 10> values = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double sum = 0;
	for (auto&& value : values)//value做为右值，加双&&
	{
		sum += value;
		std::cout << "Sum = " << sum << std::endl;
	}

	/*
	std::array<std::string, 5>::iterator first = name.begin();
	std::array<std::string, 5>::iterator last = name.end();
	while (first != last)
	{
		std::cout << "The name array :" << name.at(*first) << " ";
		*first++;
	}
	*/
	//连续递增初始化,从第三个参数的值开始递增,需要包含numeric头文件。---迭代器iterator不行---
	std::array<double, 10> increment;
	std::iota(std::begin(increment), std::end(increment), 1);
	for (size_t i = 0; i < increment.size();i++)
	{
		std::cout << "递增:" << increment.at(i);
	}
	std::cout << std::endl;
	
	/************************************************************************/
	/* 用move，代替swap
	   原因：防止iterator，reference所指的对象不会跟着移动                         */
	/************************************************************************/
	std::array<int, 5> sm1 = { 1, 2, 3, 4, 5 }, sm2 = {};
	sm2 = std::move(sm1);
	std::cout << "After move, sm2 = ";
	for (size_t i = 0; i < sm2.size(); i++)
	{
		std::cout << sm2.at(i) << " ";
		if (i == 9)
			std::cout << std::endl;
	}
	

}

void createArray()
{
	//使用初始化列, 创建
	std::array<std::string, 5> str1 = { "CGinMax", "Elliot", "Hao", "Fei", "Edison" };
	
	//调用拷贝构造， 创建
	std::array<std::string, 5> str2(str1);

	//调用重载的=， 创建
	std::array<std::string, 5> str3 = str1;

	//调用move构造函数， 创建
	std::array<std::string, 5> moStr(std::move(str1));
	std::cout << "After move constructor :";
	for (size_t i = 0; i < moStr.size();i++)
	{
		std::cout << moStr.at(i) << " ";
		if (i == 4)
			std::cout << std::endl;
	}

	//调用move=， 创建
	std::array<std::string, 5> eqStr = std::move(str1);
	std::cout << "After move equal sign :";
	for (size_t i = 0; i < moStr.size();i++)
	{
	std::cout << moStr.at(i) << " ";
	if (i == 4)
	std::cout << std::endl;
	}


}

void ArrToCStyle()
{
	std::array<std::string, 3> str1 = { "Hello", "C++", "Python" };
	//从第一个元素开始，增加索引，等于这个索引所在的元素
	bool b = (&str1[2] == &str1[0] + 2);
	std::cout << "compare: " << b << std::endl;

	//利用data函数，得到首地址
	std::array<char, 50> cstr;
	strcpy(cstr.data(), "This is C string");
	printf("What program language is it belong? %s\n", cstr.data());
}


int main()
{
	ArrToCStyle();
	//createArray();
	//test();
	return 0;
}