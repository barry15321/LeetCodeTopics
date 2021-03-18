#pragma once
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* list = new ListNode(0), *head = list;

		int sum = 0;
		while (l1 || l2 || sum) {
			if (l1) sum += l1->val, l1 = l1->next;
			if (l2) sum += l2->val, l2 = l2->next;
			list->next = new ListNode(sum % 10);
			sum /= 10;
			list = list->next;
		}
		return head->next;
	}
	
	void TopicAnswer()
	{
		ListNode *firstNum = new ListNode(2);
		ListNode *firstHead = firstNum;

		firstNum->next = new ListNode(4);	firstNum = firstNum->next;
		firstNum->next = new ListNode(3);	firstNum = firstNum->next;
		firstNum->next = NULL;
		//firstNum->next = NULL;

		ListNode *secondNum = new ListNode(5);	ListNode *secondHead = secondNum;
		secondNum->next = new ListNode(6);	secondNum = secondNum->next;
		secondNum->next = new ListNode(4);	secondNum = secondNum->next;
		secondNum->next = NULL;
		
		firstNum = firstHead;
		while (firstNum->next != NULL) {
			cout << firstNum->val << " -> ";
			firstNum = firstNum->next;
		}cout << firstNum->val << endl;
		
		secondNum = secondHead;
		while (secondNum->next != NULL) {
			cout << secondNum->val << " -> ";
			secondNum = secondNum->next;
		}cout << secondNum->val << endl;
		//print out

		ListNode *addTwoNum;
		Solution test;
			
		addTwoNum = test.addTwoNumbers(firstHead, secondHead);
		while (addTwoNum->next != NULL) 	{
			cout << addTwoNum->val << " -> ";
			addTwoNum = addTwoNum->next;
		}	cout << addTwoNum->val << endl;
		//print out
	}
};