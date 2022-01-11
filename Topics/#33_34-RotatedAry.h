#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;
#pragma once


class Solution {
public:
// #33
    int search(vector<int>& nums, int target) {
        int position = -1;

        //for (int i = 0; i < nums.size(); i++)
        //{
        //    if(nums[i] == target)
        //    {
        //        position = i;
        //        break;
        //    }
        //}
        // return position;
        // Time Complexity = O(n)
        if (nums.size() == 1 && nums[0] == target) {
            return 0;
        }
        int pre = 0;
        int post = nums.size() - 1;
        
        while (pre < post)
        {
            int mid = pre + (post - 1) / 2;
            int leftnode = nums[pre];
            int rightnode = nums[post];
            int midnode = nums[mid];

            if (leftnode == target) return pre;
            if (rightnode == target) return post;
            if (midnode == target) return mid;

            if (midnode < leftnode)
            {
                if (target > leftnode && target < midnode)
                    post--;
                else
                    pre++;
            }
            else // midnode > leftnode
            {
                if (target < rightnode && target > midnode)
                    pre++;
                else
                    post--;
            }
            
        }
        return -1;
        //O(log n)
    }
// #34
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vc;
        vector<int> empty = { -1 , -1 };

        if (nums.size() == 0)
            return empty;

        int pre = 0;
        int post = nums.size() - 1;
        int mid = pre + (post - 1) / 2;
        int leftnode = nums[pre];
        int rightnode = nums[post];
        int midnode = nums[mid];

        if (leftnode == rightnode && leftnode == target)
        {
            vc.push_back(0);
            vc.push_back(nums.size() - 1);
            return vc;
        }

        //while (pre < post) 
        while (leftnode != rightnode && pre < post)
        {
            leftnode = nums[pre];
            rightnode = nums[post];
            if (leftnode < target)
                pre++;
            if (rightnode > target)
                post--;
        }
        
        if (nums[pre] == target && nums[post] == target)
        {
            vc.push_back(pre);
            vc.push_back(post);
        }
        if (vc.size() == 0)
            return empty;
        return vc;
    }
};