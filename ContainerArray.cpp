#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <array>
#include <iterator>
#include <numeric>

void test()
{
	std::array<double, 100> data{};//��һ�����������͡��ڶ������������ݸ�������size
	//std::array<int, 100> data {};//��ʼ��Ϊ0

	//��һ���ֵ�ֵ
	std::array<int, 10> age = {11, 20, 30 ,5};

	//at()����Ԫ��
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

	//get<n>(const array)�����ص�n��Ԫ��
	std::array<std::string, 5> name = { "CGinMax", "Elliot", "Hao", "Fei", "Edison" };
	std::cout << "I thought " << std::get<2>(name) << " god is DaShen.\n";
	std::cout << "I printing 3th elements " << std::get<4>(name) << std::endl;

	std::array<std::string, 5>name2 = { "CGinMax", "Elliot", "Hao", "Fei", "Edison" };
	if (name2 == name)//��֧��< , >��û��&& , ||
	{
		std::cout << "Two arraies are the same.\n";
	}
	else if (name2 != name)
	{
		std::cout << "They are different!\n";
	}
	


	std::array<int, 10> values = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double sum = 0;
	for (auto&& value : values)//value��Ϊ��ֵ����˫&&
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
	//����������ʼ��,�ӵ�����������ֵ��ʼ����,��Ҫ����numericͷ�ļ���---������iterator����---
	std::array<double, 10> increment;
	std::iota(std::begin(increment), std::end(increment), 1);
	for (size_t i = 0; i < increment.size();i++)
	{
		std::cout << "����:" << increment.at(i);
	}
	std::cout << std::endl;
	
	/************************************************************************/
	/* ��move������swap
	   ԭ�򣺷�ֹiterator��reference��ָ�Ķ��󲻻�����ƶ�                         */
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
	//ʹ�ó�ʼ����, ����
	std::array<std::string, 5> str1 = { "CGinMax", "Elliot", "Hao", "Fei", "Edison" };
	
	//���ÿ������죬 ����
	std::array<std::string, 5> str2(str1);

	//�������ص�=�� ����
	std::array<std::string, 5> str3 = str1;

	//����move���캯���� ����
	std::array<std::string, 5> moStr(std::move(str1));
	std::cout << "After move constructor :";
	for (size_t i = 0; i < moStr.size();i++)
	{
		std::cout << moStr.at(i) << " ";
		if (i == 4)
			std::cout << std::endl;
	}

	//����move=�� ����
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
	//�ӵ�һ��Ԫ�ؿ�ʼ��������������������������ڵ�Ԫ��
	bool b = (&str1[2] == &str1[0] + 2);
	std::cout << "compare: " << b << std::endl;

	//����data�������õ��׵�ַ
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