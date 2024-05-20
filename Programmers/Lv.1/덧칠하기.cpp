#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution2(int n, int m, vector<int> section) {
    if(1<=n&&n<=100000&& 1 <= m && m <= 100000)
    {
        int answer = 0;
        vector<int> bag(n);
        cout << section.size() << endl;
        for (int i = 0; i < section.size(); i++)
        {
            int temp = section[i];
            bag[temp-1] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (bag[i] == 1)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i + j != n)
                    {
                        bag[i + j] = 0;
                    }
                }
                answer++;
            }
        }
        cout << answer << endl;
        return answer;
    }
    return -1;
}
