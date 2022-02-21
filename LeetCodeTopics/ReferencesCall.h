#pragma once
#include<iostream>

int call_by_value(int a, int b);   //傳值呼叫(call by value) 若沒有用return回傳 , x y 值並不改變
int call_by_address(int& a, int& b); //傳址呼叫(call by address = call by pointer) x y 值都已經改變(所以可以不用return)
int call_by_reference(int* a, int* b);//其實跟傳址呼叫一樣 , 不過用法有些不同 (call by reference)

void Ref_Call(int x, int y)
{
	int sx = x, sy = y;

	std::cout << "call_by_value : " << call_by_value(sx, sy) << std::endl;
	std::cout << "sx : " << sx << " , sy = " << sy << std::endl;

	std::cout << "call_by_address : " << call_by_address(sx, sy) << std::endl;
	std::cout << "sx : " << sx << " , sy = " << sy << std::endl;

	std::cout << "call_by_reference : " << call_by_reference(&sx, &sy) << std::endl;
	std::cout << "sx : " << sx << " , sy = " << sy << std::endl;
}

int call_by_value(int a, int b)
{
	if (a >= b)
		return a++;
	if (a < b)
		return b++;
}

int call_by_address(int& a, int& b)
{
	if (a >= b)
		return a++;
	if (a < b)
		return b++;
}

int call_by_reference(int* a, int* b)
{
	*a += 5;
	*b += 10;
	if (*a >= *b)
		return ++*a;
	if (*a < *b)
		return *b++;
	//return ++*b;
	
}