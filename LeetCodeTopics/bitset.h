#pragma once
#include <iostream>
#include <bitset>
#include "windows.h" // for using Sleep()
using namespace std;

void beebee() {

	unsigned long long Bit = 0xFFFFFFFFFFFFFFFF;
	uint8_t a = 0x7;
	uint16_t b = Bit;
	uint32_t c = Bit;
	uint64_t d = Bit;
	//uint8_t a = 0x7 -> นอมn!

	cout << a << endl << b << endl << c << endl << d << endl;
	//

	unsigned int Test = 8;

	unsigned short short1 = 16;
	bitset<16> bitset1{ short1 };   // the bitset representation of 4  
	cout << bitset1 << endl;  // 0000000000000100  

	unsigned short short2 = short1 << 1;     // 4 left-shifted by 1 = 8  
	bitset<16> bitset2{ short2 };
	cout << bitset2 << endl;  // 0000000000001000  

	unsigned short short3 = short1 << 2;     // 4 left-shifted by 2 = 16  
	bitset<16> bitset3{ short3 };
	cout << bitset3 << endl;  // 0000000000010000  

	bitset<32> bitset64bit = Test;
	cout << bitset64bit << endl;
}