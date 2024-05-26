#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int x_m[4] = { 1, -1, 0, 0 };
int y_m[4] = { 0, 0, 1, -1 };

int BFS(vector<string> maps, int s_x, int s_y, int row, int col) 
{
    int answer = -1;
    bool check_L = false;
    bool check_E = false;
    queue<pair<int, int>> q;
    vector<string> maps_cpy = maps;
    vector<vector<int>> visit(maps.size(), vector<int>(maps[0].size(), 0));

    q.push(make_pair(s_y, s_x));
    int y = 0;
    int x = 0;
    while (!q.empty()) 
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        if (maps[y][x] == 'L'&& check_L == false)
        {
            check_L = true;
            int cnt = visit[y][x];

            q = queue<pair<int, int>>();
            fill(visit.begin(), visit.end(), vector<int>(visit[0].size(), 0));

            visit[y][x] = cnt;
        }
        else if (maps[y][x] == 'E' && check_L)
        {
            answer = visit[y][x];
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int n_y = y + y_m[i];
            int n_x = x + x_m[i];

            if (n_y >= 0 && n_y < col && n_x >= 0 && n_x < row)
            {
                if (maps[n_y][n_x] != 'X' && visit[n_y][n_x] == 0)
                {
                    q.push(make_pair(n_y, n_x));
                    visit[n_y][n_x] = visit[y][x] + 1;
                }
            }
        }
    }
    return answer;
}

int solution(vector<string> maps) 
{
    int answer_ = -1;
    int start_x = -1;
    int start_y = -1;
    int row = maps[0].size();
    int col = maps.size();

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (maps[i][j] == 'S') {
                answer_ = BFS(maps, j, i, row, col);
                break;
            }
        }
    }

    return answer_;
}
