#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		string PalindStr = "";
		int LastSameWord;

		for (int i = 0; i < s.size(); i++)
		{
			LastSameWord = s.size() - 1;
			for (int j = i; j < s.size(); j++)
			{
				if (s[i] == s[LastSameWord])
				{
					string sub = s.substr(i, LastSameWord + 1 - i);
					//cout << "Here is the sub string : " << sub << endl;
					string rev = sub;
					reverse(rev.begin(), rev.end());
					if (sub == rev && sub.size() > PalindStr.size())
						PalindStr = sub;
				}
				LastSameWord--;
			}
		}
		return PalindStr;
	}
	
	void TopicAnswer()
	{
		cout << longestPalindrome("TestfileForLeetcode to Test") << endl;
	}
};