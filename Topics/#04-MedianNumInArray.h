#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public: 
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		double ThisIsMedNum = 0;

		for (auto it : nums2)
			nums1.push_back(it);
		sort(nums1.begin(), nums1.end());
		
		ThisIsMedNum = (nums1.size() % 2 == 0) ? (double)(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / (double)2 : (double)nums1[nums1.size() / 2];

		return ThisIsMedNum;
	}

	// if by seeing amounts of functions = O(1) + O(n) + O(1) + O(1)
	// Match the way of this question
	// and also work.
	// 28ms
	
	void TopicAnswer()
	{
		vector<int> vc1 = { 1,2 };
		vector<int> vc2 = { 3,4 };

		cout << slu.findMedianSortedArrays(vc1, vc2) << endl;

	}
	
private:

	double findMedianSortedArrays_firstVersion(vector<int>& nums1, vector<int>& nums2) {

		double ThisIsMedNum = 0;
		vector<int> vc;

		for (int i = 0; i < nums1.size(); i++)
			vc.push_back(nums1[i]);
		for (int i = 0; i < nums2.size(); i++)
			vc.push_back(nums2[i]);
		
		for (int i = 0; i < vc.size(); i++)
		{
			for (int j = i; j < vc.size(); j++)
			{
				if (vc[i] < vc[j])
					swap(vc[i], vc[j]);
			}
		}

		ThisIsMedNum = (vc.size() % 2 == 0) ? (double)(vc[vc.size() / 2] + vc[vc.size() / 2 - 1]) / (double)2 : (double)vc[vc.size() / 2];

		return ThisIsMedNum;
	}

	// Same as the first way , but it acutally just see more clearly in sort function
	// Although Complextiy of O(n^2) has not match condition of this question , it still work.
	// 124ms
};