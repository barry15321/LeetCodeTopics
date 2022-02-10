#include<iostream>
#include<stack>
#include<queue>
#include<sstream>
#include "FkingPrintStar.h"

using namespace std;

string int2str(int& i) {
	string s;
	stringstream ss(s);
	ss << i;
	return ss.str();
}

int str2int(string str) {
	int number;
	stringstream(str) >> number;
	return number;
}

int main()
{
	fkStar star;
	star.PrintStar(7);
	system("Pause");
	return 0;
}
