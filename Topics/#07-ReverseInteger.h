#pragma once
#include <iostream>

class Solution {
public:
	int reverse(int x) {

		long long res = 0;
		// long , 對型態定義為 32 or 64 位元的變數之說明符(define current variable)
		// 依照平台之規範定義 - long (和指針) 為64 bit or 32 bit . win64 使用 LLP64，其中long仍為32位，long long (和指針)為64位。
		while (x) {
			res = res * 10 + x % 10;
			x /= 10;
		}
		return (res<INT_MIN || res>INT_MAX) ? 0 : res;
	}
	
	/*
	
	熟悉 C++ 內 Define， INT64_MAX、INT64_MIN、INT32_MAX、INT32_MIN

	INT16_MAX、INT16_MIN、INT8_MAX、INT8_MIN

	UINT16_MAX、UINT16_MIN、UINT32_MAX、UINT32_MIN

			res = res * 10 + x % 10;
			x /= 10;
		
	while迴圈運算，取傳入的值 mod 10 並進位至變數( self *= 10)

	（while迴圈即做進位動作，無論n位都可以倒轉）

	極其聰明的寫法（參考網路上）
	
	*/
	
	void TopicAnswer()
	{
		cout << verify.reverse(44) << endl;
	}
};