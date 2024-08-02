#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	unsigned long long int input;
	unsigned long long int num = 0;
	unsigned long long int sum = 0;

	scanf("%d", &input);

	for (; sum <= input;)
	{
		num = num + 1;
		sum = sum + num;
		if (input < sum)
			break;
	}
	printf("%d", num - 1);
}
