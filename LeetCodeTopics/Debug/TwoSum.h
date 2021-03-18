#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
	int value;
	ListNode* next;
	ListNode(int x) : value(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	
		ListNode SumTemp(0), *Sum = &SumTemp;
		int carry = 0;
		//for the first time		

		while (l1 || l2 || carry) { // l1 != NULL && l2 != NULL little copy version

			if (l1) // if l1 != NULL
			{
				carry += l1->value;
				l1 = l1->next;
			}
			if (l2)
			{
				carry += l2->value;
				l2 = l2->next;
			}

			Sum->next = new ListNode((carry % 10));
			carry /= 10;
			Sum = Sum->next;
		}


		return SumTemp.next;
	}

	void TopicAnswer()
	{
		ListNode* firstNum = new ListNode(2);
		ListNode* firstHead = firstNum;

		firstNum->next = new ListNode(4);	firstNum = firstNum->next;
		firstNum->next = new ListNode(3);	firstNum = firstNum->next;
		firstNum->next = new ListNode(8);	firstNum = firstNum->next;
		firstNum->next = new ListNode(9);	firstNum = firstNum->next;
		firstNum->next = NULL;
		// First ListNode {2,4,3,8,9}

		ListNode* secondNum = new ListNode(5);
		ListNode* secondHead = secondNum;
		secondNum->next = new ListNode(6);	secondNum = secondNum->next;
		secondNum->next = new ListNode(4);	secondNum = secondNum->next;
		secondNum->next = NULL;
		// Second ListNode {5,6,4}

		ListNode* addTwoNum;
		Solution TwoSum;

		addTwoNum = TwoSum.addTwoNumbers(firstHead, secondHead);

		while (addTwoNum != NULL) {
			cout << addTwoNum->value << " ";
			addTwoNum = addTwoNum->next;
		}
	}
};
