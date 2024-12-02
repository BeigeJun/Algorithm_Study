#include<stdio.h>
#include <stdlib.h>
int Ejin(int a, int ab[], int s, int e)
{
	int m = (s + e) / 2;
	if (s == m || m == e)
	{
		if (a == ab[m])
		{
			return 1;
		}
		return 0;
	}
	if (ab[m] == a)
	{
		return 1;
	}
	else if (ab[m] < a)
	{
		Ejin(a, ab, m, e);
	}
	else if(ab[m]>a)
	{
		Ejin(a, ab, s, m);
	}
}
int cmp(const void* a, const void* b) {
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}
int main(void)
{
	int a;
	int ab[100000] = { 0, };
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &ab[i]);
	}


	int b;
	int bb[100000] = { 0, };
	scanf("%d", &b);
	for (int i = 0; i < b; i++)
	{
		scanf("%d", &bb[i]);
	}
	qsort(ab, a, sizeof(int), cmp);

	for (int i = 0; i < b; i++)
	{
		int z = Ejin(bb[i], ab, 0, a);
		printf("%d\n",z );
	}

}
