//#include<iostream>
//#include<iterator>
//#include<algorithm>
//#include<cmath>
////#include"Ringiterator.h""
//using namespace std;
//template<typename T>
//class elden {
//private:
//	T* start = NULL;
//	T* head = NULL;
//	T* tail = NULL;
//	size_t size;
//	size_t number = 0;
//public:
//	//constr
//	elden(int size = 0)
//		:size(size)
//	{
//		if (size == 0)
//		{
//			return;
//		}
//		start = new T[size];
//		head = start;
//		tail = start;
//		number = 0;
//	}
//	elden(elden const& other)
//		:size(other.size)
//	{
//		start = new T[size];
//		T* val = other.tail;
//		int i = 0;
//		while (i < other.size)
//		{
//			new(start + (val - other.start)) T(*val);
//			val = other.start + (val - other.start + 1) % other.size;
//			i++;
//		}
//		head = start + (other.head - other.start);
//		tail = start + (other.tail - other.start);
//		number = other.number;
//	}
//	~elden()
//	{
//		delete[] start;
//	}
//	elden operator =(elden const& other)
//	{
//		if (this == other)
//		{
//			return;
//		}
//		delete[] start;
//		size = other.size;
//		start = new T[size];
//		start = new T[size];
//		T* val = other.tail;
//		int i = 0;
//		while (i < other.size)
//		{
//			new(start + (val - other.start)) T(*val);
//			val = other.start + (val - other.start + 1) % other.size;
//			i++;
//		}
//		head = start + (other.head - other.start);
//		tail = start + (other.tail - other.start);
//		number = other.number;
//	}
//	//iterator
//	class ring :public std::iterator<std::random_access_iterator_tag, T> {
//	public:
//		ring(T* url, T* begin, T* end, size_t number)
//			:url(url), begin(begin), end(end), number(number), size(end - begin)
//		{}
//		ring(ring const& other)
//		{
//			*this = other;
//		}
//		T& operator *()const
//		{
//			return *url;
//		}
//		T* operator ->() const
//		{
//			return url;
//		}
//		ring& operator =(ring const& other)
//		{
//			url = other.url;
//			begin = other.begin;
//			end = other.end;
//			return *this;
//		}
//		ring& operator ++()
//		{
//			url++;
//			//if (url == end)
//			//{
//			//	url = begin;
//			//}
//			return *this;
//		}
//		ring& operator --()
//		{
//			url--;
//			if (url < begin)
//			{
//				url = end;
//			}
//			return *this;
//		}
//		ring& operator +(int n)
//		{
//			if (url + n < begin)
//			{
//				url = end - (n - (url - begin) + 1);
//			}
//			else
//			{
//				if (url + n >= end)
//				{
//					url = begin + (url - end) + n;
//				}
//				else
//				{
//					url += n;
//				}
//			}
//			return *this;
//		}
//		ring& operator -(int n)
//		{
//			return *this + (-n);
//		}
//		ring& operator +=(int n)
//		{
//			*this = *this + n;
//			return *this;
//		}
//		ring& operator -=(int n)
//		{
//			*this = *this - n;
//			return *this;
//		}
//		int operator -(ring const& other) const
//		{
//			return url - other.url;
//		}
//		T& operator [](size_t i)
//		{
//			if (i < end - begin)
//			{
//				return url[i];
//			}
//			cout << "none";
//			return T();
//		}
//		bool operator == (ring const& other) const
//		{
//			return url == other.url;
//		}
//		bool operator !=(ring const& other) const
//		{
//			return url != other.url;
//		}
//		bool operator <(ring const& other) const
//		{
//			return url < other.url;
//		}
//		bool operator >(ring const& other) const
//		{
//			return url > other.url;
//		}
//		bool operator <=(ring const& other) const
//		{
//			return url <= other.url;
//		}
//		bool operator >=(ring const& other) const
//		{
//			return url >= other.url;
//		}
//	private:
//		T* url;
//		T* begin;
//		T* end;
//		size_t number;
//		size_t size;
//	};
//	//other
//	ring begin()
//	{
//		return ring(start, start, start + size, number);
//	}
//	ring end()
//	{
//		return ring(start + size, start, start + size, number);
//	}
//	T& gettail()
//	{
//		return *tail;
//	}
//	T& gethead()
//	{
//		return head;
//	}
//	void resizing(size_t size2)
//	{
//		T* start2 = new T[size2], * val = tail;
//		int i = 0;
//		while (i < number)
//		{
//			new(start2 + i % size2) T(*val);
//			val = start + (val - start + 1) % size;
//			i++;
//		}
//		delete[] start;
//		head = start2 + i % size2;
//		if (i > size2)
//		{
//			tail = head;
//		}
//		else
//		{
//			tail = start2;
//		}
//		start = start2;
//		size = size2;
//		number = min(i, int(size2));
//	}
//	void push_back(T const& val)
//	{
//		new(head) T(val);
//		head = start + (head - start + 1) % size;
//		if (number == size)
//		{
//			cout << "overflow" << endl;
//			tail = head;
//		}
//		else
//		{
//			number++;
//		}
//	}
//	void pop_back()
//	{
//		if (number == 0)
//		{
//			cout << "empty" << endl;
//			return;
//		}
//		number--;
//		head = start + (size + (head - start - 1)) % size;
//	}
//	void push_front(T const& val)
//	{
//		tail = start + (size + (tail - start - 1)) % size;
//		new(tail) T(val);
//		if (number == size)
//		{
//			cout << "overflow" << endl;
//			head = tail;
//		}
//		else
//		{
//			number++;
//		}
//	}
//	void pop_front()
//	{
//		if (number == 0)
//		{
//			return;
//		}
//		number--;
//		tail = start + (tail - start + 1) % size;
//	}
//	void print()
//	{
//		cout << tail - start << " " << head - start << endl;
//		T* val = tail;
//		for (int i = 0; i < int(number); i++)
//		{
//			cout << *val << " ";
//			val = start + (val - start + 1) % size;
//		}
//		cout << endl << endl;
//	}
//	T& operator[](size_t i)
//	{
//		return *(start + i);
//	}
//};
//int main()
//{
//	elden<int> a(3);
//	a.push_back(3);
//	a.push_back(2);
//	a.push_back(4);
//	a.pop_back();
//	a.push_back(5);
//	sort(a.begin(), a.end());
//	for (auto i = a.begin(); i < a.end(); ++i)
//	{
//		cout << *i << " ";
//	}
//	cout << endl;
//	return 0;
//}