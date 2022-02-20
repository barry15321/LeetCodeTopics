#pragma once
#include <iostream>
#include <fstream>
using namespace std;

/*
		ofstream   //�ɮ׼g�ާ@ �O����g�J�x�s�˸m
		ifstream   //�ɮ�Ū�ާ@�A�x�s�˸mŪ�Ϩ�O���餤
		fstream    //Ū�g�ާ@�A��}�Ҫ��ɮץi�i��Ū�g�ާ@

		�}���ɮת��覡�biOS��(�ҥH�y��I/O������)���w�q�A���p�U�X�ؤ覡�G
		(ios_base::open_mode)

		ios::in	����J(Ū)�Ӷ}���ɮ�
		ios::out	����X(�g)�Ӷ}���ɮ�
		ios::ate	��l��m�G�ɮק�
		ios::app	�Ҧ���X���[�b�ɮץ���
		ios::trunc	�p�G�ɮפw�s�b�h���R�����ɮ�
		ios::binary	�G�i���覡
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