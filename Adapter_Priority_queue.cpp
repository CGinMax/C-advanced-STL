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
	//Ĭ�ϲ�������priority_queue
	std::priority_queue<std::string> a_proque;
	//�Զ���ײ�����
	std::priority_queue<std::string, std::vector<std::string>> a_vecPro;
	//�Զ���ײ������ͺ�������
	std::priority_queue<std::string, std::list<std::string>, std::greater<std::string>> my_priority_queue;

	//�޷�ʹ�ó�ʼ���б�
	//std::priority_queue<std::string> words ({ "CGinMax", "Cooper", "Neio" });
	std::string words[] = { "CGinMax", "Cooper", "neio", "Mark" };
	std::string last_words[] = { "C++", "Python", "Java", "Lua" };
	
	//����������,Ĭ��ģ�����
	std::priority_queue<std::string> words_que(std::begin(words), std::end(words));

	//������+�Զ���������
	std::vector<std::string> arg_vec = { "C++", "Python", "Java", "Lua" };
	std::vector<std::string> last_arg = { "CGinMax", "Cooper", "neio", "Mark" };
	//������캯�������������ԣ�����Ҫ�������ȶ��ж�����������һ�¡� ��ʲô���壿
	std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> words_fun_que(arg_vec.begin(), arg_vec.end());
	//�����ó��˵ײ����������������������Ϊ����Ĳ���
	//std::priority_queue<std::string, std::vector<std::string>, std::less<std::string>> four_arg_que(std::begin(words), std::end(words), std::less<std::string>(), last_words);
	std::priority_queue<std::string, std::vector<std::string>, std::less<std::string>> four_arg_que(std::begin(arg_vec), std::end(arg_vec), std::less<std::string>(), last_arg);

	//�Զ���ģ�����
	std::priority_queue<std::string, std::vector<std::string>, std::greater_equal<std::string>> my_words(std::begin(words), std::end(words));


	//��������
	std::priority_queue<std::string> copy_queue(words_que);
	//move����
	std::priority_queue<std::string> move_queue(copy_queue);
	//move = ����
	std::priority_queue<std::string> move_equal_queue = std::move(move_queue);

	//��ͬ������ֵ
	std::deque<int> a_deque { 10, 20, 30, 40, 50 };
	//��һ�������������������ڶ���������Ҫ��Ϊ��������ĵײ�����
	std::priority_queue<int, std::deque<int>> priority_deque (std::less<int>(), a_deque);

}

void Priority_queueOperator()
{
	std::priority_queue<std::string> stu_queue;
	//push����
	stu_queue.push(std::string("CGinMax"));
	stu_queue.push(std::string("Elliot"));
	stu_queue.push("Hao");

	stu_queue.emplace(std::string("Bari"));

	//��ȡ���ȵ�һ��Ԫ��
	std::cout << "The top element of priority_queue " << stu_queue.top() << std::endl;

	//pop��ɾ�����ȼ���ߵ�Ԫ��
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

	//��ȡĳ������Ԫ�ؼ򵥵Ĳ���
	std::priority_queue<std::string> tmp_queue(stu_queue);
	while (!tmp_queue.empty())
	{
		std::cout << tmp_queue.top() << ", ";
		tmp_queue.pop();

	}
	std::cout << std::endl;
	/************************************************************************/
	/* priority_queueû�бȽϲ�������ΪԪ���Զ�ͨ���������бȽ�
	*/
	/************************************************************************/
}

int main()
{ 
	Priority_queueOperator();
	//Priority_queueCreate();

	return 0;
}