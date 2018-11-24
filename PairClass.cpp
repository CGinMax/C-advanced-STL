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
	//Ĭ�Ϲ���
	std::pair<int, std::string> pa1;

	//�вι���
	std::pair<int, std::string> pa2(10, "CGinMax");

	//��������
	std::pair<int, std::string> pa3(pa2);

	//move����
	std::pair<int, std::string> pa4(std::move(pa3));

	//=����������
	std::pair<int, std::string> pa5 = pa4;//C++11����ʼ֧�ָ���ʾת��
	//move =
	std::pair<int, std::string> pa6 = std::move(pa5);//C++11����ʼ֧�ָ���ʾת��

	//pair��Ϊ��ֵ�и�ֵ
	std::vector<std::pair<int, std::string>> vec{ { 1, "CGinMax" }, { 2, "Elliot" } };

	//make_pair
	//������ʱpair����
	std::make_pair("Name", 21);

	f(std::make_pair("Address", 10));
	//��pair��ʼ���б���Ϊpair����
	f({ "Age", 11 });


	//�Զ���������Ϊģ�����
	//������ֻ��һ�� nonconstant cop���캯�� ʱ����C++11�ǲ�����ģ��ᱨ��
	//Ӧ�����Զ����������const copy����
	std::pair<C, int>my_pair;

}
std::pair<std::string, int> f(std::pair<std::string, int> p)
{
	return p;
}

void PairOperator()
{
	std::pair<std::string, int> a_pair("Age", 20);
	//��ȡ��һ�ڶ�Ԫ�صľ��䷽��
	std::cout << "The first element of a_pair is " << a_pair.first << std::endl;
	std::cout << "The second element of a_pair is " << a_pair.second;

	//C++11֮���ȡ��һ�ڶ�Ԫ�صķ���
	std::cout << "The first element of a_pair is " << std::get<0>(a_pair) << std::endl;
	std::cout << "The second element of a_pair is " << std::get<1>(a_pair) << std::endl;


	//�жϲ���
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

//ʵ��<<
//template<typename T1, typename T2>
//std::ostream& operator << (ostream& strm, const std::pair<T1, T2>& p)
//{
//	return strm << "[" << p.first << ", " << p.second << "]";
//}

void Tuple_Pair()
{
	std::pair<float, std::string> p(9.16, "̨��");
	//��tuple��ȡpairԪ�ظ���������
	std::cout << std::tuple_size<std::pair<float, std::string>>::value << std::endl;//2��Ԫ��
	
	std::tuple_element<1, std::pair<float, std::string>>::type str = "CGinMax";//string��������

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