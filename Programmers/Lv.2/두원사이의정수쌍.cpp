#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool Euclidiean_Distance(int x1, int y1, int x2, int y2, int r1, int r2)
{
    double dbDistance = sqrt((x2 - x1) * (x2 - x1) +(y2 - y1) * (y2 - y1));
    if (dbDistance >= r1 && dbDistance <= r2)
        return true;
    else
        return false;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    for (int i = -r2; i <= r2; i++)
    {
        for (int j = -r2; j <= r2; j++)
        {
            if(Euclidiean_Distance(i,j, 0,0,r1,r2))
                answer+=1;
        }
    }
    return answer;
}
