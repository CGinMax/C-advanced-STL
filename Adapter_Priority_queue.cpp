#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <functional>
#include <queue>

void Priority_queueCreate()
{
	//默认参数创建priority_queue
	std::priority_queue<std::string> a_proque;
	//自定义底层容器
	std::priority_queue<std::string, std::vector<std::string>> a_vecPro;
	//自定义底层容器和函数对象
	std::priority_queue<std::string, std::list<std::string>, std::greater<std::string>> my_priority_queue;

	//无法使用初始化列表
	//std::priority_queue<std::string> words ({ "CGinMax", "Cooper", "Neio" });
	std::string words[] = { "CGinMax", "Cooper", "neio", "Mark" };
	std::string last_words[] = { "C++", "Python", "Java", "Lua" };
	
	//迭代器创建,默认模板参数
	std::priority_queue<std::string> words_que(std::begin(words), std::end(words));

	//迭代器+自定义排序函数
	std::vector<std::string> arg_vec = { "C++", "Python", "Java", "Lua" };
	std::vector<std::string> last_arg = { "CGinMax", "Cooper", "neio", "Mark" };
	//如果构造函数里加上排序断言，则需要跟该优先队列定义的排序断言一致。 有什么意义？
	std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> words_fun_que(arg_vec.begin(), arg_vec.end());
	//不能用除了底层容器外的其他类型数组做为构造的参数
	//std::priority_queue<std::string, std::vector<std::string>, std::less<std::string>> four_arg_que(std::begin(words), std::end(words), std::less<std::string>(), last_words);
	std::priority_queue<std::string, std::vector<std::string>, std::less<std::string>> four_arg_que(std::begin(arg_vec), std::end(arg_vec), std::less<std::string>(), last_arg);

	//自定义模板参数
	std::priority_queue<std::string, std::vector<std::string>, std::greater_equal<std::string>> my_words(std::begin(words), std::end(words));


	//拷贝构造
	std::priority_queue<std::string> copy_queue(words_que);
	//move构造
	std::priority_queue<std::string> move_queue(copy_queue);
	//move = 构造
	std::priority_queue<std::string> move_equal_queue = std::move(move_queue);

	//相同容器赋值
	std::deque<int> a_deque { 10, 20, 30, 40, 50 };
	//第一个参数传入排序函数，第二个参数是要做为拷贝对象的底层容器
	std::priority_queue<int, std::deque<int>> priority_deque (std::less<int>(), a_deque);

}

void Priority_queueOperator()
{
	std::priority_queue<std::string> stu_queue;
	//push函数
	stu_queue.push(std::string("CGinMax"));
	stu_queue.push(std::string("Elliot"));
	stu_queue.push("Hao");

	stu_queue.emplace(std::string("Bari"));

	//获取优先第一个元素
	std::cout << "The top element of priority_queue " << stu_queue.top() << std::endl;

	//pop，删除优先级最高的元素
	stu_queue.push("Mary");
	stu_queue.pop();
	std::cout << "The top element of priority_queue " << stu_queue.top() << std::endl;

	//size
	std::cout << "The priority_queue have " << stu_queue.size() << " elements " << std::endl;

	if (!stu_queue.empty())
	{
		std::cout << "The priority_queue not empty" << std::endl;
		std::string name[] = { "Hui", "Sheldon", "Happy" };
		std::priority_queue<std::string> tch_queue(std::begin(name), std::end(name));
		stu_queue.swap(tch_queue);
	}

	//获取某个容器元素简单的操作
	std::priority_queue<std::string> tmp_queue(stu_queue);
	while (!tmp_queue.empty())
	{
		std::cout << tmp_queue.top() << ", ";
		tmp_queue.pop();

	}
	std::cout << std::endl;
	/************************************************************************/
	/* priority_queue没有比较操作，因为元素自动通过函数进行比较
	*/
	/************************************************************************/
}

int main()
{ 
	Priority_queueOperator();
	//Priority_queueCreate();

	return 0;
}