#pragma once
#include <iostream>
#include <cstdlib>
#include <string> 
using namespace std;

template <class T>
class TemplateClass
{
public:
	T a, b;
	TemplateClass(T first, T second);
};

template <class T>
TemplateClass<T>::TemplateClass(T first, T second)
{
	a = first;
	b = second;
}

void TestTemplateClass()
{
	TemplateClass<string> test("1.232", "2.222");
	cout << test.a.c_str() << " " << test.b.c_str() << endl;

	TemplateClass<double> dtest(1.3147515, 3.1415987654);
	cout << dtest.a << " " << dtest.b << endl;
}
