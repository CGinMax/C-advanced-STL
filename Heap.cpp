#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <functional>

void HeapCreate()
{
	//heap默认的运算符是 < ，生成一个大定堆
	std::vector<int> numbers = { 1, 3, 2, 6, 9, 4, 2, 3, 5, 7 };
	std::make_heap(std::begin(numbers), std::end(numbers));
	
	//使用断言创建堆，类似于priority_queue
	std::make_heap(std::begin(numbers), std::end(numbers), std::greater<int>());
}

void HeapOperate()
{
	//堆push操作
	std::vector<double> num = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
	//先make_heap
	std::make_heap(std::begin(num), std::end(num));
	//再push
	num.push_back(3.14159);
	std::push_heap(std::begin(num), std::end(num));

	//带有排序断言的heap
	std::vector<double> pr_num = { 6.7, 4.4, 9.1, 21.0, 2, 3.2 };
	std::make_heap(std::begin(pr_num), std::end(pr_num), std::greater_equal<double>());
	pr_num.push_back(99.9);
	std::push_heap(std::begin(pr_num), std::end(pr_num), std::greater_equal<double>());

	//堆pop操作
	//先进行pop_heap，跟push_heap相反
	std::pop_heap(std::begin(num), std::end(num));//pop_heap的原理：先将元素移到堆的最后面，再通过pop_back，才真正删除元素
	//再pop_back()
	num.pop_back();

	//带有断言的heap
	std::pop_heap(std::begin(pr_num), std::end(pr_num), std::greater_equal<double>());
	pr_num.pop_back();

	//判断序列是否为堆
	if (!is_heap(std::begin(num), std::end(num), std::less<>()/*默认是less*/))
	{
		std::cout << "Bulid a heap succefuly.\n";
	}
	else
	{
		std::cout << "Error.\n";
	}
	//带断言判断
	if (!is_heap(std::begin(pr_num), std::end(pr_num), std::greater_equal<>()))
	{
		std::cout << "Not empty heap!\n";
	}


	//is_heap_until，返回一个指向不在堆内的元素
	std::vector<int> my_nums = { 10, 22, 13, 4, 15, 80, 36, 45, 2 };
	std::make_heap(std::begin(my_nums), std::end(my_nums));
	std::pop_heap(std::begin(my_nums), std::end(my_nums));
	//获取80
	auto iter1 = std::is_heap_until(std::begin(my_nums), std::end(my_nums));
	//std::_Is_heap_until()
	//避免整个序列都不在堆中，从而返回一个指向end的iterator
	if (iter1 != std::end(my_nums))
		std::cout << "numbers is a heap up to " << *iter1 << std::endl;

	sort_heap(std::begin(my_nums), std::end(my_nums));//小顶堆
}


int main()
{
	HeapCreate();
	return 0;
}