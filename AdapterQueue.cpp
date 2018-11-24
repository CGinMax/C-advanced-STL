#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

void QueueCreate()
{
	//Ĭ������
	std::queue<std::string> que1;
	//vector����
	std::queue<std::string, std::vector<std::string>> que2;
	//list����
	std::queue<std::string, std::list<std::string>> que3;
	//��������
	std::queue<std::string> copy_que(que1);
	//=����������
	std::queue<std::string, std::list<std::string>> euqal_que = que3;


	//ʵ����queue
	std::vector<int> a_vec = { 2, 4, 5, 6, 21 };
	std::queue<int, std::vector<int>> init_queue(a_vec);

	std::list<std::string> a_list = { "CGinMax", "Elliot", "Hao", "Cooper" };
	std::queue<std::string, std::list<std::string>> init_list_queue(a_list);

	//move����
	std::queue<int, std::vector<int>> move_queue(std::move(init_queue));

	//move = ����
	std::queue<std::string, std::list<std::string>> move_equal_queue = std::move(init_list_queue);


}

void QueueOperator()
{
	std::queue<std::string> a_queue({ "CGinMax", "Hello", "Fei", "Cooper" });
	std::cout << "The front is " << a_queue.front() << std::endl;
	std::cout << "The back is " << a_queue.back() << std::endl;

	//push(const T& obj),���õײ�push_back
	a_queue.push(std::string("Nieo"));
	//push(T&& obj),���ƶ��ķ�ʽ�ں������Ԫ��
	a_queue.push("Park");

	//emplace
	a_queue.emplace(std::string("Hell"));

	//pop,ɾ����һ��Ԫ��
	a_queue.pop();
	//size
	std::cout << "The size is " << a_queue.size() << std::endl;
	
	//empty()
	if (!a_queue.empty())
	{
		std::cout << "The elements not empty" << std::endl;
		std::queue<std::string> more_word({ "C++", "Java", "kotlin" });
		a_queue.swap(more_word);
	}
	

}

int main()
{
	//QueueCreate();
	QueueOperator();

	return 0;
}