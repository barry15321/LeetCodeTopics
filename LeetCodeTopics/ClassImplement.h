#pragma once
#include <iostream>
using namespace std;

class counter
{
	private: int value;
	public: counter(int i = 0) { value = i; }
		  void reset() { value = 0; }
		  void increment() { value += 1; }
		  void increment(int n) { value += n; }
		  void decrement() { value -= 1; }
		  void decrement(int n) { value -= n; }
		  void print() { cout << "The value in counter is:" << value << endl; }
};

class CBox
{
	public:
		CBox(double lv, double bv = 1, double hv = 1);
		CBox() { cout << "Default constructor called." << endl; };
		~CBox() { cout << "destructor called " << endl; }
		void Set(double lv, double bv, double hv);
		double Volume();
		double area();
		void data_print() { cout << " lv : " << this->m_Length << " , bv : " << this->m_Breadth << " , hv = " << this->m_Height << endl; };
	private:
		double m_Length, m_Breadth, m_Height;
};

CBox::CBox(double lv, double bv, double hv) : m_Length(lv), m_Breadth(bv), m_Height(hv)
{
	cout << "var setting Constructor called." << endl;
	//m_Length=lv;
	//m_Breadth=bv;
	//m_Height=hv;
}

void CBox::Set(double lv, double bv, double hv)
{
	this->m_Length = lv;
	this->m_Breadth = bv;
	this->m_Height = hv;
}

double CBox::Volume()
{
	return (m_Length * m_Breadth * m_Height);
}

double CBox::area()
{
	return (m_Length * m_Breadth + m_Breadth * m_Height + m_Length * m_Height) * 2;
}

class Stack
{
	private :
	protected:
		int* array;
		int top, num;
	public:
		Stack(int n) { this->num = n; this->top = 0; this->array = new int[num]; }
		~Stack() { delete[]array; cout << "動態配置記憶體已清除" << endl; }
		void push(int var) { this->array[top] = var; this->top++; }
		void pop() { this->top--; cout << array[top] << endl; }
};

class Stack2 :public Stack
{
	public:
		Stack2(int n) :Stack(n) { }
		void push(int var)
		{
			if (top < num) 
				Stack::push(var);
			else 
				cout << "堆疊已滿" << endl; cout << var << endl;
		}
		void pop()
		{
			if (top > 0)  
				Stack::pop();
			else 
				cout << "堆疊已空"; 
		}
};

const double PI = 3.1415926;
class IPoint
{	
	public :
		double x;
		double y;
		IPoint() { x = 0; y = 0; }
		IPoint(double x, double y) { this->x = x; this->y = y; }
		~IPoint() {}
};

class IShape
{
	public :
		virtual double Perimeter() = 0;
		virtual double Area() = 0;
		IPoint startpoint;
		IPoint endpoint;
};

class ICircle : public IShape
{
public:
	ICircle() : m_radius(1)
	{
	}

	ICircle(double radius) : m_radius(radius > 0 ? radius : 1)
	{
	}

	void SetRadius(double radius)
	{
		if (radius > 0)
			m_radius = radius;
	}

	double GetRadius()
	{
		return m_radius;
	}

	double Perimeter()
	{
		double p = PI * m_radius;
		return p + p;
	}

	double Area()
	{
		return m_radius * m_radius * PI;
	}

private:
	double m_radius;
};

class IRectangle : public IShape
{
public:
	IRectangle() : m_length(1), m_width(1)
	{
	}

	IRectangle(double length, double width): m_length(length > 0 ? length : 1), m_width(width > 0 ? width : 1)
	{
	}

	void SetLength(double length)
	{
		if (length > 0)
			m_length = length;
	}

	double GetLength()
	{
		return m_length;
	}

	void SetWidth(double width)
	{
		if (width > 0)
			m_width = width;
	}

	double GetWidth()
	{
		return m_width;
	}

	double Perimeter()
	{
		return m_length + m_length + m_width + m_width;
	}

	double Area()
	{
		return m_length * m_width;
	}
	
private:
	double m_length;
	double m_width;
};

double AreaSummation(vector<IShape*> shapes)
{
	double result = 0;

	for (vector<IShape*>::size_type i = 0; i != shapes.size(); ++i)
	{
		result += shapes[i]->Area();
	}

	return result;
}

void IClass_Example()
{
	vector<IShape*> shapes;
	ICircle aCircle[3];
	IRectangle aRect[3];

	aCircle[0] = ICircle(0.75);
	aCircle[1] = ICircle();
	aCircle[2] = ICircle(3.47);
	aRect[0] = IRectangle();
	aRect[1] = IRectangle(3, 4);
	aRect[2] = IRectangle(2.5, 6.25);

	for (int i = 0; i != 3; ++i)
	{
		shapes.push_back(&aCircle[i]);
		cout << "Circle " << i + 1 << ": " << endl
			<< "Radius = " << aCircle[i].GetRadius() << endl
			<< "Perimeter = " << aCircle[i].Perimeter() << endl
			<< "Area = " << aCircle[i].Area() << endl << endl;
	}

	for (int i = 0; i != 3; ++i)
	{
		shapes.push_back(&aRect[i]);
		cout << "Rectangle " << i + 1 << ": " << endl
			<< "Length = " << aRect[i].GetLength() << ", Width = " << aRect[i].GetWidth() << endl
			<< "Perimeter = " << aRect[i].Perimeter() << endl
			<< "Area = " << aRect[i].Area() << endl << endl;
	}

	cout << "Area Summation = " << AreaSummation(shapes) << endl;
}