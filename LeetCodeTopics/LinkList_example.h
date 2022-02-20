#pragma once
#include <iostream>

using namespace std;

struct NODE
{
	int data;           //存值 
	NODE* link;         //存下一個節點的(地址)位址      
};

NODE* NewNode(void)
{
	NODE* pt;
	pt = (NODE*)malloc(sizeof(NODE));    //動態記憶體配置
	if (pt == NULL) {                      //沒有拿到記憶體 
		cout << "記憶體空間不足";
		exit(1);
	}
	return pt;                  //return pt的位址      
}

void coutLinklist(NODE* head)  //聯結串列 從頭印到尾
{
	NODE* temp = head;

	while (temp != NULL)
	{
		//cout << "temp->data: "  << temp->data <<  "\ttemp's address: "  << temp << "\ttemp->link: " << temp->link << endl;             
		cout << temp->data << " ";
		temp = temp->link;
	}

}

int choice_three(NODE* head, int i)
{
	NODE* temp = head;
	for (int k = 1; k < i; k++)
	{
		temp = temp->link;
	}

	return temp->data;
}

void insert(NODE* P, NODE* R)
{
	R->link = P->link;
	P->link = R;
}

void implement_LinkedList() {
	int data, choice;
	// NODE *temp;
	int i = 1; // 顯示節點
	NODE* head, * temp;
	temp = NewNode();     //new出一個節點       //頭
	head = temp;          //移動的(隨著資料新增)，head和temp指向同一個位址
	cout << "選擇動作[1]插入資料[2]刪除資料[3]顯示串列內容[4]顯示目前節點及資料內容[5]前往上一個節點" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "請輸入內容 ";
		cin >> data;
		temp->data = data;
		temp->link = NULL;
	}
	else
	{
		cout << "目前串列為空!!" << endl;
	}

	while (1)
	{
		cout << "選擇動作[1]插入資料[2]刪除資料[3]顯示串列內容[4]顯示目前節點及資料內容[5]前往上一個節點" << endl;
		cin >> choice;

		if (choice == 1)
		{
			temp->link = NewNode();
			temp = temp->link;
			cout << "請輸入內容 ";
			cin >> data;
			i++;
			temp->data = data;
			temp->link = NULL;
		}
		if (choice == 2)
		{
			cout << "請輸入欲刪除的資料 ";
			cin >> data;
			int num = 1;
			i--;
			temp = head;
			while (temp != NULL)
			{
				if (temp->data == data)
					break;
				else
				{
					temp = temp->link; num++;
				}
			}
			//delete temp; 問delete在哪裡出錯
			num--;
			NODE* front;
			front = head;
			for (int k = 1; k < num; k++)
			{
				front = front->link;
			}

			//cout<<temp->data<<endl;
			num += 2;
			NODE* second;
			second = head;
			for (int k = 1; k < num; k++)
			{
				second = second->link;
			}
			//cout<<temp->data<<endl;
			front->link = second;

		}
		if (choice == 3)
		{
			cout << "目前串列內容包括: ";
			coutLinklist(head);
			//cout<<endl<<i;
		}
		if (choice == 4)
		{
			if (i > 0)
				cout << "目前在第 " << i << " 個節點上，資料內容是 " << choice_three(head, i) << " " << endl;
			else
				cout << "目前串列為空!!" << endl;
		}
		if (choice == 5)
		{
			i--;
		}

	}
}



