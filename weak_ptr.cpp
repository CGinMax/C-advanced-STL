#include <iostream>
#include <memory>
#include <string>

class X{};


void weakPtr()
{
	auto pdata = std::make_shared<X>();//创建一个X类的shared pointer对象

	std::weak_ptr<X> pwdata{ pdata };//创建一个来自shared pointer的weak pointer

	std::weak_ptr<X> pwdata2{ pwdata };//从另一个weak pointer中创建weak pointer对象

	//判断所指对象是否存在
	if (pwdata.expired())//不存在，返回ture
	{
		std::cout << "object no longer exists.\n";
	}

	//从weak_ptr中得到shared_ptr，调用lock函数
	//如果调用lock的对象存在，则返回shared对象。不存在返回具有nullptr的shared对象
	std::shared_ptr<X> pshared{ pwdata2.lock() };
}


int main()
{
	weakPtr();
	return 0;
}