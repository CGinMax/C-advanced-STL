#include <iostream>
#include <memory>
#include <string>
void sharedPtr()
{
	//shared_ptr�Ĵ���
	std::shared_ptr<double> pdata{ new double{ 999.0 } };
	std::cout << *pdata << std::endl;
	//ͨ���������޸�shared_ptr��ֵ
	/**pdata = 23.42;
	std::cout << *pdata << std::endl;*/
	//std::shared_ptr<double> pdata2;
	//pdata2 = pdata;//����һ��pdataָ���pdata2

	//����Ч�ʵ�make_shared����shared_ptr
	auto pdatas = std::make_shared<double>(32.45);
	std::cout << "pdatas:" << *pdatas << std::endl;

	//get������ȡԭ��ָ��
	auto pvalues = pdatas.get();
	std::cout << "Pvalues:" << *pvalues << std::endl;

	//����shared_ptr,����ָ�븳ֵΪnullptr���������ü������Զ���1
	auto pname = std::make_shared<std::string>("CGinMax");
	//pname = nullptr;

	//Ҳ������reset����
	pname.reset(new std::string{ "Elliot" });
}

void CompareCheck()
{
	//������ıȽ�������Ƚ�����shared_ptr�ĵ�ֵַ
	auto pA = std::make_shared<std::string>("my Wife");
	auto pB = std::make_shared<std::string>("my son");
	if ((pA != pB) && (pA != nullptr))
	{
		std::cout << "Both pointers point not to the same object!" << std::endl;
	}

	//unique�����������ֵ�Ƿ�Ϊ1
	auto pname = std::make_shared<std::string>("CGinMax");

	//Ҳ���Լ���Ƿ���ڸ���
	std::shared_ptr<std::string> pname2;
	pname2 = pname;
	/*auto pname3 = std::make_shared<std::string>("CGinMax");*/
	if (pname.unique())
	{
		std::cout << "there is only one pointer.\n";

	}
	else
	{
		std::cout << "there is more than one copy pointers.\n" << "About have " << pname.use_count() << std::endl;
	}
}


int main()
{
	//sharedPtr();
	CompareCheck();
	return 0;
}