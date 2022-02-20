#pragma once
#include <iostream>
#include <queue>
#include <map>
using namespace std;

void using_map_practice()
{
	string str = "aaabbccbbdd"; // iterator , std::map , std::pair , std::insert , std::find
	map<char, int> mp;

	for (int i = 0; i < str.length(); i++)
	{
		std::map<char, int>::iterator it = mp.find(str[i]);
		if (it != mp.end())
		{
			mp[str[i]]++;
		}
		else
			mp.insert(std::pair<char, int>(str[i], 0));
	}

	int max = 0;
	char letter = ' ';
	cout << ":: " << mp.size() << endl;
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		cout << it->first << " = " << it->second << '\n';
		if (it->second > max)
		{
			max = it->second;
			letter = it->first;
		} 
	}

	cout << max << " , " << letter << endl;
	// map = dictionary , it->first , it->second = map(key,value)
	// key = alphabet , value = occur times
}


void using_vector_practice()
{

}

void using_queue_practice()
{

}

void using_set_practice()
{

}