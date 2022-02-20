#pragma once
#include <iostream>
#include <string> 
using namespace std;

class friendFunction
{
	public:
		friendFunction(int temp);
		friend void Printout(friendFunction f);
		//friend function is able to access private 
	private:
		int i;
		void privatefunc();
};

friendFunction::friendFunction(int temp)
{
	i = temp;
}

void Printout(friendFunction f)
{
	//friend function is able to access private 
	cout << f.i << endl;
	f.privatefunc();
}

void friendFunction::privatefunc()
{
	cout << "Private!" << endl;
}

class SubFriendFunction
{
	public:
		SubFriendFunction(int temp);
		friend class friendFunction;
		//friend class to access
		void PrintOut();
	private:
		int i;
};

SubFriendFunction::SubFriendFunction(int temp)
{
	i = temp;
}

void SubFriendFunction::PrintOut()
{
	cout << "i = " << i << endl;
}

/* SubFriendFunction is not constructed yet. */

void Test_FriendClass()
{
	friendFunction f(3);
	Printout(f);
}
