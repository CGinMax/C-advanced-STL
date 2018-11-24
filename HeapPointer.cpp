#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <memory>

void HeapPointer()
{
	//����һ��heap
	std::vector<std::shared_ptr<std::string>> words{ std::make_shared<std::string>("One"), std::make_shared<std::string>("Two"), std::make_shared<std::string>("Three"),
		std::make_shared<std::string>("Four") };
	//������������һ��lambda���ʽ��������������Ƚ�
	std::make_heap(std::begin(words), std::end(words), [](const std::shared_ptr<std::string>& wp1, const std::shared_ptr<std::string>&wp2) { return *wp1 > *wp2; });
	//push_heap, pop_heap, is_heap, is_heap_until, sort_heap����Ҫ�бȽϵĺ�������
}

int main()
{
	HeapPointer();
	return 0;
}