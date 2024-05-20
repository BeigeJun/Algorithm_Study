#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    vector<int> last_attack_v, tmp;
    
    last_attack_v = attacks.back();
    int last_attack = last_attack_v[0];

    int health_now = health;
    
    vector<int> attack_time(attacks.size());
    vector<int> attack_demage(attacks.size());
    for (int i = 0; i < attacks.size(); i++)
    {
        tmp = attacks[i];
        attack_time[i] = tmp[0];
        attack_demage[i] = tmp[1];
    }
    int health_cnt = 0;
    int attack_cnt = 0;
    for (int i = 0; i < last_attack+1; i++)
    {
        if (i == attack_time[attack_cnt])
        {
            health_now = health_now - attack_demage[attack_cnt];
            health_cnt = 0;
            if (health_now <= 0)
            {
                return -1;
            }
            attack_cnt++;
        }
        else
        {
            health_now += bandage[1];
            health_cnt++;
            if (health_cnt == bandage[0])
            {
                health_now += bandage[2];
                health_cnt = 0;
            }
            if (health_now >= health)
            {
                health_now = health;
                if(i==0)
                {
                    health_cnt = 0;
                }
            }
        }
    }
    return health_now;
}


int main()
{
    vector<int> z = { 5,1,5 };
    int h = 30;
    vector<vector<int>> a = { {2,10},{9,15},{10,5},{11,5 } };
    cout << solution(z, h, a) << endl;
    return 0;
}
