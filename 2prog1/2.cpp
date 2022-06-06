//#include<iostream>
//#include<stdarg.h>
//#include<vector>
//#include<algorithm>
//int const NF = 100000000000;
//using namespace std;
//class Point {
//public:
//	Point(double x = 0, double y = 0)
//		:x(x), y(y)
//	{}
//	Point(const Point&) = default;
//	//Point(Point const& a)
//	//	:x(a.x), y(a.x)
//	//{}
//	Point& operator=(Point const& other) = default;
//	//Point& operator=(Point const& other)
//	//{
//	//	this->x = other.x;
//	//	this->y = other.y;
//	//	return *this;
//	//}
//	~Point()
//	{}
//	double xcoord() const
//	{
//		return x;
//	}
//	double ycoord() const
//	{
//		return y;
//	}
//	void Output()
//	{
//		cout << x << " " << y << endl;
//	}
//private:
//	double x;
//	double y;
//};
//class Line {
//public:
//	Line()
//	{}
//	Line(int n, Point point, ...)
//	{
//		va_list args;
//		va_start(args, n);
//		for (int i = 0; i < n; i++)
//		{
//			points.push_back(va_arg(args, Point));
//		}
//		va_end(args);
//	}
//	Line(Line const& other)
//		:points(other.points)
//	{}
//	~Line()
//	{}
//	Line& operator=(Line const& other)
//	{
//		points = other.points;
//	}
//	void Output()
//	{
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			points[i].Output();
//		}
//	}
//	double Perimeter()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(this->points) - 1; i++)
//		{
//			result += sqrt(pow(points[i].xcoord() - points[i + 1].xcoord(), 2) + pow(points[i].ycoord() - points[i + 1].ycoord(), 2));
//		}
//		return result;
//	}
//private:
//	vector <Point> points;
//};
//class Closed {
//public:
//	Closed()
//	{}
//	Closed(int n, Point point, ...)
//	{
//		va_list args;
//		va_start(args, n);
//		for (int i = 0; i < n; i++)
//		{
//			points.push_back(va_arg(args, Point));
//		}
//		va_end(args);
//	}
//	Closed(Closed const& other)
//		:points(other.points)
//	{}
//	~Closed()
//	{}
//	Closed& operator=(Closed const& other)
//	{
//		points = other.points;
//	}
//	void Output()
//	{
//		cout << (int)size(points) << endl;
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			points[i].Output();
//		}
//	}
//	double Perimeter()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(this->points); i++)
//		{
//			result += sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(this->points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(this->points)].ycoord(), 2));
//		}
//		return result;
//	}
//private:
//	vector <Point> points;
//};
//class Polygon
//{
//public:
//	Polygon()
//	{}
//	Polygon(int n, Point point, ...)
//	{
//		va_list args;
//		va_start(args, n);
//		for (int i = 0; i < n; i++)
//		{
//			points.push_back(va_arg(args, Point));
//		}
//		double ind = 0;
//		for (int i = 0; i < n; i++)
//		{
//			Point r1(points[(n + i - 1) % n].xcoord() - points[i].xcoord(), points[(n + i - 1) % n].ycoord() - points[i].ycoord());
//			Point r2(points[(i + 1) % n].xcoord() - points[i].xcoord(), points[(i + 1) % n].ycoord() - points[i].ycoord());
//			if ((r1.xcoord() * r2.ycoord() - r1.ycoord() * r2.xcoord()) * ind > 0 || ind == 0)
//			{
//				ind = r1.xcoord() * r2.ycoord() - r1.ycoord() * r2.xcoord();
//			}
//			else
//			{
//				cout << "haha" << endl;
//			}
//		}
//		va_end(args);
//	}
//	Polygon(Polygon const& other)
//		:points(other.points)
//	{}
//	~Polygon()
//	{}
//	Polygon& operator=(Polygon const& other)
//	{
//		points = other.points;
//	}
//	void Output()
//	{
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			points[i].Output();
//		}
//	}
//	double Perimeter()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(this->points); i++)
//		{
//			result += sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(this->points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(this->points)].ycoord(), 2));
//		}
//		return result;
//	}
//	double Area()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			result += points[i].xcoord() * points[(i + 1) % (int)size(points)].ycoord() - points[i].ycoord() * points[(i + 1) % (int)size(points)].xcoord();
//		}
//		result = abs(result) / 2;
//		return result;
//	}
//private:
//	vector <Point> points;
//};
//class Triangle {
//public:
//	Triangle()
//	{}
//	Triangle(int n, Point point, ...)
//	{
//		if (n != 3)
//		{
//			cout << "haha" << endl;
//		}
//		va_list args;
//		va_start(args, n);
//		for (int i = 0; i < n; i++)
//		{
//			points.push_back(va_arg(args, Point));
//		}
//		double ind = 0;
//		for (int i = 0; i < n; i++)
//		{
//			Point r1(points[(n + i - 1) % n].xcoord() - points[i].xcoord(), points[(n + i - 1) % n].ycoord() - points[i].ycoord());
//			Point r2(points[(i + 1) % n].xcoord() - points[i].xcoord(), points[(i + 1) % n].ycoord() - points[i].ycoord());
//			if ((r1.xcoord() * r2.ycoord() - r1.ycoord() * r2.xcoord()) * ind > 0 || ind == 0)
//			{
//				ind = r1.xcoord() * r2.ycoord() - r1.ycoord() * r2.xcoord();
//			}
//			else
//			{
//				cout << "haha" << endl;
//			}
//		}
//		va_end(args);
//	}
//	Triangle(Triangle const& other)
//		:points(other.points)
//	{}
//	~Triangle()
//	{}
//	Triangle& operator=(Triangle const& other)
//	{
//		points = other.points;
//	}
//	void Output()
//	{
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			points[i].Output();
//		}
//	}
//	double Perimeter()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(this->points); i++)
//		{
//			result += sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(this->points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(this->points)].ycoord(), 2));
//		}
//		return result;
//	}
//	double Area()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			result += points[i].xcoord() * points[(i + 1) % (int)size(points)].ycoord() - points[i].ycoord() * points[(i + 1) % (int)size(points)].xcoord();
//		}
//		result = abs(result) / 2;
//		return result;
//	}
//private:
//	vector <Point> points;
//};
//class Trapeze {
//public:
//	Trapeze(int n, Point point, ...)
//	{
//		if (n != 4)
//		{
//			cout << "haha1" << endl;
//		}
//		va_list args;
//		va_start(args, n);
//		for (int i = 0; i < n; i++)
//		{
//			points.push_back(va_arg(args, Point));
//		}
//		Point r1(points[1].xcoord() - points[0].xcoord(), points[1].ycoord() - points[0].ycoord());
//		Point r2(points[3].xcoord() - points[2].xcoord(), points[3].ycoord() - points[2].ycoord());
//		if (r2.xcoord() == 0 || r1.xcoord() == 0)
//		{
//			if (r2.xcoord() != 0 || r1.xcoord() != 0)
//			{
//				cout << "haha" << endl;
//			}
//		}
//		else
//		{
//			if (r2.ycoord() / r2.xcoord() != r1.ycoord() / r1.xcoord())
//			{
//				cout << "haha" << endl;
//			}
//		}
//		va_end(args);
//	}
//	Trapeze(Trapeze const& other)
//		:points(other.points)
//	{}
//	~Trapeze()
//	{}
//	Trapeze& operator=(Trapeze const& other)
//	{
//		points = other.points;
//	}
//	void Output()
//	{
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			points[i].Output();
//		}
//	}
//	double Perimeter()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(this->points); i++)
//		{
//			result += sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(this->points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(this->points)].ycoord(), 2));
//		}
//		return result;
//	}
//	double Area()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			result += points[i].xcoord() * points[(i + 1) % (int)size(points)].ycoord() - points[i].ycoord() * points[(i + 1) % (int)size(points)].xcoord();
//		}
//		result = abs(result) / 2;
//		return result;
//	}
//private:
//	vector <Point> points;
//};
//class RightPolygon
//{
//public:
//	RightPolygon()
//	{}
//	RightPolygon(int n, Point point, ...)
//	{
//		va_list args;
//		va_start(args, n);
//		for (int i = 0; i < n; i++)
//		{
//			points.push_back(va_arg(args, Point));
//		}
//		double ind = NF, ind2 = 0;
//		for (int i = 0; i < n; i++)
//		{
//			Point r1(points[(n + i - 1) % n].xcoord() - points[i].xcoord(), points[(n + i - 1) % n].ycoord() - points[i].ycoord());
//			Point r2(points[(i + 1) % n].xcoord() - points[i].xcoord(), points[(i + 1) % n].ycoord() - points[i].ycoord());
//			if ((r1.xcoord() * r2.ycoord() - r1.ycoord() * r2.xcoord()) * ind > 0 || ind == NF)
//			{
//				ind = r1.xcoord() * r2.ycoord() - r1.ycoord() * r2.xcoord();
//			}
//			else
//			{
//				cout << "haha" << endl;
//			}
//			if (sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(this->points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(this->points)].ycoord(), 2)) == ind || ind == 0)
//			{
//				ind = sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(this->points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(this->points)].ycoord(), 2));
//			}
//			else
//			{
//				cout << "haha" << endl;
//			}
//		}
//		va_end(args);
//	}
//	RightPolygon(RightPolygon const& other)
//		:points(other.points)
//	{}
//	~RightPolygon()
//	{}
//	RightPolygon& operator=(RightPolygon const& other)
//	{
//		points = other.points;
//	}
//	void Output()
//	{
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			points[i].Output();
//		}
//	}
//	double Perimeter()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(this->points); i++)
//		{
//			result += sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(this->points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(this->points)].ycoord(), 2));
//		}
//		return result;
//	}
//	double Area()
//	{
//		double result = 0;
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			result += points[i].xcoord() * points[(i + 1) % (int)size(points)].ycoord() - points[i].ycoord() * points[(i + 1) % (int)size(points)].xcoord();
//		}
//		result = abs(result) / 2;
//		return result;
//	}
//private:
//	vector <Point> points;
//};
//int main()
//{
//	//Polygon a(4, Point(6, 0), Point(13.35, 2.45), Point(11.4, 7), Point(4.8, 4.25));
//	//a.Output();
//	//cout << endl << a.Perimeter() << endl << a.Area();
//	Trapeze a(4, Point(6, 2), Point(12, 2), Point(12, 6), Point(8, 6));
//	a.Output();
//	return 0;
//}
