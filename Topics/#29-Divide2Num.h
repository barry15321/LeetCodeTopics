#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
public : 
	int divide(int dividend, int divisor) {
		// divisor != 0
		if (dividend == 0) return 0;
		if (divisor == 1) return dividend;
		if (dividend == INT_MIN and divisor == -1) return INT_MAX;
		if (divisor == -1) return -dividend;
		if (divisor == INT_MIN) return (dividend == divisor) ? 1 : 0;
		
		int sign = 1; // sign 只是為了辨別 分母分子是否相同為正整數/負整數
		if (dividend > 0 and divisor < 0) sign = -1;
		if (dividend < 0 and divisor > 0) sign = -1;
		// int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; // equal
		// ^ = XOR
		int ans = 0;

		if (dividend == INT_MIN) // -2^31 = INT_MIN , 2^31=INT_MAX
		{
			ans = 1;
			dividend += (divisor < 0) ? -divisor : divisor;
		}

		dividend = abs(dividend);
		divisor = abs(divisor);

		while (dividend >= divisor) {
			int tmp = divisor;
			int num = 1;
			while (dividend - tmp >= tmp) {
				tmp <<= 1;
				num <<= 1;
			}
			dividend -= tmp;
			ans += num;
		}

		return (sign == 1) ? ans : -ans;		
	};

	void TopicAnswer() {};
private:
};