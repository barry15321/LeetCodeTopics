#pragma once
#include<iostream>
#include<stack>
using namespace std;

char ConvertAlpha(int value)
{
	char c = '0';
	c = (value > 9) ? 'A' + (value - 10) : '0' + value;
	return c;
}

void PrintCarry17(int value)
{
	//int value = 973730151;
	string Carry_17 = "";
	int PowTimes = 0;

	stack<int> stk;

	while (value > 0)
	{
		stk.push(value % 17);
		value /= 17;
	}


	int top_value = 0;;
	while (!stk.empty())
	{
		top_value = stk.top();
		cout << stk.top() << " ";
		Carry_17 += ConvertAlpha(stk.top());
		stk.pop();
	}
	cout << endl;

	cout << "Carry_17 : " << Carry_17 << endl;
}