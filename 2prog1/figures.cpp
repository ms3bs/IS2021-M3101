//#include<iostream>
//#include<stdarg.h>
//#include<vector>
//#include<algorithm>
//int const NF = 100000000;
//using namespace std;
//class Point {
//public:
//	Point(double x = 0, double y = 0)
//		:x(x), y(y) {}
//	Point(Point const& other)
//		: x(other.x), y(other.y)
//	{}
//	~Point() = default;
//	Point& operator=(Point const& other)
//	{
//		x = other.x;
//		y = other.y;
//	}
//	double const xcoord() const{
//		return x;
//	}
//	double const ycoord() const{
//		return y;
//	}
//private:
//	double x;
//	double y;
//};
//class Line {
//public:
//	Line(vector <Point> other = {})
//		: points(other) 
//	{}
//	Line(Line const& other)
//		:points(other.points)
//	{}
//	~Line()
//	{}
//	Line& operator=(Line const& other)
//	{
//		points = other.points;
//	}
//	vector <Point> getpoints() const
//	{
//		return points;
//	}
//	//void add(Point const& other) 
//	// {
//	//	points.push_back(other);
//	//}
//	double Perimeter() const
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
//class Closed : public Line {
//public:
//	Closed(vector <Point> other = {})
//		:Line(other)
//	{}
//	Closed(Closed const& other)
//		:Line(getpoints())
//	{}
//	~Closed()
//	{}
//	Closed& operator=(Closed const& other)
//	{}
//	double Perimeter()
//	{
//		double result = 0;
//		vector <Point> points = getpoints();
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			result += sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(points)].ycoord(), 2));
//		}
//		return result;
//	}
//};
//class Polygon: public Closed{
//public:
//	Polygon(vector<Point> const& other)
//		:Closed(other)
//	{
//		vector <Point> points = getpoints();
//		int n = size(points);
//		for (int i = 0; i < n; i++)
//		{
//			Point r1(points[(n + i - 1) % n].xcoord() - points[i].xcoord(), points[(n + i - 1) % n].ycoord() - points[i].ycoord());
//			Point r2(points[(i + 1) % n].xcoord() - points[i].xcoord(), points[(i + 1) % n].ycoord() - points[i].ycoord());
//			if ((r1.xcoord() * r2.ycoord() - r1.ycoord() * r2.xcoord()) > 0)
//			{
//				cout << "!" << endl;
//			}
//		}
//	}
//	Polygon(Polygon const& other)
//		: Closed(getpoints())
//	{}
//	~Polygon()
//	{}
//	Polygon& operator=(Polygon const& other)
//	{}
//	double Area()
//	{
//		double result = 0;
//		vector <Point> points = getpoints();
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			result += points[i].xcoord() * points[(i + 1) % (int)size(points)].ycoord() - points[i].ycoord() * points[(i + 1) % (int)size(points)].xcoord();
//		}
//		result = abs(result) / 2;
//		return result;
//	}
//}; 
//class Triangle: public Polygon{
//public:
//	Triangle(vector<Point> other)
//		: Polygon(other)
//	{
//		if (size(other) != 3)
//		{
//			cout << "!";
//		}
//	}
//	Triangle(Triangle const& other)
//		:Polygon(other.getpoints())
//	{}
//	~Triangle()
//	{}
//	Triangle& operator=(Triangle const& other)
//	{}
//};
//class Trapeze : public Polygon {
//public:
//	Trapeze(vector<Point> other)
//		: Polygon(other)
//	{
//		if (size(other) != 4)
//		{
//			cout << "trapeze" << endl;
//		}
//		vector <Point> points = getpoints();
//		Point r1(points[1].xcoord() - points[0].xcoord(), points[1].ycoord() - points[0].ycoord());
//		Point r2(points[3].xcoord() - points[2].xcoord(), points[3].ycoord() - points[2].ycoord());
//		if (r2.xcoord() == 0 || r1.xcoord() == 0)
//		{
//			if (r2.xcoord() != 0 || r1.xcoord() != 0)
//			{
//				cout << "trapeze" << endl;
//			}
//		}
//	}
//	Trapeze(Trapeze const& other)
//		:Polygon(other.getpoints())
//	{}
//	~Trapeze()
//	{}
//	Trapeze& operator=(Trapeze const& other)
//	{}
//};
//class RightPolygon : public Polygon {
//public:
//	RightPolygon(vector<Point> other)
//		: Polygon(other)
//	{
//		vector<Point> points = getpoints();
//		double ind = 0;
//		for (int i = 0; i < (int)size(points); i++)
//		{
//			if (sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(points)].ycoord(), 2)) == ind || ind == 0)
//			{
//				ind = sqrt(pow(points[i].xcoord() - points[(i + 1) % (int)size(points)].xcoord(), 2) + pow(points[i].ycoord() - points[(i + 1) % (int)size(points)].ycoord(), 2));
//			}
//			else
//			{
//				cout << "RightPolygon" << endl;
//			}
//		}
//	}
//	RightPolygon(RightPolygon const& other)
//		:Polygon(other.getpoints())
//	{}
//	~RightPolygon()
//	{}
//	RightPolygon& operator=(RightPolygon const& other)
//	{}
//};
//int main()
//{
//	Line(vector<Point>)
//	return 0;
//}