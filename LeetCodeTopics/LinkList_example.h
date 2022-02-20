#pragma once
#include <iostream>

using namespace std;

struct NODE
{
	int data;           //�s�� 
	NODE* link;         //�s�U�@�Ӹ`�I��(�a�})��}      
};

NODE* NewNode(void)
{
	NODE* pt;
	pt = (NODE*)malloc(sizeof(NODE));    //�ʺA�O����t�m
	if (pt == NULL) {                      //�S������O���� 
		cout << "�O����Ŷ�����";
		exit(1);
	}
	return pt;                  //return pt����}      
}

void coutLinklist(NODE* head)  //�p����C �q�Y�L���
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
	int i = 1; // ��ܸ`�I
	NODE* head, * temp;
	temp = NewNode();     //new�X�@�Ӹ`�I       //�Y
	head = temp;          //���ʪ�(�H�۸�Ʒs�W)�Ahead�Mtemp���V�P�@�Ӧ�}
	cout << "��ܰʧ@[1]���J���[2]�R�����[3]��ܦ�C���e[4]��ܥثe�`�I�θ�Ƥ��e[5]�e���W�@�Ӹ`�I" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "�п�J���e ";
		cin >> data;
		temp->data = data;
		temp->link = NULL;
	}
	else
	{
		cout << "�ثe��C����!!" << endl;
	}

	while (1)
	{
		cout << "��ܰʧ@[1]���J���[2]�R�����[3]��ܦ�C���e[4]��ܥثe�`�I�θ�Ƥ��e[5]�e���W�@�Ӹ`�I" << endl;
		cin >> choice;

		if (choice == 1)
		{
			temp->link = NewNode();
			temp = temp->link;
			cout << "�п�J���e ";
			cin >> data;
			i++;
			temp->data = data;
			temp->link = NULL;
		}
		if (choice == 2)
		{
			cout << "�п�J���R������� ";
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
			//delete temp; ��delete�b���̥X��
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
			cout << "�ثe��C���e�]�A: ";
			coutLinklist(head);
			//cout<<endl<<i;
		}
		if (choice == 4)
		{
			if (i > 0)
				cout << "�ثe�b�� " << i << " �Ӹ`�I�W�A��Ƥ��e�O " << choice_three(head, i) << " " << endl;
			else
				cout << "�ثe��C����!!" << endl;
		}
		if (choice == 5)
		{
			i--;
		}

	}
}



