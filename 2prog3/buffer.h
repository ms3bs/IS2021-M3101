#include<iostream>
#include<iterator>
using namespace std;
template<typename T>
class buffer {
private:
	T* begin_ = NULL;
	T* head = NULL;
	T* tail = NULL;
	size_t size;
public:
	//constr
	buffer(int size = 0)
		:size(size)
	{
		if (size == 0)
		{
			return;
		}
		begin_ = new T[size + 1];
		head = begin_;
		tail = begin_;
	}
	buffer(buffer const& other)
		:size(other.size)
	{
		begin_ = new T[size + 1];
		head = begin_ + (other.head - other.begin_);
		tail = begin_ + (other.tail - other.begin_);
		T* val = other.head;
		while (val != other.tail)
		{
			new(begin_ + (val - other.begin_)) T(*val);
			val = other.begin_ + (val - other.begin_ + 1) % (other.size + 1);
		}
	}
	~buffer()
	{
		delete[] begin_;
	}
	buffer& operator =(buffer const& other)
	{
		if (this == other)
		{
			return;
		}
		delete[] begin_;
		size = other.size;
		begin_ = new T[size + 1];
		head = begin_ + (other.head - other.begin_);
		tail = begin_ + (other.tail - other.begin_);
		T* val = other.head;
		while (val != other.tail)
		{
			new(begin_ + (val - other.begin_)) T(*val);
			val = other.begin_ + (val - other.begin_ + 1) % (other.size + 1);
		}
	}
	//iterator
	class b_iter :public std::iterator<std::random_access_iterator_tag, T> {
	public:
		b_iter(T* url, T* begin, T* end, T* head, T* tail)
			:url(url), begin(begin), end(end), size(end - begin), head(head), tail(tail)
		{}
		b_iter(b_iter const& other)
		{
			*this = other;
		}
		T& operator *()const
		{
			if ((size + (tail - head)) % size > (size + (url - head)) % size)
			{
				return *url;
			}
			cout << "exceedance" << endl;
			return *url;
		}
		T* operator ->() const
		{
			return url;
		}
		T& operator [](size_t n)
		{
			T* val = begin + (head - begin + n) % size;
			if ((size + (tail - head)) % size > (size + (val - head)) % size)
			{
				return *val;
			}
			cout << "exceedance" << endl;
			return *val;
		}
		b_iter& operator =(b_iter const& other)
		{
			url = other.url;
			begin = other.begin;
			end = other.end;
			size = other.size;
			return *this;
		}
		b_iter& operator ++()
		{
			url = begin + (url - begin + 1) % size;
			return *this;
		}
		b_iter& operator --()
		{
			url = begin + (size + (url - begin - 1)) % size;
			return *this;
		}
		b_iter& operator +(int n)
		{
			if (n > 0)
			{
				url = begin + (url - begin + n) % size;
			}
			else
			{
				url = begin + (size * n + (url - begin + n)) % size;
			}
			return *this;
		}
		b_iter& operator -(int n)
		{
			return *this + (-n);
		}
		b_iter& operator +=(int n)
		{
			*this = *this + n;
			return *this;
		}
		b_iter& operator -=(int n)
		{
			*this = *this - n;
			return *this;
		}
		int operator -(b_iter const& other) const
		{
			return (size + (url - head)) % size - (size + (other.url - head)) % size;
		}
		bool operator == (b_iter const& other) const
		{
			return url == other.url;
		}
		bool operator !=(b_iter const& other) const
		{
			return url != other.url;
		}
		bool operator <(b_iter const& other) const
		{
			if (*this - other < 0)
			{
				return 1;
			}
			return 0;
		}
		bool operator >(b_iter const& other) const
		{
			if (*this - other > 0)
			{
				return 1;
			}
			return 0;
		}
		bool operator <=(b_iter const& other) const
		{
			return !(*this > other);
		}
		bool operator >=(b_iter const& other) const
		{
			return !(*this < other);
		}
	private:
		T* url;
		T* begin;
		T* end;
		T* head;
		T* tail;
		size_t size;
	};
	//other
	b_iter begin()
	{
		return b_iter(head, begin_, begin_ + size + 1, head, tail);
	}
	b_iter end()
	{
		return b_iter(tail, begin_, begin_ + size + 1, head, tail);
	}
	//проверить
	void resizing(size_t size2)
	{
		T* begin2_ = new T[size2 + 1], * val = head;
		int number = 0;
		while (val != tail)
		{
			new(begin2_ + number % (size2 + 1)) T(*val);
			val = begin_ + (val - begin_ + 1) % (size + 1);
			number++;
		}
		delete[] begin_;
		begin_ = begin2_;
		size = size2;
		tail = begin2_ + number % (size2 + 1);
		if (number > size2)
		{
			head = begin_ + (tail - begin_ + 1) % (size + 1);
		}
	}
	void push_back(T const& val)
	{
		new(tail) T(val);
		tail = begin_ + (tail - begin_ + 1) % (size + 1);
		if (tail == head)
		{
			head = begin_ + (head - begin_ + 1) % (size + 1);
		}
	}
	void pop_back()
	{
		if (head == tail)
		{
			return;
		}
		tail = begin_ + (size + 1 + (tail - begin_ - 1)) % (size + 1);
	}
	void push_front(T const& val)
	{
		if (begin_ + (size + 1 + (head - begin_ - 1)) % (size + 1) == tail)
		{
			return;
		}
		head = begin_ + (size + 1 + (head - begin_ - 1)) % (size + 1);
		new(head) T(val);
	}
	void pop_front()
	{
		if (head == tail)
		{
			return;
		}
		head = begin_ + (head - begin_ + 1) % (size + 1);
	}
};