#pragma once
#include <iostream>
using namespace std;

int bs(int array[], int first, int last, int key)
{
	int middle;

	if (first > last)
		return (-1);
	else {
		middle = (first + last) / 2;
		if (key == array[middle]) return middle;
		if (key > array[middle]) return (bs(array, middle + 1, last, key));
		return (bs(array, first, middle - 1, key));
	}
}