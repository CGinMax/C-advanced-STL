#include <iostream>
#include <memory>
#include <string>

class X{};


void weakPtr()
{
	auto pdata = std::make_shared<X>();//����һ��X���shared pointer����

	std::weak_ptr<X> pwdata{ pdata };//����һ������shared pointer��weak pointer

	std::weak_ptr<X> pwdata2{ pwdata };//����һ��weak pointer�д���weak pointer����

	//�ж���ָ�����Ƿ����
	if (pwdata.expired())//�����ڣ�����ture
	{
		std::cout << "object no longer exists.\n";
	}

	//��weak_ptr�еõ�shared_ptr������lock����
	//�������lock�Ķ�����ڣ��򷵻�shared���󡣲����ڷ��ؾ���nullptr��shared����
	std::shared_ptr<X> pshared{ pwdata2.lock() };
}


int main()
{
	weakPtr();
	return 0;
}