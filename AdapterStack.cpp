#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include "My_Stack.hpp"
#include <exception>


void StackClassTest()
{
	try
	{
		//hppp namespace 下的newStack
		hpp::newStack<int> st;
		//用来被push进newStack
		std::vector<int> a_vec = { 1, 2, 3, 4 };

		for (size_t i = 0; i < a_vec.size(); i ++)
		{
			st.push(a_vec.at(i));
		}

		std::cout << st.pop() << " ";
		std::cout << st.pop() << " ";
		std::cout << std::endl;

		std::cout << "Top element " << st.top() << std::endl;

		st.push(5);
		std::cout << st.pop() << " ";
		std::cout << st.pop() << " ";
		std::cout << st.pop() << std::endl;
		std::cout << st.pop() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception :" << e.what() << std::endl;
	}
}

void StackCreate()
{
	//默认容器deque的stack
	std::stack<std::string> default_stack;
	//vector做为容器
	std::stack<std::string, std::vector<std::string>> vec_stack;
	//list做为容器
	std::stack<std::string, std::list<std::string>> list_stack;

	//无法在stack用初始化列表构造
	//std::stack<std::string, std::list<std::string>> con_stack{ "Hello", "World", "Fuck" };
	
	//通过先定义一个容器，用容器做为副本，进行赋值
	std::vector<int> a_vec = { 1, 2, 3, 4, 5, 6 };
	std::stack<int, std::vector<int>> my_stack(a_vec);

	//stack拷贝构造
	std::stack<int, std::vector<int>> copy_stack(my_stack);
	//=操作符，构造
	std::stack<int, std::vector<int>> equ_stack = my_stack;

	//move拷贝构造
	std::stack<int, std::vector<int>> move_stack(std::move(equ_stack));
	//被move做为参数的stack，会被全部移走
	if (!equ_stack.empty())
	{
		std::cout << "After move, the equ_stack not empty" << std::endl;
	}
	else
	{
		std::cout << "The fucking stack must be shit" << std::endl;
	}
	//move = 操作符
	std::stack<int, std::vector<int>> move_equ_stack = std::move(move_stack);

}

void StackOperator()
{
	std::vector<std::string> a_vec = { "CGinMax", "Hao", "Elliot", "Xin", "Cooper" };
	std::stack<std::string, std::vector<std::string>> my_stack(a_vec);
	//获取栈顶元素
	std::cout << "The top of my_stack is " << my_stack.top() << std::endl;
	//压栈,调用左值的push_back
	my_stack.push(std::string("Shale"));
	//压栈，调用右值的push_back
	my_stack.push("Sun");
	//弹栈，
	my_stack.pop();
	//获取栈元素
	my_stack.size();
	//判断是否为空
	if (!my_stack.empty())
	{
		std::cout << "The stack have " << my_stack.size() << " elements" << std::endl;
	}
	//
	my_stack.emplace(std::string("Halo"));
	std::cout << "After emplace, the last element is " << my_stack.top() << std::endl;

	//stack自带的swap，交换的两个stack元素的类型必须一致
	std::vector<std::string> other_vec = { "C++", "Python", "Java", "Lua", "Go", "Basic", "C#" };
	std::stack<std::string, std::vector<std::string>> other_stack(other_vec);
	my_stack.swap(other_stack);
	if (my_stack > other_stack)
	{
		std::cout << "my_stack > other_stack" << std::endl;
	}
	else
	{
		std::cout << "other_stack > my_stack" << std::endl;
	}


	std::vector<std::string> move_vec = { "ABC", "CDS", "SOS", "CCJ" };
	std::stack<std::string, std::vector<std::string>> move_stack(move_vec);



}

int main()
{
	StackClassTest();
	//StackOperator();
	//StackCreate();

	return 0;
}