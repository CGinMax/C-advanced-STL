#include <iostream>
#include <string>
#include <functional>


//lambda��Ϊʵ�Σ������template

template<typename T>
void realRef(T lamRef)
{
	//auto tem = lamRef("yes");

	std::cout << "template������lambda���ʽ��Ϊʵ�� " << lamRef("yes") << std::endl;
}
void test()
{
	//�����﷨
	[](double value){ return value * 2; };//����ֵΪvoid
	//ָ������ֵ����
	auto its = [](int m_code) ->std::string { return std::to_string(m_code); };
	//�ַ���תint,std::int stoi(const wstring& _Str, size_t *_Idx = 0, int _Base = 10)
	//��׼��atoi(str.c_str())
	std::cout << "int tranform to string " << its(1000) << std::endl;

	auto lam = [] (int age) { return age; };
	std::cout << "My age is " << lam(20) << std::endl;

	//lambda��Ϊʵ�Σ������template
	//template<typename T>
	realRef([](std::string str) { return str; });

	//��function����������functional
	std::function<std::string(std::string)> fun_lamb = [](const std::string str) { return str; };
	//����funtion�����б�����û��const����lambda�����б��У�����Ӱ�죿
	std::cout << "functional lambda:" << fun_lamb("It is ture!") << std::endl;

	//[�����б�] (�����б�) "mutable"��ѡ -> type{ return }
	/*�������ݣ�
		=�����ʾ�����ܷ������еı���������privated����proteced�������ܸı�ñ�����ֵ�����Ǽ�mutable�� �ٷ����ͣ�����ֵ�ķ�ʽ�������з�շ�Χ�ڵ��Զ�������
		&�����б��������÷�ʽʹ�ã�ʡȥmutable
		����ĳ���ض��ı�����&var���ڱ�����ǰ��&����
		*/
}


int main()
{
	test();
	return 0;
}