#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, x;
	int *score = new int[100];
	while(scanf("%d", &n) != EOF&&n != 0)
	{
		int *stu = new int[n];
		for(int i = 0; i < 100l; i++)
		{
			score[i] = 0;
		}
		printf("���������\n");
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			score[x]++;
		}
		scanf("%d", &x);
		printf("����Ϊ��%d\n", score[x]);
	}
	
	return 0;
}

