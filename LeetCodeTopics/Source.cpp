#include<iostream>
#include<stack>
#include<queue>
#include<sstream>

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
	//Solution s;
	//vector<vector<char>> vc;
	//vector<char> c_ary;
	//c_ary = { '5','3','.','.','7','.','.','.','.' }; vc.push_back(c_ary);
	//c_ary = { '6','.','.','1','9','5','.','.','.' }; vc.push_back(c_ary);
	//c_ary = { '.','9','8','.','.','.','.','6','.' }; vc.push_back(c_ary);
	//c_ary = { '8','.','.','.','6','.','.','.','3' }; vc.push_back(c_ary);
	//c_ary = { '4','.','.','8','.','3','.','.','1' }; vc.push_back(c_ary);
	//c_ary = { '7','.','.','.','2','.','.','.','6' }; vc.push_back(c_ary);
	//c_ary = { '.','6','.','.','.','.','2','8','.' }; vc.push_back(c_ary);
	//c_ary = { '.','.','.','4','1','9','.','.','5' }; vc.push_back(c_ary);
	//c_ary = { '.','.','.','.','8','.','.','7','9' }; vc.push_back(c_ary);

	//cout << "T/F : " << s.isValidSudoku(vc) << endl;


	system("Pause");
	return 0;
}
