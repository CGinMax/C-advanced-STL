#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
#include <functional>

void ListTest()
{
	//������Ԫ�ص�list
	std::list<std::string> word;
	//��ʼ���б�
	std::list<double> numbers = { 11.2, 22.3, 33.4, 44.5, 55.6 };

	//20����Ԫ��
	std::list<std::string> words { 20 };
	//�������20����ͬ���ݵ�Ԫ��
	std::list<std::string> litter(20, std::string("HelloWorld"));
	//��������
	std::list<std::string> copy_litter{ litter };//��{}��Ϊ������

	//����������
	std::list<double> samples = { std::rbegin(numbers), std::rend(numbers) };
	std::copy(std::begin(samples), std::end(samples), std::ostream_iterator<double>(std::cout, " "));
	std::cout << std::endl;

	//size����Ԫ�ظ���
	auto iter1 = std::begin(samples);//listֻ��ͨ������������Ԫ�ط���
	for (size_t i = 0; i < samples.size(); i++)
	{
		std::cout << "The " << i << " elements is " << *iter1 << std::endl;
		*iter1++;
	}
	//resize������list��Ԫ�ظ���
	samples.resize(3);
	std::cout << "The samples change to " << samples.size() << " elements" << std::endl;


	//���Ԫ��
	//push_xxxx��������ֵ���ò���
	std::list<std::string> names = { "CGinMax", "Elliot", "ZZs", "Sugar" };
	names.push_front("Python");
	names.push_back("Hao");
	//emplace_xxxx��������ֵ���ò��������������Ʋ���������
	names.emplace_front("C++");
	names.emplace_back("Xin");
	std::copy(std::begin(names), std::end(names), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << std::endl;

	//list�м����Ԫ��
	std::list<std::string>::iterator iter2 = std::begin(names);
	/*auto iter2 = --std::end(names);*/
	names.insert(iter2, "Wyu");//�õ�����ָ������Ԫ�ص�λ��
	std::advance(iter2, 4);//��iterator.h����һ��������ָ��ĵ��������ڶ����������������ƶ���λ��
	names.insert(iter2, 2, "Giao");//�����ͬԪ�ز���
	std::copy(std::begin(names), std::end(names), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << std::endl;

	//����һ����������list
	std::array<std::string, 5> a_Arr = { "ycy", "uzi", "ming", "wxz", "faker" };
	names.insert(std::end(names), std::cbegin(a_Arr), std::cend(a_Arr));
	std::vector<std::string> a_Vec(5, "NB");
	names.insert(std::begin(names), std::cbegin(a_Vec), std::cend(a_Vec));
	std::copy(std::begin(names), std::end(names), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << std::endl;

	/************************************************************************/
	/* ����list�������ԣ�list���������������Ϊ��ָ���Ԫ��λ�÷����仯���ı�
	   ��Ԫ��ɾ��ʱ���������Ż�ʧЧ*/
	/************************************************************************/

	//�Ƴ�Ԫ��
	litter.clear();//�Ƴ�����Ԫ������,Ԫ�ظ�����Ϊ0
	std::cout << "The litter size is " << litter.size() << std::endl;

	samples.erase(std::begin(samples));//�Ƴ�ĳ��λ�õ�һ��Ԫ�أ�

	names.remove("faker");//�Ƴ�������һ�����ݵĲ���

	std::list<int> nums = { 2, 3, 4, 5, 6, 7, 8, 9 };
	//��һԪ������Ϊ�������������ͺ�Ԫ��ͬ���ͣ����ز���ֵ������ture��Ԫ�ػᱻ�Ƴ�
	nums.remove_if([](int n) {return n % 2 == 0; });//�����ǲ�������

	//unique�����ظ���Ԫ��ʡ��ȥ��
	names.unique();


}

void SortList()
{
	//sort����
	std::list<std::string> sortlist = { "CGinMax", "Hao", "Elliot", "Bob", "Cooper" };
	sortlist.sort();//�޲�sort�����б��е�Ԫ����������

	//greater�������Ƚ�T���Ͷ���ĺ�������greater��һ���࣬()�����صĲ�����
	sortlist.sort(std::greater<std::string>());//һ�����������lambda���ʽ��Ϊ����
	//lambda���ʽ����
	sortlist.sort([](const std::string& s1, const std::string& s2)
	{
		if (s1[0] == s2[0])
			return s1.length() < s2.length();
		else
			return s1 > s2;
	});

	//merge���ϲ�����list
	std::list<int> my_list = { -4, 1, 2, 5, 8 };
	std::list<int> you_list = { -1, 0, 4, 9, 16 };
	//ʹ��mergeʱ��Ԫ�ر����������
	my_list.merge(you_list);
	std::copy(std::begin(my_list), std::end(my_list), std::ostream_iterator<int>(std::cout, ", "));
	std::cout << std::endl;

	//splice����listԪ���ƶ�����һ�������� ָ��λ�õ�ǰ�棬����һ��Ԫ�أ����Ԫ�أ���������
	std::list<std::string> my_strings = { "C++", "Python", "Java", "Lua" };
	std::list<std::string> you_strings = { "CGinMax", "Elliot", "Simom", "Cooper" };
	//��һ��������Ŀ��λ�ã��ڶ���������Ԫ�ص���Դ�������������ǿ�ʼ����Ԫ��λ�õĵ����������ĸ������ǽ�������Ԫ�ص�λ��
	my_strings.splice(std::end(my_strings), you_strings, ++std::begin(you_strings), --std::end(you_strings));
	//���Ҫ���������������������ĸ�������ʡ��

}

void CreateList()
{
	//Ĭ�Ϲ���
	std::list<std::string> list1;
	//��ʼ���б���
	std::list<std::string> list2 = { "CGinMax", "Elliot", "Cooper" };
	//��������
	std::list<std::string> list3(list2);
	//=������
	std::list<std::string> list4 = list2;
	//move����
	std::list<std::string> list5(std::move(list3));
	//move =������
	std::list<std::string> list6 = std::move(list4);

	//n��Ԫ�ص�list
	std::list<double> l1(10);
	//n��Ԫ��list��ÿ��Ԫ��ֵһ��
	std::list<double> l2(10, 99.9);
	//��ĳ�������������ڵ�Ԫ�ع��� list
	std::list<double> l3(++std::begin(l2), --std::end(l2));
	//��ʼ���б���Ϊ���캯���Ĳ���
	std::list<double> l4({ 11.2, 22.3, 33.4, 44.5, 55.6 });

	//����list
	l4.~list();
}
/************************************************************************/
/* Ԫ�ش�С��������������һ��                                                 */
/************************************************************************/

void ElementOprator()
{
	std::list<double> l1;
	//10����ͬ��Ԫ�أ���ֵ��list
	l1.assign(10, 99.9);

	std::list<double> l2;
	//����Ԫ�ظ�ֵ��list
	l2.assign(++std::begin(l1), --std::end(l1));

	std::list<double> l3;
	//��ʼ���б���Ϊ����
	l3.assign({ 11.2, 22.3, 33.4, 44.5 });

	//swap����Ԫ��
	l1.swap(l3);
	std::swap(l1, l2);

	//front��back����ͷβԪ��
	std::cout << "List1 front element is " << l1.front() << std::endl;
	std::cout << "List1 back element is " << l1.back() << std::endl;

	std::list<int> emp_list;
	//std::cout << emp_list.front() << std::endl;//Runtime error
	if (!emp_list.empty())
	{
		std::cout << emp_list.back() << std::endl;//OK
	}

}

int main()
{ 
	//ListTest();
	//SortList();
	//CreateList();
	ElementOprator();

	return 0;
}