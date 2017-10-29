//bfs for n00bies

#include<bits/stdc++.h>
using namespace std;

vector<int> v[100];
bool visited[100];

void bfs(int s)
{
	queue<int>q;
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		int p=q.front();
		cout<<p<<' ';
		q.pop();
		for(int i=0;i<v[p].size();i++)	//basically you pick up each node and visit its children
		{
			if(visited[v[p][i]]==false)
			{
				q.push(v[p][i]);
				visited[v[p][i]]=true;
			}
		}

	}
}

void initialise()
{
	for(int i=0;i<100;i++)
	{
		visited[i]=false;
	}
}
int main()
{
	int nodes_of_graph,edges_of_graph,x,y;
	cin>>nodes_of_graph>>edges_of_graph;
	for(int i=1;i<=edges_of_graph;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		//v[y].push_back(x);
	}
	initialise();
	for(int i=1;i<=nodes_of_graph;i++)
	{
		if(visited[i]==false)
		{
			bfs(i);
		}
	}
}