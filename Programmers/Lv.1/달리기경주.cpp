#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer(players);
    map<string,int> m;
    for(int i = 0 ; i < players.size();i++)
    {
        m[players[i]] = i;
    }
    for(int i = 0 ; i < callings.size() ; i ++)
    {
        int up = m[callings[i]];
        m[answer[up-1]]+=1;
        m[callings[i]]-=1;
        
        string tmp = answer[up];
        answer[up] = answer[up-1];
        answer[up-1] = tmp;
    }
    return answer;
}
