#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
	int result = 0;
	for (auto i : nums) {
		result ^= i;
	}
	return result;
	} 
	// XOR function , cause we know A XOR A = 0 , therefore we only need 1 loop to check every elememts in the array
	// for like: [2,1,4,5,2,4,1] 
	// XOR -> 0 ^ 2 ^ 1 ^ 4 ^ 5 ^ 2 ^ 4 ^ 1
	//    ==> 0 ^ 2 ^ 2 ^ 1 ^ 1 ^ 4 ^ 4 ^ 5
	//    ==> 0 ^ 0 ^ 0 ^ 0 ^ 5 => 5
/*
	vector<int> ary;
	ary.push_back(2);
	ary.push_back(2);
	ary.push_back(1);
	
	for (int i = 0; i < ary.size(); i++)
	{
		bool flag = false;
		for (int j = i; j < ary.size(); j++)
		{
			if (ary[i] == ary[j] && i != j && ary[i] != 0 && ary[j] != 0)
			{
				ary[i] = 0;
				ary[j] = 0;
				flag = true;
				break;
			}
		}
		if (flag == false && ary[i] != 0)
			cout << ary[i] << endl;
			//return ary[i];
	}
	
	for (auto i : ary) {
		cout << i << " ";
	}
	cout << endl;
*/
	//on vector , simply dealing data in array , but there is a better way

	void TopicAnswer()
	{
		cout<< singleNumber(98) << endl;
	}
};
