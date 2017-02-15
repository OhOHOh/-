#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool IsPrime(int a)
{
	if(a == 1)
		return false;
	int bound = (int)sqrt(a) + 1;
	for(int i = 2; i < bound; i++)
	{
		if(a%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n ,found;
	while(scanf("%d", &n) != EOF)
	{
		found = 0;
		char *tmp = new char[n+1];
		for(int i = 0; i < n+1; i++) //��ʼ��Ϊ  '1' ��Ϊ���� 
			tmp[i] = '1';
		//tmp[1] = tmp[2] = tmp[3] = '1'; //1��2��3��������Ϊ  '1'
		for(int i = 2; i < n+1; i++)
		{
			if(tmp[i] == '1')//������ 
			{
				found = 1;
				for(int j = i; j*i < n; j++)//������Ϊ '3' 
					tmp[j*i] = '3';
				if(i%10 == 1)
					printf("%d ", i);
			}//if
			else
				continue;
		}
		if(found == 0)
			printf("-1\n");
		else
			printf("\n");
	}
	
	return 0;
}

