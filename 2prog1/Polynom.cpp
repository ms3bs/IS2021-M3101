#include<iostream>
#include<vector>
#include<algorithm>
#include<stdarg.h>
#include<map>
using namespace std;
class Polyn {
public:
	Polyn(map<int, double> other = {})
		:coef(other)
	{}
	Polyn(int n, int a, ...)
	{
		va_list args;
		va_start(args, n);
		for (int i = 0; i < n; i++)
		{
			int num1 = va_arg(args, int);
			double num2 = va_arg(args, double);
			coef[num1] = num2;
		}
		va_end(args);
	}
	Polyn(Polyn const& other)
		:coef(other.coef)
	{}
	~Polyn()
	{}
	void operator=(Polyn const& other)
	{
		coef = other.coef;
	}
	bool operator==(Polyn const& other)
	{
		return other.coef == coef;
	}
	bool operator!=(Polyn const& other)
	{
		return other.coef != coef;
	}
	Polyn operator+(Polyn& other)
	{
		map<int, double> res = this->coef;
		for (map <int, double> ::iterator it = other.coef.begin(); it != other.coef.end(); it++)
		{
			if (res.find(it->first) != res.end())
			{
				res[it->first] += it->second;
			}
			else
			{
				res[it->first] = it->second;
			}
		}
		return Polyn(res);
	}
	Polyn operator-(Polyn& other)
	{
		map<int, double> res = this->coef;
		for (map <int, double> ::iterator it = other.coef.begin(); it != other.coef.end(); it++)
		{
			if (res.find(it->first) != res.end())
			{
				res[it->first] -= it->second;
			}
			else
			{
				res[it->first] = -it->second;
			}
		}
		return Polyn(res);
	}
	Polyn operator+()
	{
		return *this;
	}
	Polyn operator-()
	{
		map<int, double> res = this->coef;
		for (map <int, double> ::iterator it = res.begin(); it != res.end(); it++)
		{
			it->second = -it->second;
		}
		return Polyn(res);
	}
	void operator+=(Polyn& other)
	{
		*this = *this + other;
	}
	void operator-=(Polyn& other)
	{
		*this = *this - other;
	}
	Polyn operator*(Polyn& other)
	{
		map<int, double> res;
		for (map <int, double> ::iterator it = coef.begin(); it != coef.end(); it++)
		{
			for (map <int, double> ::iterator it2 = other.coef.begin(); it2 != other.coef.end(); it2++)
			{
				if (res.find(it->first + it2->first) != res.end())
				{
					res[it->first + it2->first] += it->second * it2->second;
				}
				else
				{
					res[it->first + it2->first] = it->second * it2->second;
				}
			}
		}
		return Polyn(res);
	}
	Polyn operator/(double const k)
	{
		map<int, double> res = this->coef;
		for (map <int, double> ::iterator it = res.begin(); it != res.end(); it++)
		{
			it->second = it->second / k;
		}
		return Polyn(res);
	}
	void operator*=(Polyn& other)
	{
		*this = *this * other;
	}
	void operator/=(double const k)
	{
		*this = *this / k;
	}
	double operator[](int const k)
	{
		if (coef.find(k) == coef.end())
		{
			cout << "!" << endl;
			return 0;
		}
		return coef[k];
	}
	friend istream& operator>>(istream& is, Polyn& other);
	friend ostream& operator<<(ostream& os, Polyn& other);
private:
	map <int, double> coef;
};
istream& operator>>(istream& is, Polyn& other)
{
	int n;
	is >> n;
	for (int i = 0; i < n; i++)
	{
		int num1;
		double num2;
		is >> num1 >> num2;
		other.coef[num1] = num2;
	}
	return is;
}
ostream& operator<<(ostream& os, Polyn& other)
{
	int ind = 0;
	for (map <int, double> ::iterator it = other.coef.begin(); it != other.coef.end(); it++)
	{
		if (it->second == 0)
		{
			continue;
		}
		if (it->second > 0)
		{
			if (ind)
			{
				os << "+";
			}
			else
			{
				ind = 1;
			}
		}
		else
		{
			ind = 1;
		}
		os << it->second;
		if (it->first)
		{
			os << "*";
			if (it->first > 1)
			{
				cout << "(x)^(" << it->first << ")";
			}
			else
			{
				cout << "x";
			}
		}
	}
	return os;
}
int main()
{
	Polyn a(2, 0, 1.0, 1, 1.0), b(a);
	a = a * b;
	cout << a;
	return 0;
}