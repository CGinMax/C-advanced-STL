#include <iostream>
#include <vector>
#include <memory>
#include <string>

void ContainerPointer()
{
	//a_vector对象有智能指针
	std::vector<std::unique_ptr<std::string>> a_vector;
	//make_unique可以生成对象和指针，并返回智能指针
	a_vector.push_back(std::make_unique<std::string>("CGinMax"));
	a_vector.push_back(std::make_unique<std::string>("CGinMax"));
	//通过unique_pointer创建的元素不能被拷贝，通过move实现转移
}

void PointerTest()
{
	//原生指针的创建
	std::vector<std::string*> words;
	std::string word;
	std::cout << "Enter you word by space, Ctrl+Z stop input.\n";
	while (true)
	{
		if ((std::cin >> word).eof())
		{
			std::cin.clear();
			break;
		}
		words.push_back(new std::string(word));
	}
	//for迭代输出地址
	for (auto& w : words)
		std::cout << w << " ";
	std::cout << std::endl;

	//迭代器迭代输出
	for (std::vector<std::string*>::iterator iter1 = words.begin(); iter1 != words.end(); ++iter1)
	{
		//iter1本身是个指针，所以需要通过解引用获取它的值
		std::cout << **iter1 << " ";
	}
	std::cout << std::endl;

	//原生指针的问题
	//for (auto iter2 = words.begin(); iter2 != words.end(); ++iter2)
	//	words.erase(iter2);//元素虽然消除，但内存还在，会导致指针内存泄漏
	//解决方法
	for (auto iter2 = words.begin(); iter2 != words.end();)
	{
		if (**iter2 == "Elliot")
		{
			//先释放内存，再删除元素
			delete *iter2;
			words.erase(iter2);
		}
		else
			++iter2;
	}
}

void SmartPointer()
{
	std::vector<std::shared_ptr<std::string>> words;
	std::string word;
	std::cout << "Enter you word by a space, click Ctrl+Z on next line to stop input.\n";
	while (true)
	{
		if ((std::cin >> word).eof())
		{
			std::cin.clear();
			break;
		}
		//Create smart pointer to string&
		words.push_back(std::make_shared<std::string>(word));
	}

	//删除元素,智能指针会自动调用析构函数释放内存
	words.clear();
}

int main1()
{
	//ContainerPointer();
	SmartPointer();
	PointerTest();
	return 0;
}