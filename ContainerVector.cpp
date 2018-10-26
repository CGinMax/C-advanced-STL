#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

void VectorTest()
{
	//����10��Ԫ�ص��ڴ棬��û��Ԫ��
	std::vector<int> v;
	v.reserve(10);
	std::cout << "V elements size :" << v.size() << std::endl;
	std::cout << "v elements capacity: " << v.capacity() << std::endl;
	for (size_t index = 0; index < v.capacity();index++)
	{
		v.push_back(index);
	}
	std::cout << "After assign, v.size :" << v.size() << std::endl;
	//������������£�����һ��Ԫ��
	v.push_back(11);
	std::cout << "After push a element in back, v.size :" << v.size() << std::endl;//size������1
	std::cout << "After push a element in back, v.capacity :" << v.capacity() << std::endl;//capacity������5

	//����5��Ԫ�ء�Ԫ��Ĭ�ϳ�ʼֵΪ0
	std::vector<std::string> vs1(5);
	std::vector<std::string> vs2(5, "CGinMax");//ÿ��Ԫ�ض���CGinMax

	//��������ʼ
	std::vector<std::string> vs3 { std::begin(vs2), std::end(vs2) };
	std::cout << "vs3.at(2) : " << vs3.at(2) << std::endl;
	//�ƶ���������ʼ,Ԫ�ص��ڴ������͸������ڣ���ֵ��move����
	std::vector<std::string> vs4{ std::make_move_iterator(std::begin(vs2)), std::make_move_iterator(std::end(vs2)) };
	std::cout << "vs4.at(0) : " << vs4.at(0) << std::endl;
	std::cout << "vs2 has gone? " << vs2.size() << " size, " << vs2.capacity() << " capacity"<< std::endl;
	std::cout << "vs2.at(0) : " << vs2.at(0) << std::endl;

	//resize�� Parameters��the vector size you want to reset, assign a inital value to new elements(default is 0)
	std::vector<int> values = { 1, 2, 3 };
	values.resize(5);
	values.resize(10, 100);//last five elements is 100
	values.resize(8, 90);//����ı�ԭ���趨�ĳ�ֵ
	std::copy(std::begin(values), std::end(values), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	//std::cout << "values.at(7) :" << values.at(7) << std::endl;



	//copy�㷨���е�����ʹ��
	std::vector<double> data = { 15.9, 41.7, 20.5, 33.4, 26.8 };
	std::cout << "ÿ�����������ͬ �ո� ������ ��Ctrl+Z ����:";
	//std::back_inserter -> back_insert_iterator
	//std::copy(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(), std::back_inserter(data));
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<double>(std::cout, " "));

	//make_move_iterator
	std::vector<double> data1{ std::make_move_iterator(std::begin(data)), std::make_move_iterator(std::end(data)) };
	std::copy(std::begin(data1), std::end(data1), std::ostream_iterator<double>(std::cout, " "));
	std::cout << std::endl;
	//std::vector<double> data1;
	//data1 = { std::make_move_iterator(std::begin(data)), std::make_move_iterator(std::end(data)) };
}

void PushElement()
{
	//push_back,����һ��Ԫ�ؾͷ���һ���ڴ棬����size��capacityͬʱ��1
	std::vector<std::string> m_vec;
	m_vec.push_back("CGinMax");
	std::cout << "size :" << m_vec.size() << std::endl;
	std::cout << "capacity :" << m_vec.capacity() << std::endl;
	m_vec.push_back("Elliot");
	m_vec.push_back("Hao");
	m_vec.push_back("Fuck");
	std::cout << "size :" << m_vec.size() << std::endl;
	std::cout << "capacity :" << m_vec.capacity() << std::endl;

	//emplace_back
	m_vec.emplace_back("emplace element");
	m_vec.emplace_back("More elements", 5, 8);//���ַ����ĵ�5+1��Ԫ�ؿ�ʼ����ȡ8���ַ���Ϊ�ַ�������
	std::copy(std::begin(m_vec), std::end(m_vec), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//emplace���õ�����ָ��λ�ò��룬������ָ��Ԫ�ص�ǰ��壬�������������
	std::vector<std::string>a_str = { "people", "dog" };
	auto iter = a_str.emplace(std::begin(a_str), "AI");//���ص�һ��Ԫ�صĵ�����
	a_str.emplace(++iter, "Ghost");
	std::copy(std::begin(a_str), std::end(a_str), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//insert �����������ز����Ԫ��λ��
	std::vector<std::string>number = { "one", "three", "four" };
	auto iter1 = number.insert(++std::begin(number), "two");
	std::cout << "the place of iter element��" << *iter1 << std::endl;

	//insert��������
	std::string more[] = { "five", "six", "seven" };
	iter1 = number.insert(--std::end(number), std::begin(more), std::end(more));//��֧�ַ��������
	//iter1 = number.insert(std::rbegin(number).base(), std::begin(more), std::end(more));//rbegin().base�ѷ��������ת��Ϊ��׼������
	std::copy(std::begin(number), std::end(number), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
	//�����ͬ���ݲ���,�ڶ�������Ϊ�������
	number.insert(std::cend(number)-1, 3, "error");

	//�Գ�ʼ���б���Ϊ����
	number.insert(std::end(number), { std::string{ "twelve" }, std::string{ "thirteen" } });
	std::copy(std::begin(number), std::end(number), std::ostream_iterator<std::string>(std::cout, " "));


}

void DelVec()
{
	//clearɾ������Ԫ��
	std::vector<int> data1(100, 99);
	data1.clear();

	//pop_backɾ��β����һ��Ԫ��
	std::vector<int> data2(100, 100);
	data2.pop_back();

	//shrink_to_fitȥ�����������
	std::vector<int> data3(1000, 200);
	data3.clear();
	data3.shrink_to_fit();//������Ҳ����֮ʧЧ

	//erase,ɾ��һ������Ԫ�أ�����Ϊ��������ͬ������ֵҲ��һ��������
	std::vector<std::string> str1 = { "Hello", "���", "Yes", "�õ�" };
	auto iter1 = str1.erase(std::begin(str1) + 3);
	str1.emplace_back("�õ�");
	iter1 = str1.erase(std::begin(str1), std::begin(str1) + 2);

	//remove �Ƴ�ָ�����ݵ�Ԫ�أ������algorithmͷ�ļ�
	std::vector<std::string> str2 = { "shanwei", "shenzhen", "guangzhou", "jianmen", "zhuhai" };
	auto iter2 = std::move(std::begin(str2), std::end(str2), "shanwei");
	//size��capacity�����ֲ���
	//����û�б�ɾ����֪ʶ�����и����ݵ�Ԫ���Ƶ����棬����һ����vector�����һ����ЧԪ�ص���һ��Ԫ�ص�ַ
}

void CreateVec()
{
	//Default Constructor
	std::vector<std::string>v1;
	//initlist����ʼ���б�ΪԪ�س�ֵ
	std::vector<std::string> v2 = { "CGinMax", "Hao", "Xian", "Xin" };
	std::vector<std::string> v22({ "NB", "Fuck", "Shit", "Yashi" });
	//Copy Construcot
	std::vector<std::string> v3(v2);
	//Equal operator
	std::vector<std::string> v4 = v3;
	//Move Constructor
	std::vector<std::string> v5(std::move(v4));
	//Equal Move Constructor
	std::vector<std::string> v6 = std::move(v5);

	//����һ����СΪn��vector
	std::vector<double> d1(100);
	//10��Ԫ�ص�vecto��ֵ��Ϊ49.1
	std::vector<double> d2(10, 49.1);
	//��������Ϊ��ʼ���б�
	std::vector<double> d3(std::begin(d2), std::end(d2));
}

void VecToCStyle()
{
	//��Array������C-Style Arrayһ��
}

//vector<bool>Ԫ�ض��Ƕ�bit���в���
void VecBool()
{
	std::vector<bool> b1(5, true);
	//flip��������boolԪ��ȡ���࣬����ÿ��bit����
	b1.flip();
	//�ض�Ԫ��ȡ����
	b1[2].flip();
	//��ֵ
	b1[1] = false;


}

int main()
{
	CreateVec();
	//DelVec();
	//PushElement();
	//VectorTest();
	return 0;
}