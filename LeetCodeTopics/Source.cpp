#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>

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
	char fileName[] = "data.txt";
	ifstream infile(fileName);

	if (infile)
		cout << infile.rdbuf();
	else
		cerr << "Error while opening the file " << fileName << endl;

	system("Pause");
	return 0;
}
