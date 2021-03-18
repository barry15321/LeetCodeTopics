#pragma once
#include<iostream>
using namespace std;

class Solution {
public:

	int lengthOfLongestSubstring(string s) {
		int len = 0;
		string str = "";

		for (int i = 0; i < s.length(); i++)
		{
			string sub = "";
			for (int j = i; j < s.length(); j++)
			{
				if (sub.find(s[j]) != string::npos)
					break;
				else
					sub.push_back(s[j]);
			}
			if (sub.length() > str.length())
				str = sub;
		}

		//cout << "str = " << str << endl;
		return str.length();
	}
	
	void TopicAnswer()
	{
		cout << lengthOfLongestSubstring("SubtextSubttste00");
	}
};