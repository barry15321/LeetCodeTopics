#pragma once
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* data = new ListNode(), * head = data;
        vector<int> ary;
        
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while (temp)
            {
                ary.push_back(temp->val);
                temp = temp->next;
            } 
        }

        std::sort(ary.begin(), ary.end());

        if (ary.size() == 0)
            return NULL;
        
        data->val = ary[0];
        for (int i = 1; i < ary.size(); i++)
        {
            data->next = new ListNode(ary[i]);
            data = data->next;
        }

        return head;
    }

    void TopicAnswer()
    {
        vector<ListNode*> vec;
        vec.push_back(NULL);
        vec.push_back(NULL);
        vec.push_back(NULL);

        ListNode* node = mergeKLists(vec);
        
        if (node != NULL)
        {
            while (node)
            {
                cout << node->val << " ";
                node = node->next;
            }
            cout << endl;
        }
        else
            cout << "NULL" << endl;
    }
};