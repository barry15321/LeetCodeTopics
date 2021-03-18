#pragma once
#include<cmath>
#include<sstream>
#include<cstring>
#include<string>

using namespace std;

class Solution
{
public:
    bool isNumber(string s) {
        return isValidInteger(s) || isValidDecimal(s) || isValidExponent(s);
    }

    bool isValidDigit(char ch)
    {
        if (ch >= '0' && ch <= '9') return true;
        else return false;
    }

    bool isValidSeriesOfDigits(string s)
    {
        for (char ch : s)
        {
            if (!isValidDigit(ch)) return false;
        }
        return true;
    }

    bool isSigned(string s)
    {
        if (s[0] == '+' || s[0] == '-') return true;
        else return false;
    }

    bool isValidInteger(string s)
    {
        if (isSigned(s))
        {
            s = s.substr(1);
            return !s.empty() && isValidSeriesOfDigits(s); // Just sign with no number is not allowed
        }
        else
            return isValidSeriesOfDigits(s);
    }

    bool isValidDecimal(string s)
    {
        if (isSigned(s)) s = s.substr(1);
        int dot_pos = s.find(".");
        if (dot_pos == string::npos) return false;

        string prefix = s.substr(0, dot_pos);
        string suffix = s.substr(dot_pos + 1);
        return !(prefix.empty() && suffix.empty()) &&
            isValidSeriesOfDigits(prefix) && isValidSeriesOfDigits(suffix);
    }

    bool isValidExponent(string s)
    {
        if (isSigned(s)) s = s.substr(1);
        int e_pos = s.find_first_of("eE");
        if (e_pos == string::npos) return false;

        string prefix = s.substr(0, e_pos);
        string suffix = s.substr(e_pos + 1);
        return !prefix.empty() && !suffix.empty() &&
            (isValidSeriesOfDigits(prefix) || isValidDecimal(prefix)) &&
            isValidInteger(suffix);
    }

	// simliar way to this discuss to solve this problem , but he did better than mine.
	// https://leetcode.com/problems/valid-number/discuss/1098778/Very-simple-elegant-layered-solution-in-C%2B%2B

	void TopicAnswer()
	{
		cout << isNumber(".1") << endl;
	}
};
