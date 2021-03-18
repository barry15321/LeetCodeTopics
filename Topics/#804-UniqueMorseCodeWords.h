#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:

	int uniqueMorseRepresentations(vector<string>& words) {
		
		string code[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		vector<string>::iterator it;
		string::iterator its;
		set<string> table;
				
		//for (int i = 0; i < words.size(); i++){
		//	{
		//		string str;
		//		for (int j = 0; j < words[i].length(); j++)
		//			str += code[words[i][j] - 97];
		//		//table.push_back(str);
		//		table.insert(str);
		//		str.clear();
		//	}			
		//}

		//for (it = words.begin(); it != words.end(); it++) {
		//	string str;
		//	for (its = it->begin(); its != it->end(); its++) {
		//		str += code[*its - 'a'];
		//	}
		//	table.insert(str);
		//}
		
		//iterator version

		for (auto nit : words)
		{
			string str;
			for (auto sit : nit) str += code[sit - 'a'];
			table.insert(str);
		}
		 
		return table.size();
	}
	
	void TopicAnswer()
	{
		vector<string> testword;
		testword.push_back("hello");
		testword.push_back("dddd");
		testword.push_back("eeeeeo");
		testword.push_back("xxxddddd");

		cout << uniqueMorseRepresentations(testword) << endl;
	}
};
