#pragma once
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
private:

	string int2str(int &i) {
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

public:
	vector<string> fizzBuzz(int n) {
		vector<string> ary;
		string word;
		int setNum = 1;

		while (n) {

			if (setNum % 3 == 0 && setNum % 5 == 0)
				word = "FizzBuzz";
			else if (setNum % 3 == 0)
				word = "Fizz";
			else if (setNum % 5 == 0)
				word = "Buzz";
			else
				word = int2str(setNum);

			ary.push_back(word);
			n--; setNum++;
		}
		return ary;
	}
	
	void TopicAnswer()
	{
		vector<string> ary = fizzBuzz(15);

		for (auto i : ary)
			cout << i << endl;
	}
};