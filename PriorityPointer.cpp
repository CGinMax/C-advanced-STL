#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <queue>

void PriorityCreate()
{
	//用优先队列时，先定义一个比较对象的函数对象
	auto comp = [](const std::shared_ptr<std::string>& wp1, const std::shared_ptr<std::string>& wp2){ return *wp1 > *wp2; };

	//创建一个带有shared_ptr的优先队列
	std::priority_queue<std::shared_ptr<std::string>, std::vector<std::shared_ptr<std::string>>, decltype(comp)> words1{ comp };
	//用一个指定的外部容器初始化存放指针
	std::vector<std::shared_ptr<std::string>> init{ std::make_shared<std::string>("CGinMax"), std::make_shared<std::string>("Elliot"),
		std::make_shared<std::string>("Hao"), std::make_shared<std::string>("Cooper") };

	//decltype，让编译器找出表达式的类型
	std::priority_queue<std::shared_ptr<std::string>, std::vector<std::shared_ptr<std::string>>, decltype(comp)> words2(comp, init);
	//该方法只适合shared pointer

	//emplace, push 元素
	words1.emplace(new std::string("one"));
	words1.emplace(new std::string("two"));

	words2.push(std::make_shared<std::string>("Luca"));
	words2.push(std::make_shared<std::string>("Jane"));

}

int main3()
{

	PriorityCreate();

	return 0;
}