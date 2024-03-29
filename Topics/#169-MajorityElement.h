#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <bitset>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int major = nums[0];
		int count =1;

		for (int i=1 ;i<nums.size();i++) {
			if (count == 0) {
                count++;
				major = nums[i];
			}
			else if (major == nums[i])
				count++;
			else count--;
		}
		
		//set first element as major element , count = 1 ,then count the rest of other elements
		return major;
	}
	
	void TopicAnswer()
	{
		vector<int> ary = {4,4,3};
		cout << majorityElement(ary) << endl;
	}
};
