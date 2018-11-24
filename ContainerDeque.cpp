#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <algorithm>

void DeqTest()
{
	std::deque<int> a_deque;
	//指定元素个数
	std::deque<int> my_deque(10);
	//初始化列表deque
	std::deque<std::string> words = { "CGinMax", "Hello", "TNT", "infinety" };
	std::copy(std::begin(words), std::end(words), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//迭代器初始化
	std::deque<std::string> words_part = { std::rbegin(words).base(), std::rend(words).base() };
	std::copy(std::begin(words_part), std::end(words_part), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//访问元素
	std::cout << words.at(2) << std::endl;

	//front , back, size, resize与vector一致
	std::cout << "front element is :" << words.front() << std::endl;
	std::cout << "back element is :" << words.back() << std::endl;
	std::cout << "words size is :" << words.size() << std::endl;
	words.resize(5);
	std::cout << "After resize, words size is:" << words.size() << std::endl;

	//替换deque内容
	std::deque<std::string> str1 = { "one", "two", "three", "four" };
	//最好用std::string定义。
	//原因：如果是个"",会被认为似乎initializer_list<const char*> ,而不是initializer_list<string>
	auto init_list = { std::string("seven"), std::string("eight"), std::string("night") };
	str1.assign(init_list);
	std::copy(std::begin(str1), std::end(str1), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//迭代器assign
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
	//初始化列表做为元素参数
	auto iter2 = str1.insert(std::end(str1), { std::string("SwU"), std::string("Tsing") });
	
	//变量做为参数
	std::string more[] = { "Highter", "Grader", "Medium" };
	auto iter3 = str1.insert(std::begin(str1), std::begin(more), std::end(more));
	//第3个插入之后，iter1，iter2发生改变，运行时会出错
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