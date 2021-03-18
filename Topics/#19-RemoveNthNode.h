#pragma once
#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = head;

        if (head->next == nullptr && n == 1)
            return NULL;
        
        int Counts = 0;
        while (pre)
        {
            pre = pre->next;
            Counts++;
        }

        if (n > Counts || n < 0)
            return NULL;

        pre = head;
        if (n == 1)
        {
            while (pre->next->next)
                pre = pre->next;

            pre->next = nullptr;
        }
        else if (n == Counts)
        {
            pre = pre->next;
            head = pre;
        }
        else
        {
            for (int i = 1; i <= Counts; i++)
            {
                if (Counts - i == n)
                    pre->next = pre->next->next;
                else
                    pre = pre->next;
            }
        }


        return head;
    }

    void TopicAnswer()
    {
        ListNode* nodes = new ListNode(1);
        ListNode* head = nodes;

        nodes->next = new ListNode(2);	nodes = nodes->next;
        nodes->next = new ListNode(3);	nodes = nodes->next;
        nodes->next = new ListNode(4);	nodes = nodes->next;
        nodes->next = new ListNode(5);	nodes = nodes->next;
        
        ListNode* data = removeNthFromEnd(head, 1);
    
        print_Nodelist(data);
        
    }

    void print_Nodelist(ListNode* node)
    {
        ListNode* data = node;
        
        cout << "node list : ";
        while (data)
        {
            cout << data->val << " ";
            data = data->next;
        }
        cout << endl;
    }
};

/*

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

*/