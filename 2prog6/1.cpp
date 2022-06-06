//#include<iostream>
//
//using namespace std;
//constexpr int f(int x, int n)
//{
//	return n > 0 ? x * f(x, n - 1) : 1;
//}
//template<int x, int...>
//class polynom {};
//template<int x, int coef, int degree>
//class polynom<x, coef, degree> {
//public:
//	static const int value = coef * f(x, degree);
//};
////template<int x, int other>
////class polynom<x, other>{
////public:
////	static const int value = x;
////};
//template<int x, int coef, int degree, int... other>
//class polynom<x, coef, degree, other...>
//{
//public:
//	static const int value = coef * f(x, degree) + polynom<x, other...>::value;
//};
//
//template<int x, int coef, int degree>
//ostream& operator <<(ostream& os, polynom<x, coef, degree> const& lala)
//{
//	os << "(" << coef << ")" << "*" << x << "^" << degree;
//	return os;
//}
//template<int x, int coef, int degree, int...other>
//ostream& operator <<(ostream& os, polynom<x, coef, degree, other...> const& lala)
//{
//	os << "(" << coef << ")" << "*" << x << "^" << degree << "+" << polynom<x, other...>();
//	return os;
//}
//int main()
//{
//	cout << polynom<6, 9, 5, -6, 4, 4, 3, -1, 2, 1, 1, -1, 0>();
//	return 0;
//}