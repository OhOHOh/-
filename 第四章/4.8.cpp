#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool mark[100001]; // ������� ����ֵΪ flase ����˵����ӦΪ���� 
int prime[100001]; // �������� 
int primeSize;	   // �������� 
void init()
{
	for(int i = 0; i <= 100000; i++)
		mark[i] = false;
	primeSize = 0;
	for(int i = 2; i <= 100000; i++)
	{
		if(mark[i] == true)// i �Ǻ��� 
			continue;
		prime[primeSize++] = i;
		if(i >= 1000)
			break;
		for(int j = i * i; j <= 100000; j += i)
		{
			mark[j] = true;
		}
	}	
}


int main()
{
	init();
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int ansPrime[30];	//���ÿ�������� 
		int ansSize = 0;	//�����صĸ��� 
		int ansNum[30];		//ÿ�������ض�Ӧ�� �� 
		for(int i = 0; i < primeSize; i++)
		{
			if(n%prime[i] == 0&&n >= prime[i])
			{
				ansPrime[ansSize] = prime[i];
				ansNum[ansSize] = 0;
				while(n%prime[i] == 0)
				{
					ansNum[ansSize]++;
					n /= prime[i];					
				}//while
				ansSize++;
				if(n == 1)
					break;				
			}
		}//for
		if(n != 1)
		{
			ansPrime[ansSize] = n;
			ansNum[ansSize] = 1;
			ansSize++;
		}
		int ans = 0;
		for(int i = 0; i < ansSize; i++)
		{
			//printf("%d^%d\n", ansPrime[i], ansNum[i]);
			ans += ansNum[i];
		}
		
		printf("%d\n", ans);
	}
	
	
	return 0;
}

