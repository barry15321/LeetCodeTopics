#pragma once
#include <iostream>
#include <string> 
using namespace std;

#define YES

void TestDefine()
{
	#ifdef YES
		int i;
	#else
		int x;
	#endif
		i = 0;
		//x = 0;

	#ifndef NO
	#define HELLO
	#endif

	#ifdef HELLO
		cout << "HELLO" << endl;
	#endif

}
