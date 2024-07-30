#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> find(vector<vector<int>> land, int y, int x) {
    land[y][x] = 0;
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

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int x_dir[4] = { -1,1,0,0 };
    int y_dir[4] = { 0,0,-1,1 };
    bool visited[101][101] = { false };
    return answer;
}



int main() 
{
    vector<string> maps = { "X591X", "X1X5X", "X231X", "1XXX1" };
    solution(maps);
    
}
