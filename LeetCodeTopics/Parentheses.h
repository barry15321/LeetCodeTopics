#pragma once
#include<vector>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
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