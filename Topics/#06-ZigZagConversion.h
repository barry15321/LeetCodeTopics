#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:	
	string convert(string s, int numRows)
	{
		vector<vector<char>> record;
		string combination = "";

		if (s.length() == 0)
			return "";
		if (s.length() <= numRows)
			return s;
		if (numRows == 1)
			return s;

		vector<char> rd;
		for (int i = 1; i <= s.length(); i++)
		{
			if (rd.size() == numRows)
			{
				record.push_back(rd);
				rd.clear();
				rd.push_back(s[i - 2]);
			}
			rd.push_back(s[i - 1]);
		}

		if (rd.size() > 0)
		{
			while (rd.size() != numRows)
				rd.push_back('\t');
			record.push_back(rd);
		}

		for (int i = 1; i < record.size(); i += 2)
		{		
			vector<char> temp = record[i];
			std::reverse(temp.begin(), temp.end());
			record[i] = temp;
		}
		for (int i = 1; i < record.size(); i ++)
		{
			if (i % 2 == 1)
				record[i][numRows - 1] = '\t';
			else
				record[i][0] = '\t';
			
		}

		for (int row = 0; row < numRows; row++)
		{
			for (int i = 0; i < record.size(); i++)
			{
				if (record[i][row] != '\t')
					combination += record[i][row];
			}
		}
		return combination;
	}
	
	void TopicAnswer()
	{
		cout << slu.convert("ABC", 2) << endl;

		cout << slu.convert("ABCDE", 3) << endl;

		cout << slu.convert("PAYPALISHIRING", 4) << endl;
		cout << slu.convert("PAYPALISHIRING", 3) << endl;

		cout << slu.convert("PAYPALISHIR", 4) << endl;


		cout << slu.convert("ABCCE", 2) << endl;
		cout << slu.convert("ACCCE", 2) << endl;
	}
};