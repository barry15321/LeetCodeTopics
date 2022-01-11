#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//1 <= nums.length <= 100
		//	0 <= nums[i] <= 100
		//  2,14,7,8,1,4,6,5,2,1
		int des_index = -1;
		int swap_index = -1;
		int diff_value = INT_MAX;

		for (int i = nums.size() - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1]) // des
			{
				des_index = i - 1;
				for (int j = i - 1; j < nums.size(); j++)
				{
					if (nums[des_index] < nums[j] && nums[j] - nums[des_index] < diff_value)
					{
						diff_value = nums[j] - nums[des_index];
						swap_index = j;
					}
				}
				break;
			}
		}

		if (des_index != -1)
		{
			diff_value = nums[des_index];
			nums[des_index] = nums[swap_index];
			nums[swap_index] = diff_value;
			//swap
			sort(nums.begin() + des_index + 1, nums.end());
		}
		else {
			sort(nums.begin(), nums.end());
		}
		//sort
	};
};
