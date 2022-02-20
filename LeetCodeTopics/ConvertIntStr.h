#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
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