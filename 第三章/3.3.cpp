#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

//priority_queue<int> Q;	//����� 
priority_queue< int, vector<int>, greater<int> > Q; //С���� 

int main()
{
	int n, x;
	while(scanf("%d", &n) != EOF)
	{
		while(Q.empty() == false) //��ն� 
			Q.pop();
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			Q.push(x);
		}
		int ans = 0;
		while(true)
		{
			if(Q.size() == 1)
				break;
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			ans += a + b;
			Q.push(a+b);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}

