#include <string>
#include <vector>
#include <iostream>
using namespace std;

int oil = 0;

vector<vector<int>> find(vector<vector<int>> land, int y, int x) {
    land[y][x] = 0;
    oil++;
    int serow = land.size();
    int garow = land[0].size();
    if (x + 1 < garow)
    {
        if (land[y][x + 1] == 1)
        {
            land = find(land, y, x + 1);
        }
    }
    if (y + 1 < serow)
    {
        if (land[y + 1][x] == 1)
        {
            land = find(land, y + 1, x);
        }
    }
    if (x - 1 >= 0)
    {
        if (land[y][x - 1] == 1)
        {
            land = find(land, y, x - 1);
        }
    }
    if (y - 1 >= 0)
    {
        if (land[y - 1][x] == 1)
        {
            land = find(land, y - 1, x);
        }
    }
    return land;
}

int solution(vector<vector<int>> land) {
    vector<int> oil_cnt;
    vector<vector<int>> land_back = land;
    int answer = 0;
    int max_land = land[0].size();
    int max_deep = land.size();
    for (int j = 0; j < max_land; j++)
    {
        for (int i = 0; i < max_deep; i++)
        {
            if (land[i][j] == 1)
            {
                land = find(land, i, j);
            }
        }
        oil_cnt.push_back(oil);
        oil = 0;
        land = land_back;
    }
    answer = oil_cnt[0];
    if (oil_cnt.size() > 1)
    {
        for (int i = 1; i < oil_cnt.size(); i++)
        {
            if (answer < oil_cnt[i])
            {
                answer = oil_cnt[i];
            }
        }
    }
    return answer;
}
