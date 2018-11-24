#include <iostream>
#include <forward_list>
#include <algorithm>
#include <utility>
#include <string>
#include <iterator>
#include <vector>

void Forward_listTest()
{
	//构造列表方式跟list容器一致
	std::forward_list<std::string> forList1;
	std::forward_list<std::string> forList2 = { "CGinMax", "Elliot", "Hao" };
	std::forward_list<std::string> forList3(forList2);
	std::forward_list<std::string> forList4({ "C++", "Python", "Java", "Android" });
	//。。。。

	//forward_list没有获取元素大小的size。用iterator中的distance
	std::forward_list<std::string> my_list1 = { "Wyu", "Tsing", "Xmu" };
	auto count = std::distance(std::begin(my_list1), std::end(my_list1));
	std::cout << count << std::endl;

	//forward_list，没有指向最末元素的特定函数，如back,push_back,pop_back

	//迭代器移动
	std::forward_list<int> age = { 12, 23, 34, 45, 56, 67 };
	auto iter1 = std::begin(age);
	std::cout << "The begin is " << *iter1 << std::endl;
	std::advance(iter1, 3);
	std::cout << "The 4 element is " << *iter1 << std::endl;


	//元素拼接。
	//由于forward_list是单向的，spelice和insert只有单向的spelice_after, insert_after
	//被添加元素的容器除了第一个元素以外，其他元素都无法做为插入点，before_begin, cbefore_begin
	std::forward_list<std::string> my_class = { "CGinMax", "Elliot", "Yu", "Bing" };
	std::forward_list<std::string> other_class = { "Fei", "Zhao", "Black" };

	//splice_after，拼接的容器的begin是指向容器的第二个元素
	my_class.splice_after(my_class.before_begin(), other_class, std::begin(other_class));
	std::copy(std::begin(my_class), std::end(my_class), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << std::endl;

	//一段元素剪切，除了第一个元素，其他元素都被剪切
	std::forward_list<std::string> new_class = { "Cooper", "Hao", "Bulus", "Jane", "paper" };
	other_class.splice_after(other_class.cbefore_begin(), new_class, std::begin(new_class), std::end(new_class));
	std::copy(std::begin(new_class), std::end(new_class), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//不加最后两个参数，可以剪切整个容器
	std::forward_list<std::string> bad_class = { "Juss", "Mary", "Nieo", "Ku" };
	new_class.splice_after(new_class.cbefore_begin(), bad_class);

	new_class.insert_after(new_class.before_begin(), std::string("Dale"));
	new_class.insert_after(new_class.before_begin(), 2, std::string("Haoer"));
	new_class.insert_after(new_class.before_begin(), "Leaune");//右值参数
	std::vector<std::string> a_vec = { "Hello", "Nice", "Welcome" };
	new_class.insert_after(new_class.before_begin(), std::begin(a_vec), std::end(a_vec));

	//跟list一致
	//sort，排序
	//merge，先排好序，在拼接
	//unique，移除相同的元素
	//remove，移除特定的元素

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