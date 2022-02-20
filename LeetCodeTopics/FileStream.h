#pragma once
#include <iostream>
#include <fstream>
using namespace std;

/*
		ofstream   //檔案寫操作 記憶體寫入儲存裝置
		ifstream   //檔案讀操作，儲存裝置讀區到記憶體中
		fstream    //讀寫操作，對開啟的檔案可進行讀寫操作

		開啟檔案的方式在iOS類(所以流式I/O的基類)中定義，有如下幾種方式：
		(ios_base::open_mode)

		ios::in	為輸入(讀)而開啟檔案
		ios::out	為輸出(寫)而開啟檔案
		ios::ate	初始位置：檔案尾
		ios::app	所有輸出附加在檔案末尾
		ios::trunc	如果檔案已存在則先刪除該檔案
		ios::binary	二進位制方式
*/

void load_ifStream()
{
	ifstream file;
	string str;
	file.open("hello.txt"); // directory

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> str;
			cout << str << endl;
		}
	}
	else
		cout << "Fail open file!" << endl;

}

void load_ofstream()
{
	ofstream file("testfile.txt");
	// fstream file
	// file.open("testfile.txt", ios::out);

	if (file.is_open())
	{
		file << "we have added a file" << endl;
		file.close();

	}
	else
		cout << "Fail open file!" << endl;
}