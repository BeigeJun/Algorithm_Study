#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> m;
    for(int i = 0; i < name.size(); i++)
    {
        m[name[i]] = yearning[i];
    }
    for(int i = 0; i < photo.size();i++)
    {
        int sum = 0;
        for(int j = 0; j < photo[i].size(); j++)
        {
            for( int z = 0; z <name.size(); z++)
            {
                if(photo[i][j] == name[z])
                {
                    sum += m[name[z]];
                }
            }
        }
        answer.push_back(sum);
    }
    return answer;
}
