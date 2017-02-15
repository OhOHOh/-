#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct bigInteger
{
	int digit[1000];
	int size;
	void init()
	{
		for(int i = 0; i < 1000; i++)
			digit[i] = 0;
		size = 0;
	}
	void set(char str[])//从字符串中提取整数 
	{
		init();
		int len = strlen(str);
		for(int i = len-1, j = 0, t = 0, c = 1; i >= 0; i--)
		{
			t += (str[i] - '0') * c;
			j++;
			c *= 10;
			if(j == 4||i == 0)
			{
				digit[size++] = t;
				j = 0;
				c = 1;
			}
		}
	}
	void output()//将数字高精度输出 
	{
		for(int i = size-1; i >= 0; i--)
		{
			if(i != size-1)
				printf("%04d", digit[i]);
			else
				printf("%d", digit[i]);
		}
		printf("\n");
	}
	bigInteger operator + (const bigInteger &A) const
	{
		bigInteger ret;
		ret.init();
		int carry = 0;
		for(int i = 0; i < A.size; i++)
		{
			int tmp = A.digit[i] + digit[i] + carry;
			carry = tmp / 10000;
			tmp %= 10000;
			ret.digit[ret.size++] = tmp;
		}
		if(carry != 0)
			ret.digit[ret.size++] = carry;
		
		return ret;
	}
}a, b, c;

int main()
{
	char str1[1000], str2[1000];
	while(scanf("%s%s", str1, str2) != EOF)
	{
		a.set(str1);
		b.set(str2);
		c = a + b;
		c.output();
	}
	
	
	
	return 0;
}

