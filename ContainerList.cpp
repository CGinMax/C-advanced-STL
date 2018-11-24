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
	//构造无元素的list
	std::list<std::string> word;
	//初始化列表
	std::list<double> numbers = { 11.2, 22.3, 33.4, 44.5, 55.6 };

	//20个空元素
	std::list<std::string> words { 20 };
	//构造具有20个相同内容的元素
	std::list<std::string> litter(20, std::string("HelloWorld"));
	//拷贝构造
	std::list<std::string> copy_litter{ litter };//用{}做为操作符

	//迭代器构造
	std::list<double> samples = { std::rbegin(numbers), std::rend(numbers) };
	std::copy(std::begin(samples), std::end(samples), std::ostream_iterator<double>(std::cout, " "));
	std::cout << std::endl;

	//size访问元素个数
	auto iter1 = std::begin(samples);//list只能通过迭代，进行元素访问
	for (size_t i = 0; i < samples.size(); i++)
	{
		std::cout << "The " << i << " elements is " << *iter1 << std::endl;
		*iter1++;
	}
	//resize，重置list的元素个数
	samples.resize(3);
	std::cout << "The samples change to " << samples.size() << " elements" << std::endl;


	//添加元素
	//push_xxxx，都是右值引用参数
	std::list<std::string> names = { "CGinMax", "Elliot", "ZZs", "Sugar" };
	names.push_front("Python");
	names.push_back("Hao");
	//emplace_xxxx，都是左值引用参数，减少了右移操作的运算
	names.emplace_front("C++");
	names.emplace_back("Xin");
	std::copy(std::begin(names), std::end(names), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << std::endl;

	//list中间插入元素
	std::list<std::string>::iterator iter2 = std::begin(names);
	/*auto iter2 = --std::end(names);*/
	names.insert(iter2, "Wyu");//用迭代器指定插入元素的位置
	std::advance(iter2, 4);//在iterator.h，第一个参数：指向的迭代器，第二个参数：迭代器移动的位置
	names.insert(iter2, 2, "Giao");//多个相同元素插入
	std::copy(std::begin(names), std::end(names), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << std::endl;

	//将另一个容器插入list
	std::array<std::string, 5> a_Arr = { "ycy", "uzi", "ming", "wxz", "faker" };
	names.insert(std::end(names), std::cbegin(a_Arr), std::cend(a_Arr));
	std::vector<std::string> a_Vec(5, "NB");
	names.insert(std::begin(names), std::cbegin(a_Vec), std::cend(a_Vec));
	std::copy(std::begin(names), std::end(names), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << std::endl;

	/************************************************************************/
	/* 由于list的特殊性，list对象迭代器不会因为所指向的元素位置发生变化而改变
	   当元素删除时，迭代器才会失效*/
	/************************************************************************/

	//移除元素
	litter.clear();//移除所有元素内容,元素个数变为0
	std::cout << "The litter size is " << litter.size() << std::endl;

	samples.erase(std::begin(samples));//移除某个位置的一个元素，

	names.remove("faker");//移除跟参数一致内容的参数

	std::list<int> nums = { 2, 3, 4, 5, 6, 7, 8, 9 };
	//用一元断言做为参数，参数类型和元素同类型，返回布尔值。返回ture的元素会被移除
	nums.remove_if([](int n) {return n % 2 == 0; });//可以是参数对象

	//unique，将重复的元素省略去掉
	names.unique();


}

void SortList()
{
	//sort排序
	std::list<std::string> sortlist = { "CGinMax", "Hao", "Elliot", "Bob", "Cooper" };
	sortlist.sort();//无参sort，将列表中的元素升序排序

	//greater，用来比较T类型对象的函数对象。greater是一个类，()是重载的操作符
	sortlist.sort(std::greater<std::string>());//一个函数对象或lambda表达式做为参数
	//lambda表达式方法
	sortlist.sort([](const std::string& s1, const std::string& s2)
	{
		if (s1[0] == s2[0])
			return s1.length() < s2.length();
		else
			return s1 > s2;
	});

	//merge，合并两个list
	std::list<int> my_list = { -4, 1, 2, 5, 8 };
	std::list<int> you_list = { -1, 0, 4, 9, 16 };
	//使用merge时，元素必须是升序的
	my_list.merge(you_list);
	std::copy(std::begin(my_list), std::end(my_list), std::ostream_iterator<int>(std::cout, ", "));
	std::cout << std::endl;

	//splice，将list元素移动到另一个容器的 指定位置的前面，可以一个元素，多个元素，整个容器
	std::list<std::string> my_strings = { "C++", "Python", "Java", "Lua" };
	std::list<std::string> you_strings = { "CGinMax", "Elliot", "Simom", "Cooper" };
	//第一个参数是目标位置，第二个参数是元素的来源，第三个参数是开始复制元素位置的迭代器，第四个参数是结束复制元素的位置
	my_strings.splice(std::end(my_strings), you_strings, ++std::begin(you_strings), --std::end(you_strings));
	//如果要复制整个容器，第三、四个参数可省略

}

void CreateList()
{
	//默认构造
	std::list<std::string> list1;
	//初始化列表构建
	std::list<std::string> list2 = { "CGinMax", "Elliot", "Cooper" };
	//拷贝构造
	std::list<std::string> list3(list2);
	//=操作符
	std::list<std::string> list4 = list2;
	//move构造
	std::list<std::string> list5(std::move(list3));
	//move =操作符
	std::list<std::string> list6 = std::move(list4);

	//n个元素的list
	std::list<double> l1(10);
	//n个元素list，每个元素值一致
	std::list<double> l2(10, 99.9);
	//用某个容器的区间内的元素构造 list
	std::list<double> l3(++std::begin(l2), --std::end(l2));
	//初始化列表做为构造函数的参数
	std::list<double> l4({ 11.2, 22.3, 33.4, 44.5, 55.6 });

	//析构list
	l4.~list();
}
/************************************************************************/
/* 元素大小操作跟其他容器一致                                                 */
/************************************************************************/

void ElementOprator()
{
	std::list<double> l1;
	//10个相同的元素，赋值给list
	l1.assign(10, 99.9);

	std::list<double> l2;
	//区间元素赋值给list
	l2.assign(++std::begin(l1), --std::end(l1));

	std::list<double> l3;
	//初始化列表做为参数
	l3.assign({ 11.2, 22.3, 33.4, 44.5 });

	//swap交换元素
	l1.swap(l3);
	std::swap(l1, l2);

	//front，back访问头尾元素
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