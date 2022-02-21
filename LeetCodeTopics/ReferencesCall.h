#pragma once
#include<iostream>

int call_by_value(int a, int b);   //�ǭȩI�s(call by value) �Y�S����return�^�� , x y �Ȩä�����
int call_by_address(int& a, int& b); //�ǧ}�I�s(call by address = call by pointer) x y �ȳ��w�g����(�ҥH�i�H����return)
int call_by_reference(int* a, int* b);//����ǧ}�I�s�@�� , ���L�Ϊk���Ǥ��P (call by reference)

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