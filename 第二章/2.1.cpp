#include <iostream> 
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	bool cmp(int x, int y);
	int n, temp;
	cin >>n;
	int *data = new int[n];
	for(int i = 0; i < n; i++)
		cin >>data[i];
	
	/*for(int i = 0; i < n; i++)  	//ð������ 
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(data[j] > data[j+1])
			{
				temp = data[j+1];
				data[j+1] = data[j];
				data[j] = temp;
			} 
		}//end for'
	}*/
	//sort(data,data+n);			    //�ÿ⺯�������� 
	sort(data, data+n, cmp);			//�������� 
	
	
	
	for(int i = 0; i < n; i++)
		cout <<data[i]<<' ';
	cout <<endl;
	
	return 0;
}
bool cmp(int x, int y)
{
	return x > y;
}

