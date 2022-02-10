#pragma once
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

class fkStar {
public : 

	void PrintStar(int n)
	{
		for (int i = 0; i <= n / 2; i++)
		{
			for (int j = 0; j <= (n / 2) - 1 - i; j++)
				cout << " ";
			for (int k = 0; k <= (n / 2 - 1) * i; k++)
				cout << "*";
			cout << endl;
		}
		for (int i = 0; i <= n / 2 - 1; i++)
		{
			for (int j = 0; j <= i; j++)
				cout << " ";
			for (int k = 0; k <= (n / 2 + 1) - 2 * i; k++)
				cout << "*";
			cout << endl;
		}


		/*	
		cout << endl << endl << endl;
		int i, j, k;
	
		for (i = 0; i <= 3; i++) {
			for (j = 0; j <= 2 - i; j++) {
				printf(" ");
			}
			for (k = 0; k <= 2 * i; k++) {
				printf("*");

			}
			printf("\n");

		}
		for (i = 0; i <= 2; i++) {
			for (j = 0; j <= i; j++) {
				printf(" ");

			}
			for (k = 0; k <= 4 - 2 * i; k++) {
				printf("*");

			}
			printf("\n");

		}
		*/
	}
};
