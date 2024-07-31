#include <string>
#include <vector>
#include <iostream>
using namespace std;

int sum = 0;

void find(vector<string>& land, int y, int x) {
    sum += stoi(string(1, land[y][x]));
    land[y][x] = 'X';
    int serow = land.size();
    int garow = land[0].size();

    if (x + 1 < garow && land[y][x + 1] != 'X') {
        find(land, y, x + 1);
    }
    if (y + 1 < serow && land[y + 1][x] != 'X') {
        find(land, y + 1, x);
    }
    if (x - 1 >= 0 && land[y][x - 1] != 'X') {
        find(land, y, x - 1);
    }
    if (y - 1 >= 0 && land[y - 1][x] != 'X') {
        find(land, y - 1, x);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int serow = maps.size();
    int garow = maps[0].size();

    for (int i = 0; i < serow; i++) {
        for (int j = 0; j < garow; j++) {
            if (maps[i][j] != 'X') {
                sum = 0;
                find(maps, i, j);
                if (sum != 0) {
                    answer.push_back(sum);
                }
            }
        }
    }
    if (answer.empty())
        answer.push_back(-1);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = i; j < answer.size(); j++)
        {
            if (answer[i] > answer[i + 1])
            {
                int tmp = answer[i];
                answer[i] = answer[j];
                answer[j] = tmp;
            }
        }
    }
    return answer;
}
