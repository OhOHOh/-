#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

char str[100];
int mat[][5] = {//���ȼ����� 
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 1, 1, 0, 0,
	1, 1, 1, 0, 0
};
stack<int> op;			//�����ջ
stack<double> in;		//����ջ
void GetStrNext(bool &reto, int &retn, int &i)
//reto Ϊ true ʱ����ʾ��Ԫ��Ϊ����������������֣������� retn �� 
{	
	if(i == strlen(str))//�����ַ����Ѿ������� 
	{
		reto = true;
		retn = 0;
		return;
	}
	if(str[i] >= '0'&&str[i] <= '9')//����λ������ 
	{
		reto = false;
	}//if
	else//����λ������� 
	{
		reto = true;
		switch(str[i])
		{
			case '+': {
				retn = 1;
				break;
			}
			case '-': {
				retn = 2;
				break;
			}
			case '*': {
				retn = 3;
				break;
			}
			case '/': {
				retn = 4;
				break;
			}
		}//switch
		i += 1;
		return;
	}//end else
	//������ʵ�ǵ����ʵ������ֵ������	, �����������ִ���ʾ����ֵ��� 
	retn = 0;
	for(; str[i] >= '0'&&str[i] <= '9'; i++)
	{
		retn *= 10;
		retn += str[i] - '0';
	}
	return;
}

int main()
{
	while(scanf("%s", str) != EOF)// while(gets(str) ...
	{
		if(strlen(str) <= 1)
			printf("����Ƿ���\n");
		bool retop;
		int retnum, idx = 0;
		while(op.empty() == false) 	//��շ���ջ������ջ 
			op.pop();
		while(in.empty() == false)
			in.pop();
		op.push(0);	//����ջ�ȷ�һ�� int 0 

		while(true)
		{
			GetStrNext(retop, retnum, idx);
			if(retop == false)
			{
				in.push((double)retnum);
			}//if
			else//��ǰ���ʵ��� ����� 
			{
				double tmp;
				if(op.empty() == true||mat[retnum][op.top()] == 1)//������ܷ� ��ջ
				{
					op.push(retnum);
				}
				else//���ʵ� ��������ȼ�С 
				{
					while(mat[retnum][op.top()] == 0)// ���ȼ�С��ջ������� 
					{
						int ret = op.top();
						op.pop();
						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();
						switch(ret) 
						{
							case 1: {
								tmp = a + b;
								break;
							}
							case 2: {
								tmp = a - b; 
								break;
							}
							case 3: {
								tmp = a * b;
								break;
							}
							case 4: {
								tmp = a / b;
								break;
							}
						}//switch
						in.push(tmp);
					}//while
					op.push(retnum); //����ǰ�������ѹ��ջ 
				}//else ���ʵ� ��������ȼ�С 
			}//else ��ǰ���ʵ��� �����
			if(op.size() == 2&&op.top() == 0)
				break;
		}//while(true) 
		printf("%.2f\n", in.top());		
	}
	
	return 0;
}

