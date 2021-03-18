#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {

		int Distance = 99999999, Summary = 0;
		if (nums.size() < 3) return 0;

		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				for (int k = j + 1; k < nums.size(); k++)
				{
					int element_sum = nums[i] + nums[j] + nums[k];

					if (element_sum == target)
						return element_sum;
					else
					{
						if (abs(element_sum - target) < Distance)
						{
							Distance = abs(element_sum - target);
							Summary = element_sum;
						}
					}
				}
			}
		}

		return Summary;
	}
	
	void TopicsAnswer()
	{
		vector<int> vc = { -1, 2, 1, -4 };
		cout << threeSumClosest(vc, 1) << endl;
	}
};