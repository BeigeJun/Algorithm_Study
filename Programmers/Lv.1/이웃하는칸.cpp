#include <string>
#include <vector>

using namespace std;
int x_m[4] = {1,-1,0,0};
int y_m [4] = {0, 0,1,-1};
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string color = board[h][w];
    int row = board[0].size();
    int col = board.size();
    for (int i = 0; i < 4; i++)
    {
        int n_x = w + x_m[i];
        int n_y = h + y_m[i];
        if ((n_x >= 0 && n_x < row) && (n_y >= 0 && n_y < col))
        {
            if (board[n_y][n_x] == color)
            {
                answer++;
            }
        }
    }
    return answer;
}
