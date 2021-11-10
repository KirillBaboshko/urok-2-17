#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <cassert>
using namespace std;

class Array
{
	int size;
	int* array;
public:
	explicit Array(int size = 10);
	~Array();
	int getSize()const;
	int getValue(int index)const;
	void setValue(int index,int value);
	void display(int index)const;
};
Array::Array(int size) 
{
	this->size = size;
	array = new int[this->size];
}
Array::~Array()
{
	delete[] array;
}
int Array::getSize()const
{
	return size;
}
int Array::getValue(int index)const
{
	return array[index];
}
void Array::setValue(int index, int value)
{
	 array[index]=value;
}
void Array::display(int index)const
{
	cout << array[index]<<" ";
}
void display(const Array& array)
{
	for (int i = 0; i < array.getSize(); i++) 
	{
		array.display(i);
	}
	cout << endl;
}
class Date 
{
	int day;
	int mounth;
	int year;
public:
	Date(int day, int mounth, int year) :day{ day }, mounth{ mounth }, year{ year }
	{
	}
	Date( int year) :Date(1,1,year)
	{
	}
	friend void  displayDate(Date date);

};
void displayDate(Date date)
{
	cout << date.day << "." << date.mounth << "." << date.year<<endl;
}
Date baseDate() 
{
	return 2000;
}

class Point 
{
	double x;
	double y;
public:
	Point(double x, double y):x{x},y{y}
	{
	}
	Point() :Point{0,0}
	{
	}
	void display()const
	{
		cout << x << "," << y;
	}
	void read() 
	{
		cout << "Vvedite x"<<endl;
		cin >> x;
		
		cout << "Vvedite y" << endl;
		cin >> y;
	}
	static bool isEqual(const Point& point1, const Point& point2) 
	{
		if (point1.x == point2.x && point1.y == point2.y)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	static Point add(const Point& point1, const Point& point2) 
	{
		return Point (point1.x + point2.x,point1.y + point2.y);
	}
	static Point  mult(const Point& point1, double value) 
	{
			return Point(point1.x * value, point1.y * value);

	}
	static Point  mult( double value,const Point& point1)
	{
		return Point(point1.x * value, point1.y * value);

	}
	
	
	static double  distance(const Point& point1, const Point& point2) 
	{
		return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
	}
	static double  length(const Point& point) 
	{
		return distance(point,Point());
	}
	friend bool operator==(const Point& point1, const Point& point2) 
	{
		return isEqual(point1, point2);
	}
	friend Point operator+(const Point& point1, const Point& point2)
	{
		return add(point1, point2);
	}
	friend ostream& operator<<(ostream& output,const Point& point)
	{
		output<<"("<<point.x<<","<< point.y<<")";
		return output;
	}
};
int main()
{
	srand(time(NULL));
	//displayDate(2020);
	//Date date = 2010;
	//displayDate(date);
	//Date date2000 = baseDate();
	//displayDate(date2000);

	/*int size = 4;
	Array array(size);

	for (int i = 0; i < size; i++) 
	{
		array.setValue(i, size);
	}
	display(array);
	cout << "!!!\n";
	display();*/

	Point point1(1, 1);
	Point point2;
	Point point3(1, 1);
	if (point1==point3)
		cout << "point1 and point3 are equal" << endl;
	cout << "p1 ";
	point1.display();
	cout << endl;
	cout << "Enter point p2 in format x,y (e.g.12,10)" << endl;
	point2.read();
	cout << "p2 ";
	point2.display();
	cout << endl;
	cout << "p2 + p1 = "<<(point1+point2);
	cout << endl;
	cout << "Distance between ";
	point1.display();
	cout << " and ";
	point2.display();
	cout << " is ";
	cout << Point::distance(point1, point2);
	cout << endl;
	return 0;
}