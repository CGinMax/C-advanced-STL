#include <iostream>
#include <utility>
#include <tuple>
#include <functional>
#include <string>
#include <vector>
#include "printtuple.hpp"

void TupleClass()
{
	//tuple可以有很多个元素
	std::tuple<std::string, int, float, double, char> t1;
	std::tuple<std::string, float, char> t2("Name", 21.2f, 'H');
	std::tuple<int, double, char, std::string> t3 = std::make_tuple(1, 3.14, 'G', "CGinMax");
	std::tuple<std::string, float, char> t4("Age", 9.17f, 'B');
	
	//获取元素
	std::cout << std::get<0>(t2) << std::endl;
	//不同tuple之间元素赋值
	std::get<2>(t2) = std::get<2>(t3);

	//比较元素
	//元素个数必须一样，才可以比较
	if (t2 != t4)
	{
		std::cout << "Two tuple are not same!\n";
	}

	//不能传索引
	//int i;
	//std::get<i>(t2);

	std::tuple<int, std::string, char> tem(20, "7k7k", 'Q');
	int i;
	std::string str;
	char ch;
	//将tuple的值提取出来
	std::make_tuple(std::ref(i), std::ref(str), std::ref(ch)) = tem;
	std::cout << "The tem(0) is " << std::get<0>(tem) << std::endl;
	//通过tie创建tuple
	std::tie(i, str, ch) = tem;
	std::cout << std::get<0>(tem) << std::endl;

	auto t5 = std::tie(std::ref(i), std::ref(str), std::ref(ch));
	std::cout << std::get<0>(t5) << std::endl;
	//std::cout << std::get<1>(t5) << std::endl;
	std::cout << std::get<2>(t5) << std::endl;

	//tuple做为初值列，需要通过make_tuple
	std::vector<std::tuple<int, double, std::string>> a_tuple{ std::make_tuple(1, 21.31, "CGinMax"), std::make_tuple(2, 31.21, "Elliot") };


	//Tuple其他特性
	//tuple_size
	std::cout << std::tuple_size<std::tuple<int, std::string, char>>::value << std::endl;

	//tuple_element第一个参数，是第i个元素的类型，第二个参数是tupleType
	std::tuple_element<1, std::tuple<int, std::string, char>>::type a_elem = std::string("Fuck");

	//串联多个tuple为1个tuple
	auto catTuple = std::tuple_cat(std::make_tuple(11, 3.14, "Hello"), std::tie(i));
}

void TupleIO()
{
	std::tuple<int, float, std::string> t(99, 10.22, "NiHao");
	std::cout << "The tuple t is " << t << std::endl;

}

int main()
{
	//TupleClass();
	TupleIO();
	return 0;
}