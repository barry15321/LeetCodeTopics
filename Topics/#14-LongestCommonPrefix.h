#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() < 1)
			return "";

		for (int i = 0; i < strs.size(); i++)
			if (strs[i].size() == 0)
				return "";

		string Prefix = "";

		for (int i = 0; i < strs.size(); i++)
			for (int j = i; j < strs.size(); j++)
				if (strs[i].size() > strs[j].size())
				{
					string tempStr = strs[i];
					strs[i] = strs[j];
					strs[j] = tempStr;
				}

		for (int i = 0; i < strs[0].size(); i++)
		{
			bool AlphaCheck = true;
			for (int j = 1; j < strs.size(); j++)
				if (strs[0].at(i) != strs[j].at(i))
					AlphaCheck = false;

			if (AlphaCheck)
				Prefix += strs[0].at(i);
			else
				break;
		}

		//cout << "Prefix = " << Prefix << endl;

		return Prefix;
	}
	
	void TopicAnswer()
	{
		vector<string> vc = { "flower" , "flow" , "flight" };	
		cout << verify.longestCommonPrefix(vc) << endl;
	}
};