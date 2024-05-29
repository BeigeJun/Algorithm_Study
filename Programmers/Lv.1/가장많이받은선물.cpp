#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int friend_num = friends.size();
    int gifts_num = gifts.size();
    vector<int> gisu(vector<int>(friend_num, 0));
    vector<int> will_take(vector<int>(friend_num, 0));
    vector<vector<int>> gift_move(friend_num, vector<int>(friend_num,0));

    for (int i = 0; i < gifts_num; i++)
    {
        stringstream ss(gifts[i]);
        vector<string> words;
        string word;
        int x = 0;
        int y = 0;
        while (getline(ss, word, ' ')) {
            words.push_back(word);
        }
        for (int j = 0; j < friend_num; j++)
        {
            if (words[0] == friends[j])
            {
                x = j;
            }
            if (words[1] == friends[j])
            {
                y = j;
            }
        }
        gift_move[x][y]++;
        words.clear();
    }
    
    for (int f_n = 0; f_n < friend_num; f_n++)
    {
        int give = 0;
        int take = 0;

        for (int j = 0; j < friend_num; j++)
        {
            give += gift_move[f_n][j];
        }

        for (int i = 0; i < friend_num; i++)
        {
                take += gift_move[i][f_n];
        }
        gisu[f_n] = give - take;
    }
    int a_give = 0;
    int b_give = 0;
    int plus = 0;

    for (int i = 0; i < friend_num; i++)
    {
        for (int j = plus; j < friend_num; j++)
        {
            if (gift_move[i][j] > gift_move[j][i])
            {
                will_take[i]++;
            }
            else if(gift_move[i][j] < gift_move[j][i])
            {
                will_take[j]++;
            }
            else if (gift_move[i][j] == gift_move[j][i])
            {
                if (gisu[i] > gisu[j])
                {
                    will_take[i]++;
                }
                else if (gisu[i] < gisu[j])
                {
                    will_take[j]++;
                }
            }
        }
        plus++;
    }
    for (int i = 0; i < friend_num; i++)
    {
        if (answer < will_take[i])
        {
            answer = will_take[i];
        }
    }
    return answer;
}
