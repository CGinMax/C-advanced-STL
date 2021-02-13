#include <iostream>
#include <memory>
#include <string>
void sharedPtr()
{
	//shared_ptr的创建
	std::shared_ptr<double> pdata{ new double{ 999.0 } };
	std::cout << *pdata << std::endl;
	//通过解引用修改shared_ptr的值
	/**pdata = 23.42;
	std::cout << *pdata << std::endl;*/
	//std::shared_ptr<double> pdata2;
	//pdata2 = pdata;//拷贝一份pdata指针给pdata2

	//更高效率的make_shared创建shared_ptr
	auto pdatas = std::make_shared<double>(32.45);
	std::cout << "pdatas:" << *pdatas << std::endl;

	//get函数获取原生指针
	auto pvalues = pdatas.get();
	std::cout << "Pvalues:" << *pvalues << std::endl;

	//重置shared_ptr,将该指针赋值为nullptr，并且引用计数会自动减1
	auto pname = std::make_shared<std::string>("CGinMax");
	//pname = nullptr;

	//也可以用reset函数
	pname.reset(new std::string{ "Elliot" });
}

void CompareCheck()
{
	//用任意的比较运算符比较两个shared_ptr的地址值
	auto pA = std::make_shared<std::string>("my Wife");
	auto pB = std::make_shared<std::string>("my son");
	if ((pA != pB) && (pA != nullptr))
	{
		std::cout << "Both pointers point not to the same object!" << std::endl;
	}

	//unique函数检查引用值是否为1
	auto pname = std::make_shared<std::string>("CGinMax");

	//也可以检查是否存在副本
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