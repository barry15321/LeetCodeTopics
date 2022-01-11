#pragma once
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> checklist_r, checklist_c, checklist_matrix;
    bool isValidSudoku(vector<vector<char>>& board) {

        if (board.empty())
            return false;
        //2d fix or 3d fix
        bool IsWrong = false;

        for (int i = 0; i < 9; i++)
        {
            init_checklist(checklist_c);
            init_checklist(checklist_r);

            for (int j = 0; j < 9; j++)
            {
                add_list_value(checklist_r, board[i][j]);
                add_list_value(checklist_c, board[j][i]);

                if (j == 2 || j == 5 || j == 8)
                {
                    if (i == 2 || i == 5 || i == 8)
                    {
                        init_checklist(checklist_matrix);
                        
                        for (int k = 0; k < 3; k++)
                            for (int s = 0; s < 3; s++)
                                add_list_value(checklist_matrix, board[i - k][j - s]);
                        // 2,2 2,1 2,0 1,2 1,1 1,0 0,2 0,1 0,0
                        IsWrong = IsNumValid(checklist_matrix);
                        if (!IsWrong)
                            return false;
                        //doing a 3x3 Matrix check
                    }
                }
            }

            IsWrong = IsNumValid(checklist_c);
            if (!IsWrong)
                return false;
            IsWrong = IsNumValid(checklist_r);
            if (!IsWrong)
                return false;
        }
        
        return true;
    }

    void add_list_value(vector<int>& list, char s)
    {
        if (s != '.')
            list[s - '0']++;
    }

    void init_checklist(vector<int>& list)
    {
        list.clear();
        for (int i = 0; i < 10; i++)
            list.push_back(0);
    }

    bool IsNumValid(vector<int>& list)
    {
        if (list.size() > 0)
        {
            for (int i = 0; i < 10; i++)
            {
                if (list[i] > 1)
                    return false;
            }
        }
        return true;
    }
};