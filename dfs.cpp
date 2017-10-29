#include<iostream>
#include<vector>

using namespace std;

vector<int>v[10];
bool fat[10];
	
void dfs(int s)
{
	fat[s]=true;
	for(int i=0;i<v[s].size();i++)
	{
		if(fat[v[s][i]]==false)
		{
			dfs(v[s][i]);
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
	ios::sync_with_stdio(0), cin.tie(0);
	int nodes,edges,x,y,connectedcomponents=0;
	cin>>nodes>>edges;
	for(int i=1;i<=edges;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
	}
	initialise();
	for(int i=1;i<=nodes;i++)
	{
		if(fat[i]==false)
		{
			dfs(i);
			connectedcomponents++;
		}
	}
	cout<<connectedcomponents;
}