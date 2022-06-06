#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

template<size_t size>
struct Piece {
public:
	Piece<size>* next = NULL;
	char data[size];
};

template<typename T, size_t numPiece = 1000, size_t sizePiece = 1000>
class Allocator {
public:
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef size_t size_type;
	typedef ptrdiff_t different_type;

	static const size_t size = sizePiece * sizeof(T);
	template<typename U>

	struct rebind {
		using other = Allocator<U, numPiece, sizePiece>;
	};
	Allocator() {
		assert(numPiece * sizePiece > 0);
		head = new Piece<size>;

		begin = new Piece<size>[numPiece];
		head = begin;
		for (int i = 0; i < numPiece - 1; i++)
		{
			(begin + i)->next = begin + i + 1;
		}
		cout << begin << endl;
	}
	Allocator(const Allocator& other)
		:begin(other.begin), head(other.head), ptr(ptr)
	{
		ptr++;
	}
	template<typename U>
	Allocator(Allocator<U, numPiece, sizePiece>& other)
		: begin((Piece<size>*)other.begin), head((Piece<size>*)other.head), ptr(other.ptr)
	{
		ptr++;
	}
	~Allocator()
	{
		if (ptr == 1)
		{
			delete[] begin;
			delete head;
		}
		else
		{
			ptr--;
		}
	}
	pointer allocate(size_t numObj)
	{
		if (numObj > sizePiece || head == NULL)
		{
			throw bad_alloc();
		}
		Piece<size>* support = head;
		cout << head << " " << head->next << endl;
		head = (head)->next;
		cout << head << endl;
		return reinterpret_cast<pointer>(support);
	}
	void deallocate(pointer p, size_t n)
	{
		Piece<size>* support = reinterpret_cast<Piece<size>*>(p);
		support->next = head;
		head = support;
	}
	bool operator==(const Allocator& other) const
	{
		return begin == other.begin;
	}

	bool operator!=(const Allocator& other) const
	{
		return begin != other.begin;
	}
	Piece<size>* begin;
	Piece<size>* head;
	size_t ptr = 1;
};
int main()
{
	vector<int, Allocator<int>> a;
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);



	}

	return 0;
}