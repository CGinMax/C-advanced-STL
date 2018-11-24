#include <iostream>
#include <utility>
#include <tuple>
#include <functional>
#include <string>
#include <vector>
#include "printtuple.hpp"

void TupleClass()
{
	//tuple�����кܶ��Ԫ��
	std::tuple<std::string, int, float, double, char> t1;
	std::tuple<std::string, float, char> t2("Name", 21.2f, 'H');
	std::tuple<int, double, char, std::string> t3 = std::make_tuple(1, 3.14, 'G', "CGinMax");
	std::tuple<std::string, float, char> t4("Age", 9.17f, 'B');
	
	//��ȡԪ��
	std::cout << std::get<0>(t2) << std::endl;
	//��ͬtuple֮��Ԫ�ظ�ֵ
	std::get<2>(t2) = std::get<2>(t3);

	//�Ƚ�Ԫ��
	//Ԫ�ظ�������һ�����ſ��ԱȽ�
	if (t2 != t4)
	{
		std::cout << "Two tuple are not same!\n";
	}

	//���ܴ�����
	//int i;
	//std::get<i>(t2);

	std::tuple<int, std::string, char> tem(20, "7k7k", 'Q');
	int i;
	std::string str;
	char ch;
	//��tuple��ֵ��ȡ����
	std::make_tuple(std::ref(i), std::ref(str), std::ref(ch)) = tem;
	std::cout << "The tem(0) is " << std::get<0>(tem) << std::endl;
	//ͨ��tie����tuple
	std::tie(i, str, ch) = tem;
	std::cout << std::get<0>(tem) << std::endl;

	auto t5 = std::tie(std::ref(i), std::ref(str), std::ref(ch));
	std::cout << std::get<0>(t5) << std::endl;
	//std::cout << std::get<1>(t5) << std::endl;
	std::cout << std::get<2>(t5) << std::endl;

	//tuple��Ϊ��ֵ�У���Ҫͨ��make_tuple
	std::vector<std::tuple<int, double, std::string>> a_tuple{ std::make_tuple(1, 21.31, "CGinMax"), std::make_tuple(2, 31.21, "Elliot") };


	//Tuple��������
	//tuple_size
	std::cout << std::tuple_size<std::tuple<int, std::string, char>>::value << std::endl;

	//tuple_element��һ���������ǵ�i��Ԫ�ص����ͣ��ڶ���������tupleType
	std::tuple_element<1, std::tuple<int, std::string, char>>::type a_elem = std::string("Fuck");

	//�������tupleΪ1��tuple
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