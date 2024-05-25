#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int col = wallpaper.size();
    int row = wallpaper[0].size();
    int col_min = col;
    int col_max = 0;
    int row_min = row;
    int row_max = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (wallpaper[j][i] == '#')
            {
                if (col_min > j)
                {
                    col_min = j;
                }
                if (col_max < j)
                {
                    col_max = j;
                }
                if (row_min > i)
                {
                    row_min = i;
                }
                if (row_max < i)
                {
                    row_max = i;
                }
            }
        }
    }
    answer.push_back(col_min);
    answer.push_back(row_min);
    answer.push_back(col_max+1);
    answer.push_back(row_max+1);
    return answer;
}
