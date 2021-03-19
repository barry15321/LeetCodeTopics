#pragma once

#include<iostream>
#include<vector>

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dhead = head;

        while (head && head->next)
        {
            int temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;

            head = head->next->next;
        }

        return dhead;
    }

    void TopicAnswer()
    {
        ListNode* node = new ListNode(1) , *head = node;

        node->next = new ListNode(5);
        node = node->next;
        node->next = new ListNode(8);
        node = node->next;
        node->next = new ListNode(7);
        node = node->next;
        node->next = new ListNode(16);
        node = node->next;

        ListNode* swap = swapPairs(head);

        while (swap)
        {
            cout << swap->val << " ";
            swap = swap->next;
        }
        cout << endl;
    }
};