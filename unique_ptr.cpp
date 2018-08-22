#include<iostream>
#include<memory>
#include<string>

void uniquePtr()
{
	//创建unique_ptr的方法
	std::unique_ptr<std::string> pname{ new std::string{ "dada" } };
	std::cout << *pname << std::endl;

	//theptr is unique_ptr
	auto theptr = std::make_unique<std::string>("Algernon");
	std::cout << *theptr << std::endl;

	//delete[] pname;
	//析构pname所指向的对象，并把原生指针替换为空指针
	pname.reset();

	//delete[] theptr;
	//析构掉原先的对象，然后把地址替换为新对象的地址
	theptr.reset(new std::string{ "CGinMax" });//不能将已经被unique_ptr所指的对象，作为reset的参数
	std::cout << *theptr << std::endl;

	//release析构对象
	auto up_name = std::make_unique<std::string>("FUCKing guy");
	//release()之后得到一个字符串对象的原生指针，而up_name_new会指向该字符串对象
	std::unique_ptr<std::string>up_name_new{ up_name.release() };//类似与两个unique_ptr指针对换
	std::cout << *up_name_new << std::endl;

	//通过swap函数交换
	up_name_new.swap(theptr);
	std::cout << "up_name_new:" << *up_name_new << std::endl;
	std::cout << "theptr:" << *theptr << std::endl;

	//指向数组的unique_ptr
	size_t len = 10;
	std::unique_ptr<int[]> pnum1{ new int[len] };
	for (size_t i = 0; i < len; i++)
	{
		pnum1[i] = i * i;
		std::cout << pnum1[i] << " ";
	}
	std::cout << std::endl;

	std::unique_ptr<int[]> pnum2 = std::make_unique<int[]>(10);
	for (size_t i = 0; i < len; i++)
	{
		pnum2[i] = i * (i + 1);
		std::cout << pnum2[i] << " ";

	}
	std::cout << std::endl;


	//将unique_ptr获取为普通指针方法
	auto unique_p = std::make_unique<std::string>("helloWorld");
	std::string* pstr{ unique_p.get() };

	std::cout << *pstr << std::endl;

}

void checkUnique()
{
	auto up_name = std::make_unique<std::string>("HelloCGinMax");
	//unique_ptr可以隐式转换为布尔值
	//也可以通过ptr.get()获取返回值，进行布尔判断
	if (up_name)
	{
		std::unique_ptr<std::string> up_new{ up_name.release() };

		if (up_new.get())
		{
			std::cout << "Up name is:" << *up_new << std::endl;
		}
		if (!up_name)
		{
			std::cout << "The unique_ptr is nullptr!" << std::endl;
		}
	}
	
}

int main()
{
	uniquePtr();
	checkUnique();

	return 0;
}