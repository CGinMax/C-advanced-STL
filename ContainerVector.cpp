#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

void VectorTest()
{
	//分配10个元素的内存，但没有元素
	std::vector<int> v;
	v.reserve(10);
	std::cout << "V elements size :" << v.size() << std::endl;
	std::cout << "v elements capacity: " << v.capacity() << std::endl;
	for (size_t index = 0; index < v.capacity();index++)
	{
		v.push_back(index);
	}
	std::cout << "After assign, v.size :" << v.size() << std::endl;
	//容量满的情况下，插入一个元素
	v.push_back(11);
	std::cout << "After push a element in back, v.size :" << v.size() << std::endl;//size增加了1
	std::cout << "After push a element in back, v.capacity :" << v.capacity() << std::endl;//capacity增加了5

	//分配5个元素。元素默认初始值为0
	std::vector<std::string> vs1(5);
	std::vector<std::string> vs2(5, "CGinMax");//每个元素都是CGinMax

	//迭代器初始
	std::vector<std::string> vs3 { std::begin(vs2), std::end(vs2) };
	std::cout << "vs3.at(2) : " << vs3.at(2) << std::endl;
	//移动迭代器初始,元素的内存容量和个数还在，但值被move走了
	std::vector<std::string> vs4{ std::make_move_iterator(std::begin(vs2)), std::make_move_iterator(std::end(vs2)) };
	std::cout << "vs4.at(0) : " << vs4.at(0) << std::endl;
	std::cout << "vs2 has gone? " << vs2.size() << " size, " << vs2.capacity() << " capacity"<< std::endl;
	std::cout << "vs2.at(0) : " << vs2.at(0) << std::endl;

	//resize， Parameters：the vector size you want to reset, assign a inital value to new elements(default is 0)
	std::vector<int> values = { 1, 2, 3 };
	values.resize(5);
	values.resize(10, 100);//last five elements is 100
	values.resize(8, 90);//不会改变原来设定的初值
	std::copy(std::begin(values), std::end(values), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	//std::cout << "values.at(7) :" << values.at(7) << std::endl;



	//copy算法进行迭代器使用
	std::vector<double> data = { 15.9, 41.7, 20.5, 33.4, 26.8 };
	std::cout << "每个输入的数据同 空格 隔开， 用Ctrl+Z 结束:";
	//std::back_inserter -> back_insert_iterator
	//std::copy(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(), std::back_inserter(data));
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<double>(std::cout, " "));

	//make_move_iterator
	std::vector<double> data1{ std::make_move_iterator(std::begin(data)), std::make_move_iterator(std::end(data)) };
	std::copy(std::begin(data1), std::end(data1), std::ostream_iterator<double>(std::cout, " "));
	std::cout << std::endl;
	//std::vector<double> data1;
	//data1 = { std::make_move_iterator(std::begin(data)), std::make_move_iterator(std::end(data)) };
}

void PushElement()
{
	//push_back,插入一个元素就分配一个内存，所以size和capacity同时加1
	std::vector<std::string> m_vec;
	m_vec.push_back("CGinMax");
	std::cout << "size :" << m_vec.size() << std::endl;
	std::cout << "capacity :" << m_vec.capacity() << std::endl;
	m_vec.push_back("Elliot");
	m_vec.push_back("Hao");
	m_vec.push_back("Fuck");
	std::cout << "size :" << m_vec.size() << std::endl;
	std::cout << "capacity :" << m_vec.capacity() << std::endl;

	//emplace_back
	m_vec.emplace_back("emplace element");
	m_vec.emplace_back("More elements", 5, 8);//从字符串的第5+1个元素开始，读取8个字符做为字符串传入
	std::copy(std::begin(m_vec), std::end(m_vec), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//emplace，用迭代器指定位置插入，迭代器指定元素的前面插，反向迭代器向后插
	std::vector<std::string>a_str = { "people", "dog" };
	auto iter = a_str.emplace(std::begin(a_str), "AI");//返回第一个元素的迭代器
	a_str.emplace(++iter, "Ghost");
	std::copy(std::begin(a_str), std::end(a_str), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//insert ，迭代器返回插入的元素位置
	std::vector<std::string>number = { "one", "three", "four" };
	auto iter1 = number.insert(++std::begin(number), "two");
	std::cout << "the place of iter element：" << *iter1 << std::endl;

	//insert，插入多个
	std::string more[] = { "five", "six", "seven" };
	iter1 = number.insert(--std::end(number), std::begin(more), std::end(more));//不支持反向迭代器
	//iter1 = number.insert(std::rbegin(number).base(), std::begin(more), std::end(more));//rbegin().base把反向迭代器转换为标准迭代器
	std::copy(std::begin(number), std::end(number), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
	//多个相同数据插入,第二个参数为插入个数
	number.insert(std::cend(number)-1, 3, "error");

	//以初始化列表作为参数
	number.insert(std::end(number), { std::string{ "twelve" }, std::string{ "thirteen" } });
	std::copy(std::begin(number), std::end(number), std::ostream_iterator<std::string>(std::cout, " "));


}

void DelVec()
{
	//clear删除所有元素
	std::vector<int> data1(100, 99);
	data1.clear();

	//pop_back删除尾部的一个元素
	std::vector<int> data2(100, 100);
	data2.pop_back();

	//shrink_to_fit去掉多余的容量
	std::vector<int> data3(1000, 200);
	data3.clear();
	data3.shrink_to_fit();//迭代器也会随之失效

	//erase,删除一个或多个元素，参数为迭代器，同样返回值也是一个迭代器
	std::vector<std::string> str1 = { "Hello", "你好", "Yes", "好的" };
	auto iter1 = str1.erase(std::begin(str1) + 3);
	str1.emplace_back("好的");
	iter1 = str1.erase(std::begin(str1), std::begin(str1) + 2);

	//remove 移除指定数据的元素，需包含algorithm头文件
	std::vector<std::string> str2 = { "shanwei", "shenzhen", "guangzhou", "jianmen", "zhuhai" };
	auto iter2 = std::move(std::begin(str2), std::end(str2), "shanwei");
	//size和capacity都保持不变
	//数据没有被删除，知识将存有该数据的元素移到后面，返回一个新vector的最后一个有效元素的下一个元素地址
}

void CreateVec()
{
	//Default Constructor
	std::vector<std::string>v1;
	//initlist，初始化列表为元素初值
	std::vector<std::string> v2 = { "CGinMax", "Hao", "Xian", "Xin" };
	std::vector<std::string> v22({ "NB", "Fuck", "Shit", "Yashi" });
	//Copy Construcot
	std::vector<std::string> v3(v2);
	//Equal operator
	std::vector<std::string> v4 = v3;
	//Move Constructor
	std::vector<std::string> v5(std::move(v4));
	//Equal Move Constructor
	std::vector<std::string> v6 = std::move(v5);

	//构造一个大小为n的vector
	std::vector<double> d1(100);
	//10个元素的vecto，值都为49.1
	std::vector<double> d2(10, 49.1);
	//迭代器做为初始化列表
	std::vector<double> d3(std::begin(d2), std::end(d2));
}

void VecToCStyle()
{
	//跟Array容器的C-Style Array一致
}

//vector<bool>元素都是对bit进行操作
void VecBool()
{
	std::vector<bool> b1(5, true);
	//flip，对所有bool元素取反相，即对每个bit求补数
	b1.flip();
	//特定元素取反相
	b1[2].flip();
	//赋值
	b1[1] = false;


}

int main()
{
	CreateVec();
	//DelVec();
	//PushElement();
	//VectorTest();
	return 0;
}