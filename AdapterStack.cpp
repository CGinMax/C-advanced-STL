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
		//hppp namespace �µ�newStack
		hpp::newStack<int> st;
		//������push��newStack
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
	//Ĭ������deque��stack
	std::stack<std::string> default_stack;
	//vector��Ϊ����
	std::stack<std::string, std::vector<std::string>> vec_stack;
	//list��Ϊ����
	std::stack<std::string, std::list<std::string>> list_stack;

	//�޷���stack�ó�ʼ���б���
	//std::stack<std::string, std::list<std::string>> con_stack{ "Hello", "World", "Fuck" };
	
	//ͨ���ȶ���һ����������������Ϊ���������и�ֵ
	std::vector<int> a_vec = { 1, 2, 3, 4, 5, 6 };
	std::stack<int, std::vector<int>> my_stack(a_vec);

	//stack��������
	std::stack<int, std::vector<int>> copy_stack(my_stack);
	//=������������
	std::stack<int, std::vector<int>> equ_stack = my_stack;

	//move��������
	std::stack<int, std::vector<int>> move_stack(std::move(equ_stack));
	//��move��Ϊ������stack���ᱻȫ������
	if (!equ_stack.empty())
	{
		std::cout << "After move, the equ_stack not empty" << std::endl;
	}
	else
	{
		std::cout << "The fucking stack must be shit" << std::endl;
	}
	//move = ������
	std::stack<int, std::vector<int>> move_equ_stack = std::move(move_stack);

}

void StackOperator()
{
	std::vector<std::string> a_vec = { "CGinMax", "Hao", "Elliot", "Xin", "Cooper" };
	std::stack<std::string, std::vector<std::string>> my_stack(a_vec);
	//��ȡջ��Ԫ��
	std::cout << "The top of my_stack is " << my_stack.top() << std::endl;
	//ѹջ,������ֵ��push_back
	my_stack.push(std::string("Shale"));
	//ѹջ��������ֵ��push_back
	my_stack.push("Sun");
	//��ջ��
	my_stack.pop();
	//��ȡջԪ��
	my_stack.size();
	//�ж��Ƿ�Ϊ��
	if (!my_stack.empty())
	{
		std::cout << "The stack have " << my_stack.size() << " elements" << std::endl;
	}
	//
	my_stack.emplace(std::string("Halo"));
	std::cout << "After emplace, the last element is " << my_stack.top() << std::endl;

	//stack�Դ���swap������������stackԪ�ص����ͱ���һ��
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