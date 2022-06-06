#include<iostream>
#include<vector>
#include<algorithm>
#include<stdarg.h>
using namespace std;
class Polyn {
public:
	Polyn(vector<double> other = {})
	{
		coefs = other;
	}
	Polyn(int n, double coef, ...)
	{
		va_list args;
		va_start(args, n);
		for (int i = 0; i < n; i++)
		{
			coefs.push_back(va_arg(args, double));
		}
		va_end(args);
	}
	Polyn(Polyn const& other)
		:coefs(other.coefs)
	{}
	~Polyn()
	{}
	void operator=(Polyn const& other)
	{
		coefs = other.coefs;
	}
	bool operator==(Polyn const& other)
	{
		return other.coefs == coefs;
	}
	bool operator!=(Polyn const& other)
	{
		return other.coefs != coefs;
	}
	Polyn operator+(Polyn const& other) 
	{
		vector <double> result(max(size(other.coefs), size(coefs)), 0);
		for (int i = 0; i < max(size(other.coefs), size(coefs)); i++)
		{
			if (i < size(other.coefs))
			{
				result[i] += other.coefs[i];
			}
			if (i < size(coefs))
			{
				result[i] += coefs[i];
			}
		}
		return Polyn(result);
	}
	Polyn operator-(Polyn const& other)
	{
		vector <double> result(max(size(other.coefs), size(coefs)), 0);
		for (int i = 0; i < max(size(other.coefs), size(coefs)); i++)
		{
			if (i < size(other.coefs))
			{
				result[i] -= other.coefs[i];
			}
			if (i < size(coefs))
			{
				result[i] += coefs[i];
			}
		}
		return Polyn(result);
	}
	Polyn operator+()
	{
		return *this;
	}
	Polyn operator-()
	{
		vector <double> result(size(coefs));
		for (int i = 0; i < (int)size(coefs); i++)
		{
			result[i] = -coefs[i];
		}
		return Polyn(result);
	}
	void operator+=(Polyn const& other)
	{
		*this = *this + other;
	}
	void operator-=(Polyn const& other)
	{
		*this = *this - other;
	}
	Polyn operator*(Polyn const& other)
	{
		vector <double> resul((int)(size(coefs) + size(other.coefs)) - 1, 0);
		for (int i = 0; i < (int)(size(coefs) + size(other.coefs)) - 1; i++)
		{
			for (int j = 0; j < (int)size(coefs); j++)
			{
				if (j + size(other.coefs) - 1 < i || j > i)
				{
					continue;
				}
				resul[i] += coefs[j] * other.coefs[i - j];
			}
		}
		return Polyn(resul);
	}
	Polyn operator/(double const k)
	{
		vector <double> result(size(coefs));
		for (int i = 0; i < (int)size(coefs); i++)
		{
			if (k == 0)
			{
				if (i == 0)
				{
					cout << "!" << endl;
				}
				result[i] = 0;
			}
			else
			{
				result[i] = coefs[i] / k;
			}
		}
		return Polyn(result);
	}
	void operator*=(Polyn const& other)
	{
		*this = *this * other;
	}
	void operator/=(double const k)
	{
		*this = *this / k;
	}
	double operator[](int const k)
	{
		if (k > (int)size(coefs))
		{
			cout << "!" << endl;
			return 0;
		}
		return coefs[k];
	}
	friend istream& operator>>(istream& is, Polyn& other);
	friend ostream& operator<<(ostream& os, Polyn& other);
private:
	vector<double> coefs;
};
istream& operator>>(istream& is, Polyn& other)
{
	int n;
	is >> n;
	for (int i = 0; i < n; i++)
	{
		is >> other.coefs[i];
	}
	return is;
}
ostream& operator<<(ostream& os, Polyn & other)
{
	int ind = 0;
	for (int i = size(other.coefs) - 1; i >= 0; i--)
	{
		if (other.coefs[i] == 0)
		{
			continue;
		}
		if (other.coefs[i] > 0 )
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
		os << other.coefs[i];
		if (i)
		{
			os << "*";
			if (i > 1)
			{
				cout << "(x)^(" << i << ")";
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
	Polyn a(4, -3.4, 1.0, 3.0, 12.34), b(2, -1, 1.0);
	a = a / 2;
	cout << a;
	return 0;
}