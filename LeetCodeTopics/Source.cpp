#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

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
