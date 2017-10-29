#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[10];
bool fat[10];

void bfs(int s)
{
	queue<int>q;
	q.push(s);
	fat[s]=true;
	while(!q.empty())
	{
		int p=q.front();
		cout<<p<<' ';
		q.pop();
		for(int i=0;i<v[p].size();i++)
		{
			if(fat[v[p][i]]==false)
			{
				q.push(v[p][i]);
				fat[v[p][i]]=true;
			}
		}

	}
}

void initialise()
{
	for(int i=0;i<10;i++)
	{
		fat[i]=false;
	}
}
int main()
{
	int nodes,edges,x,y;
	cin>>nodes>>edges;
	for(int i=1;i<=edges;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		//v[y].push_back(x);
	}
	initialise();
	for(int i=1;i<=nodes;i++)
	{
		if(fat[i]==false)
		{
			bfs(i);
		}
	}
}