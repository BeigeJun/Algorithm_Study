#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a;
	int b;
	int bna;
	int i;
	int sum = 0;
	scanf("%d", &a);
	for (i = 0; ; i++) {
		b = (a-5*i) / 5;
		if (b < 0)
		{
			printf("-1");
			break;
		}
		bna = a - 5*b;
		if (bna % 2 == 0)
		{
			sum = b + bna / 2;
			printf("%d", sum);
			break;
		}
	}
}
