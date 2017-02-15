#include <iostream> 
#include <string>
#include <algorithm>

using namespace std;

typedef struct Node
{
	char name[100];
	int age;
	int score;
	bool operator < (const Node &b) const  //����������� 
	{
		if(score != b.score)
			return (score < b.score);
		int tmp = strcmp(name, b.name);
		if(tmp != 0)
			return (name < b.name);
		else
			return (age < b.age);
	}
}Node;

int main()
{
	bool cmp(Node a, Node b);
	int n;
	cin >>n;
	Node *stu = new Node[n];
	for(int i = 0; i < n; i++)
	{
		cin >>stu[i].name>>stu[i].age>>stu[i].score;
	}
	//����һ , �Լ�����cmp��������Ͽ⺯�� sort 
	//sort(stu, stu+n, cmp);
	//������ ,����C++����� "<" 
	sort(stu, stu+n);
	
	cout <<"�����"<<endl;
	for(int i = 0; i < n; i++)
	{
		cout <<stu[i].name<<' '<<stu[i].age<<' '<<stu[i].score<<endl;
	}
	free(stu);
	
	return 0;
}
bool cmp(Node a, Node b)
{
	if(a.score != b.score)
		return (a.score < b.score);
	int temp = strcmp(a.name, b.name);
	if(temp != 0)
		return (temp<0);
	else 
		return (a.age < b.age);
}//end cmp

