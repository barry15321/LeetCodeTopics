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

char Alphabet_upper(char c)
{
	return (char)toupper(c);
}

char Alphabet_lower(char c)
{
	return (char)tolower(c);
}

string str_upper(string str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
	return str;
}

string str_lower(string str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);
	return str;
}

void char_var_ExampleUse()
{
	char c_str[99] = "asfDFdd";
	char cl_str[] = "Hello World";
	char* cp_str = cl_str;

	string str = "This Is A testfile.";

	for (int i = 0; i < strlen(c_str); i++)
		c_str[i] = Alphabet_upper(c_str[i]);

	cout << "cl_str : " << cl_str << endl << "cp_str : " << cp_str << endl;
	cout << "c_str : " << c_str << endl << endl;

	str = str_lower(str);
	cout << "str : " << str << endl;
}

