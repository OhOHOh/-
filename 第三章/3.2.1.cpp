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
void GetOp(bool &reto, int &retn, int &i) 
//reto Ϊ true ʱ����ʾ��Ԫ��Ϊ����������������֣������� retn �� 
{
	if(i == 0&&op.empty() == true)//�տ�ʼ�������봮 
	{
		reto = true;
		retn = 0;
		return;
	}
	if(i == strlen(str))//�����ַ����Ѿ������� 
	{
		reto = true;
		retn = 0;
		return;
	}
	if(str[i] > '0'&&str[i] < '9')//����λ������ 
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
		i += 2;
		return;
	}//end else
	//������ʵ�ǵ����ʵ������ֵ������	, �����������ִ���ʾ����ֵ��� 
	retn = 0;
	for(; str[i] != ' '&&str[i] != 0; i++)
	{
		retn *= 10;
		retn += str[i] - '0';
	}
	while(str[i] == ' ')	//���������ִ�֮���Ƿ��ǿո� 
		i++;
	return;
}

int main() 
{
	while(gets(str))// while(scanf("%s", str) ������ 
	{
		if(str[0] == 0&&str[1] == 0)
			break;
		bool retop;
		int retnum, idx = 0;
		while(!op.empty())	//��շ���ջ������ջ 
			op.pop();
		while(!in.empty())
			in.pop();

		while(true)
		{
			GetOp(retop, retnum, idx);
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

