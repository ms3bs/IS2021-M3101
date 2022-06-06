#pragma once
#include<iostream>
using namespace std;
namespace alg
{
	template<typename T>
	int funct(T const& val)
	{
		return (*val > 0);
	}
	struct gener {
		template<typename T>
		bool operator ()(T const& val)
		{
			return (*val > 0);
		}
	};
	template<typename iter, typename unar>
	bool all_of(iter begin, iter end, unar funct)
	{
		while (begin != end)
		{
			if (!(funct(begin)))
			{
				return false;
			}
			++begin;
		}
		return true;
	}
	template<typename iter, typename unar>
	bool any_of(iter begin, iter end, unar funct)
	{
		while (begin != end)
		{
			if (funct(begin))
			{
				return true;
			}
			++begin;
		}
		return false;
	}
	template<typename iter, typename unar>
	bool none_of(iter begin, iter end, unar funct)
	{
		while (begin != end)
		{
			if (funct(begin))
			{
				return false;
			}
			++begin;
		}
		return true;
	}
	template<typename iter, typename unar>
	bool one_of(iter begin, iter end, unar funct)
	{
		int num = 0;
		while (begin != end)
		{
			if (funct(begin))
			{
				num++;
			}
			++begin;
		}
		if (num == 1)
		{
			return true;
		}
		return false;
	}
	template<typename iter, typename unar>
	bool is_sorted(iter begin, iter end, unar funct)
	{
		iter val = begin;
		++val;
		while (val != end)
		{
			if (!funct(begin, val))
			{
				return false;
			}
			++begin;
			++val;
		}
		return true;
	}
	template<typename iter, typename unar>
	bool is_partitioned(iter begin, iter end, unar funct)
	{
		bool ind = 0;
		iter val = begin;
		++val;
		while (begin != end)
		{
			if (funct(begin) != funct(val))
			{
				if (ind)
				{
					return false;
				}
				ind = 1;
			}
			++begin;
			++val;
		}
		return true;
	}
	template<typename iter, typename T>
	iter find_not(iter begin, iter end, T const& val)
	{
		while (begin != end)
		{
			if (val != *begin)
			{
				return begin;
			}
			++begin;
		}
		return end;
	}
	template<typename iter, typename T>
	iter find_backward(iter begin, iter end, T const& val)
	{
		iter val2 = end;
		while (begin != end)
		{
			if (val == *begin)
			{
				val2 = begin;
			}
			++begin;
		}
		return val2;
	}
	template<typename iter, typename unar>
	bool is_palindrom(iter begin, iter end, unar funct)
	{
		--end;
		while (begin != end)
		{
			if (funct(begin) != funct(end))
			{
				return false;
			}
			++begin;
			--end;
		}
		return true;
	}
}