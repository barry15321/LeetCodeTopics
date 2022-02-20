#pragma once
#include<iostream>
using namespace std;

void declare2dAry_delete(int size)
{
	int** p = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		p[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			p[i][j] = i + j;
			cout << p[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++)
	{
		delete[]p[i];
	}
	delete[]p;
}

int** declare2dAry(int size)
{
	int** p = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		p[i] = new int[size];
	}
	return p;
}

