#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>

void DeqTest()
{
	std::deque<int> a_deque;
	//ָ��Ԫ�ظ���
	std::deque<int> my_deque(10);
	//��ʼ���б�deque
	std::deque<std::string> words = { "CGinMax", "Hello", "TNT", "infinety" };
	std::copy(std::begin(words), std::end(words), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//��������ʼ��
	std::deque<std::string> words_part = { std::rbegin(words).base(), std::rend(words).base() };
	std::copy(std::begin(words_part), std::end(words_part), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//����Ԫ��
	std::cout << words.at(2) << std::endl;

	//front , back, size, resize��vectorһ��
	std::cout << "front element is :" << words.front() << std::endl;
	std::cout << "back element is :" << words.back() << std::endl;
	std::cout << "words size is :" << words.size() << std::endl;
	words.resize(5);
	std::cout << "After resize, words size is:" << words.size() << std::endl;

	//�滻deque����
	std::deque<std::string> str1 = { "one", "two", "three", "four" };
	//�����std::string���塣
	//ԭ������Ǹ�"",�ᱻ��Ϊ�ƺ�initializer_list<const char*> ,������initializer_list<string>
	auto init_list = { std::string("seven"), std::string("eight"), std::string("night") };
	str1.assign(init_list);
	std::copy(std::begin(str1), std::end(str1), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//������assign
	std::string more[] = { "Highter", "Grader", "Medium" };
	std::deque<std::string> str2 = { "University", "Word" };
	str2.assign(std::begin(more) + 1, std::end(more));
	
}

void PushElements()
{
	std::deque<std::string> str1 = { "wyu", "xmu", "zsu", "bdu" };
	//push_back
	str1.push_back(std::string("MIT"));

	//push_front
	str1.push_front(std::string("DaYe"));
	for (size_t index = 0; index < str1.size();index++)
	{
		std::cout << str1.at(index) << " ";
	}
	std::cout << std::endl;

	//insert
	auto iter1 = str1.insert(++std::begin(str1), "HKU");
	std::cout << str1.at(1) << std::endl;
	//��ʼ���б���ΪԪ�ز���
	auto iter2 = str1.insert(std::end(str1), { std::string("SwU"), std::string("Tsing") });
	
	//������Ϊ����
	std::string more[] = { "Highter", "Grader", "Medium" };
	auto iter3 = str1.insert(std::begin(str1), std::begin(more), std::end(more));
	//��3������֮��iter1��iter2�����ı䣬����ʱ�����
	/*std::cout << "iter1 = " << *iter1 << std::endl;
	std::cout << "iter2 = " << *iter2 << std::endl;
	std::cout << "iter3 = " << *iter3 << std::endl;*/
	std::copy(std::begin(str1), std::end(str1), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;


}


int main()
{
	PushElements();
	//DeqTest();
	return 0;
}