#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int row = data.size();
    int col = data[0].size();
    vector<vector<int>> Tmp(row, vector<int>(col, 0));
    vector<int> tmp(col, 0);
    int num = 0;

    if (ext == "code")
    {
        num = 0;
    }
    else if (ext == "date")
    {
        num = 1;
    }
    else if (ext == "maximum")
    {
        num = 2;
    }
    else if (ext == "remain")
    {
        num = 3;
    }
    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        if (data[i][num] < val_ext)
        {
            answer.push_back(data[i]);
            cnt++;
        }
    }
    int row_ = answer.size();
    int col_ = answer[0].size();

    if (sort_by == "code")
    {
        num = 0;
    }
    else if (sort_by == "date")
    {
        num = 1;
    }
    else if (sort_by == "maximum")
    {
        num = 2;
    }
    else if (sort_by == "remain")
    {
        num = 3;
    }
    for (int j = 0; j < row_; j++)
    {
        for (int i = 0; i < row_ - 1; i++)
        {
            if (answer[i][num] > answer[i + 1][num])
            {
                tmp = answer[i];
                answer[i] = answer[i + 1];
                answer[i + 1] = tmp;
            }
        }
    }
    return answer;
}
