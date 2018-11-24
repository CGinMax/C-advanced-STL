#include <iostream>
#include <forward_list>
#include <algorithm>
#include <utility>
#include <string>
#include <iterator>
#include <vector>

void Forward_listTest()
{
	//�����б�ʽ��list����һ��
	std::forward_list<std::string> forList1;
	std::forward_list<std::string> forList2 = { "CGinMax", "Elliot", "Hao" };
	std::forward_list<std::string> forList3(forList2);
	std::forward_list<std::string> forList4({ "C++", "Python", "Java", "Android" });
	//��������

	//forward_listû�л�ȡԪ�ش�С��size����iterator�е�distance
	std::forward_list<std::string> my_list1 = { "Wyu", "Tsing", "Xmu" };
	auto count = std::distance(std::begin(my_list1), std::end(my_list1));
	std::cout << count << std::endl;

	//forward_list��û��ָ����ĩԪ�ص��ض���������back,push_back,pop_back

	//�������ƶ�
	std::forward_list<int> age = { 12, 23, 34, 45, 56, 67 };
	auto iter1 = std::begin(age);
	std::cout << "The begin is " << *iter1 << std::endl;
	std::advance(iter1, 3);
	std::cout << "The 4 element is " << *iter1 << std::endl;


	//Ԫ��ƴ�ӡ�
	//����forward_list�ǵ���ģ�spelice��insertֻ�е����spelice_after, insert_after
	//�����Ԫ�ص��������˵�һ��Ԫ�����⣬����Ԫ�ض��޷���Ϊ����㣬before_begin, cbefore_begin
	std::forward_list<std::string> my_class = { "CGinMax", "Elliot", "Yu", "Bing" };
	std::forward_list<std::string> other_class = { "Fei", "Zhao", "Black" };

	//splice_after��ƴ�ӵ�������begin��ָ�������ĵڶ���Ԫ��
	my_class.splice_after(my_class.before_begin(), other_class, std::begin(other_class));
	std::copy(std::begin(my_class), std::end(my_class), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << std::endl;

	//һ��Ԫ�ؼ��У����˵�һ��Ԫ�أ�����Ԫ�ض�������
	std::forward_list<std::string> new_class = { "Cooper", "Hao", "Bulus", "Jane", "paper" };
	other_class.splice_after(other_class.cbefore_begin(), new_class, std::begin(new_class), std::end(new_class));
	std::copy(std::begin(new_class), std::end(new_class), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//��������������������Լ�����������
	std::forward_list<std::string> bad_class = { "Juss", "Mary", "Nieo", "Ku" };
	new_class.splice_after(new_class.cbefore_begin(), bad_class);

	new_class.insert_after(new_class.before_begin(), std::string("Dale"));
	new_class.insert_after(new_class.before_begin(), 2, std::string("Haoer"));
	new_class.insert_after(new_class.before_begin(), "Leaune");//��ֵ����
	std::vector<std::string> a_vec = { "Hello", "Nice", "Welcome" };
	new_class.insert_after(new_class.before_begin(), std::begin(a_vec), std::end(a_vec));

	//��listһ��
	//sort������
	//merge�����ź�����ƴ��
	//unique���Ƴ���ͬ��Ԫ��
	//remove���Ƴ��ض���Ԫ��

}

void ExpectionTest()
{
	std::forward_list<int> int_list = { 2, 31, 6, -4, 11, 28, 9 };
	std::forward_list<int> int_list2 = { 1, 2, 3, 4, 5 };

	try
	{
		int_list.merge(int_list2);
	}
	catch (std::forward_list<int> e)
	{
		std::cout << "You forward_list not sort" << std::endl;

	}
}

int main()
{
	ExpectionTest();
	//Forward_listTest();
	return 0;
}