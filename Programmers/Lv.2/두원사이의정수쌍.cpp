#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
struct Point
{
    int x;
    int y;
};

bool Euclidiean_Distance(Point a, Point b, int r1, int r2)
{
    double dbDistance = sqrt((b.x - a.x) * (b.x - a.x) +(b.y - a.y) * (b.y - a.y));
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
            Point PMade, PCenter;
            PMade.x = i;
            PMade.y = j;
            PCenter.x = 0;
            PCenter.y = 0;
            if(Euclidiean_Distance(PMade, PCenter,r1,r2))
                answer+=1;
        }
    }
    return answer;
}
