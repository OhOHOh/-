#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node
{
	Node *lchild;
	Node *rchild;
	char ch;
}Tree[50];
int loc;//ÿ�γ�ʼ��Ϊ 0 
char str1[27], str2[27];
Node *creat()
{
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}
void PostOrder(Node *T) //������� 
{
	if(T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", T->ch);
	}
}
Node *Build(int s1, int e1, int s2, int e2)
//��ǰ�������������� ��ԭ ����������������ڵ㣬ǰ��������Ϊ�� str1[s1] �� str1[e1] 
{
	Node *ret = creat();
	ret->ch = str1[s1];
	int rootIdx;
	for(int i = s2; i <= e2; i++)//�ҵ����ڵ� 
	{
		if(str2[i] == ret->ch)
		{
			rootIdx = i;
			break;
		}
	}//for
	if(rootIdx != s2)
		ret->lchild = Build(s1+1, s1+rootIdx-s2, s2, rootIdx-1);
	if(rootIdx != e2)
		ret->rchild = Build(s1+rootIdx-s2+1, e1, rootIdx+1, e2);
	return ret;
	
}//end Build

int main()
{	
	while(scanf("%s%s", str1, str2) != EOF)
	{
		loc = 0;
		int L1 = strlen(str1);
		int L2 = strlen(str2);
		Node *T = Build(0, L1-1, 0, L2-1);
		PostOrder(T);
		printf("\n");
	}
	
	return 0;
}

