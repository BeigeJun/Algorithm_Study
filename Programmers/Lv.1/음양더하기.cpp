#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int len = signs.size();
    for(int i = 0 ; i < len; i++)
    {
        if(signs[i] == true)
        {
            answer += absolutes[i];
        }
        else
        {
            answer += absolutes[i] * -1;
        }
    }
    return answer;
}
