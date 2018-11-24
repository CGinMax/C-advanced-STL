#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <queue>

void PriorityCreate()
{
	//�����ȶ���ʱ���ȶ���һ���Ƚ϶���ĺ�������
	auto comp = [](const std::shared_ptr<std::string>& wp1, const std::shared_ptr<std::string>& wp2){ return *wp1 > *wp2; };

	//����һ������shared_ptr�����ȶ���
	std::priority_queue<std::shared_ptr<std::string>, std::vector<std::shared_ptr<std::string>>, decltype(comp)> words1{ comp };
	//��һ��ָ�����ⲿ������ʼ�����ָ��
	std::vector<std::shared_ptr<std::string>> init{ std::make_shared<std::string>("CGinMax"), std::make_shared<std::string>("Elliot"),
		std::make_shared<std::string>("Hao"), std::make_shared<std::string>("Cooper") };

	//decltype���ñ������ҳ����ʽ������
	std::priority_queue<std::shared_ptr<std::string>, std::vector<std::shared_ptr<std::string>>, decltype(comp)> words2(comp, init);
	//�÷���ֻ�ʺ�shared pointer

	//emplace, push Ԫ��
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