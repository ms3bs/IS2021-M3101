#include<iostream>
#include<iterator>
#include<cmath>
#include<algorithm>
#include"buffer.h"
#include"alg.h"
using namespace std;
class lala {
public:
	lala(int num = 1, int dem = 1)
		:num(num), dem(dem)
	{
		if (dem == 0)
		{
			cout << "foo" << endl;
		}
	}
	lala(const lala& other)
		:num(other.num), dem(other.dem)
	{}
	~lala() = default;
	lala& operator =(const lala& other)
	{
		num = other.num;
		dem = other.dem;
		return *this;
	}
	bool operator <(const lala& other)
	{
		return num * other.dem < dem* other.num;
	}
	friend ostream& operator <<(ostream& is, lala& val);
private: 
	int num;
	size_t dem;
};
ostream& operator <<(ostream& os, lala& val)
{
	os << val.num << "/" << val.dem << ",";
	return os;
}
int main()
{
	cout << "int" << endl;
	buffer<int> a(10);
	a.push_back(-2);
	a.push_back(2);
	a.push_back(-10);
	a.push_back(3);
	a.push_back(-100);
	a.pop_back();
	a.pop_front();
	//a.push_front(5);
	for (auto i = a.begin(); i < a.end(); ++i)
	{
		cout << *i << " ";
	}
	auto i = a.begin();
	cout << endl;
	cout << i[1000];
	cout << endl;
	//sort(a.begin(), a.end());
	//for (buffer<int>::b_iter i = a.begin(); i < a.end(); ++i)
	//{
	//	cout << *i << " ";
	//}
	//cout << endl;
	//a.resizing(2);
	//for (auto i = a.begin(); i < a.end(); ++i)
	//{
	//	cout << *i << " ";
	//}
	//cout << endl << "other class" << endl;
	//buffer<lala> b(5);
	//b.push_back(lala(1, 1));
	//b.push_back(lala(1, 2));
	//b.push_back(lala(1, 3));
	//b.push_back(lala(5, 4));
	//for (auto i = b.begin(); i < b.end(); ++i)
	//{
	//	cout << *i << " ";
	//}
	//cout << endl;
	//sort(b.begin(), b.end());
	//for (auto i = b.begin(); i < b.end(); ++i)
	//{
	//	cout << *i << " ";
	//}
	//cout << endl << "algor" << endl;
	//cout << alg::is_palindrom<buffer<int>::b_iter>(a.begin(), a.end(), alg::funct<buffer<int>::b_iter>);
	return 0;
}