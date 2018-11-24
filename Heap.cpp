#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <functional>

void HeapCreate()
{
	//heapĬ�ϵ�������� < ������һ���󶨶�
	std::vector<int> numbers = { 1, 3, 2, 6, 9, 4, 2, 3, 5, 7 };
	std::make_heap(std::begin(numbers), std::end(numbers));
	
	//ʹ�ö��Դ����ѣ�������priority_queue
	std::make_heap(std::begin(numbers), std::end(numbers), std::greater<int>());
}

void HeapOperate()
{
	//��push����
	std::vector<double> num = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
	//��make_heap
	std::make_heap(std::begin(num), std::end(num));
	//��push
	num.push_back(3.14159);
	std::push_heap(std::begin(num), std::end(num));

	//����������Ե�heap
	std::vector<double> pr_num = { 6.7, 4.4, 9.1, 21.0, 2, 3.2 };
	std::make_heap(std::begin(pr_num), std::end(pr_num), std::greater_equal<double>());
	pr_num.push_back(99.9);
	std::push_heap(std::begin(pr_num), std::end(pr_num), std::greater_equal<double>());

	//��pop����
	//�Ƚ���pop_heap����push_heap�෴
	std::pop_heap(std::begin(num), std::end(num));//pop_heap��ԭ���Ƚ�Ԫ���Ƶ��ѵ�����棬��ͨ��pop_back��������ɾ��Ԫ��
	//��pop_back()
	num.pop_back();

	//���ж��Ե�heap
	std::pop_heap(std::begin(pr_num), std::end(pr_num), std::greater_equal<double>());
	pr_num.pop_back();

	//�ж������Ƿ�Ϊ��
	if (!is_heap(std::begin(num), std::end(num), std::less<>()/*Ĭ����less*/))
	{
		std::cout << "Bulid a heap succefuly.\n";
	}
	else
	{
		std::cout << "Error.\n";
	}
	//�������ж�
	if (!is_heap(std::begin(pr_num), std::end(pr_num), std::greater_equal<>()))
	{
		std::cout << "Not empty heap!\n";
	}


	//is_heap_until������һ��ָ���ڶ��ڵ�Ԫ��
	std::vector<int> my_nums = { 10, 22, 13, 4, 15, 80, 36, 45, 2 };
	std::make_heap(std::begin(my_nums), std::end(my_nums));
	std::pop_heap(std::begin(my_nums), std::end(my_nums));
	//��ȡ80
	auto iter1 = std::is_heap_until(std::begin(my_nums), std::end(my_nums));
	//std::_Is_heap_until()
	//�����������ж����ڶ��У��Ӷ�����һ��ָ��end��iterator
	if (iter1 != std::end(my_nums))
		std::cout << "numbers is a heap up to " << *iter1 << std::endl;

	sort_heap(std::begin(my_nums), std::end(my_nums));//С����
}


int main()
{
	HeapCreate();
	return 0;
}