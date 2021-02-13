#include<iostream>
#include<memory>
#include<string>

void uniquePtr()
{
	//����unique_ptr�ķ���
	std::unique_ptr<std::string> pname{ new std::string{ "dada" } };
	std::cout << *pname << std::endl;

	//theptr is unique_ptr
	auto theptr = std::make_unique<std::string>("Algernon");
	std::cout << *theptr << std::endl;

	//delete[] pname;
	//����pname��ָ��Ķ��󣬲���ԭ��ָ���滻Ϊ��ָ��
	pname.reset();

	//delete[] theptr;
	//������ԭ�ȵĶ���Ȼ��ѵ�ַ�滻Ϊ�¶���ĵ�ַ
	theptr.reset(new std::string{ "CGinMax" });//���ܽ��Ѿ���unique_ptr��ָ�Ķ�����Ϊreset�Ĳ���
	std::cout << *theptr << std::endl;

	//release��������
	auto up_name = std::make_unique<std::string>("FUCKing guy");
	//release()֮��õ�һ���ַ��������ԭ��ָ�룬��up_name_new��ָ����ַ�������
	std::unique_ptr<std::string>up_name_new{ up_name.release() };//����������unique_ptrָ��Ի�
	std::cout << *up_name_new << std::endl;

	//ͨ��swap��������
	up_name_new.swap(theptr);
	std::cout << "up_name_new:" << *up_name_new << std::endl;
	std::cout << "theptr:" << *theptr << std::endl;

	//ָ�������unique_ptr
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


	//��unique_ptr��ȡΪ��ָͨ�뷽��
	auto unique_p = std::make_unique<std::string>("helloWorld");
	std::string* pstr{ unique_p.get() };

	std::cout << *pstr << std::endl;

}

void checkUnique()
{
	auto up_name = std::make_unique<std::string>("HelloCGinMax");
	//unique_ptr������ʽת��Ϊ����ֵ
	//Ҳ����ͨ��ptr.get()��ȡ����ֵ�����в����ж�
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