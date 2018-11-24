#include <iostream>
#include <vector>
#include <memory>
#include <string>

void ContainerPointer()
{
	//a_vector����������ָ��
	std::vector<std::unique_ptr<std::string>> a_vector;
	//make_unique�������ɶ����ָ�룬����������ָ��
	a_vector.push_back(std::make_unique<std::string>("CGinMax"));
	a_vector.push_back(std::make_unique<std::string>("CGinMax"));
	//ͨ��unique_pointer������Ԫ�ز��ܱ�������ͨ��moveʵ��ת��
}

void PointerTest()
{
	//ԭ��ָ��Ĵ���
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
	//for���������ַ
	for (auto& w : words)
		std::cout << w << " ";
	std::cout << std::endl;

	//�������������
	for (std::vector<std::string*>::iterator iter1 = words.begin(); iter1 != words.end(); ++iter1)
	{
		//iter1�����Ǹ�ָ�룬������Ҫͨ�������û�ȡ����ֵ
		std::cout << **iter1 << " ";
	}
	std::cout << std::endl;

	//ԭ��ָ�������
	//for (auto iter2 = words.begin(); iter2 != words.end(); ++iter2)
	//	words.erase(iter2);//Ԫ����Ȼ���������ڴ滹�ڣ��ᵼ��ָ���ڴ�й©
	//�������
	for (auto iter2 = words.begin(); iter2 != words.end();)
	{
		if (**iter2 == "Elliot")
		{
			//���ͷ��ڴ棬��ɾ��Ԫ��
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

	//ɾ��Ԫ��,����ָ����Զ��������������ͷ��ڴ�
	words.clear();
}

int main1()
{
	//ContainerPointer();
	SmartPointer();
	PointerTest();
	return 0;
}