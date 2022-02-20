#pragma once
#include<iostream>
#include<vector>
using namespace std;

public class Solution {
    
    public bool IsValid(string s)
        {
            bool IsCorrect = true;

            Stack<char> stack = new Stack<char>();
            int LeftBrackets = 0, RightBrackets = 0;
            for (int i = 0; i < s.Count(); i++)
            {
                if (IsLeftBrackets(s[i]))
                {
                    LeftBrackets++;
                    stack.Push(s[i]);
                }
                else if (IsRightBrackets(s[i]))
                {
                    RightBrackets++;
                    if (stack.Count <= 0)
                        return false;

                    char pair_c = stack.Pop();
                    char vs_c = getParentPair(s[i]);

                    if (pair_c != vs_c)
                        return false;
                }
            }

            IsCorrect = LeftBrackets == RightBrackets;
            return IsCorrect;
        }

        private bool IsLeftBrackets(char c)
        {
            if (c == '[' || c == '{' || c == '(' || c == '<')
                return true;
            else
                return false;
        }

        private bool IsRightBrackets(char c)
        {
            if (c == ']' || c == '}' || c == ')' || c == '>')
                return true;
            else
                return false;
        }

        private char getParentPair(char c)
        {
            if (c == ']')
                return '[';
            else if (c == '}')
                return '{';
            else if (c == ')')
                return '(';
            else if (c == '>')
                return '<';
            else
                return ' ';
        }

}

class Recursive_Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string>& res) {
        if (left > right) return;
        if (left == 0 && right == 0)    res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }

    void TopicAnswer()
    {
        vector<string> ary =  generateParenthesis(3);
        for (int i = 0; i < ary.size(); i++)
            cout << ary[i] << endl;        
    }

};


/*

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

*/