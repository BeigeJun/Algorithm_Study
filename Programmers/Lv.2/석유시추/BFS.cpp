#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int oil = 0;
queue<pair<int, int>> q;
int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,-1,1 };
bool visited[501][501] = {false};


vector<vector<int>> BFS(vector<vector<int>> land, int y, int x)
{
    int serow = land.size();
    int garow = land[0].size();

    q.push(make_pair(y,x));
    land[y][x] = 0;
    while (!q.empty())
    {
        int front_y = q.front().first;
        int front_x = q.front().second;
        q.pop();
        oil++;
        for (int i = 0; i < 4; i++)
        {
            int n_y = front_y + y_dir[i];
            int n_x = front_x + x_dir[i];
            if ((n_x < garow && n_x >= 0) && (n_y < serow && n_y  >= 0) && (land[n_y][n_x] == 1))
            {
                land[n_y][n_x] = 0;
                q.push(make_pair(n_y, n_x));
            }
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
                land = BFS(land, i, j);
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
