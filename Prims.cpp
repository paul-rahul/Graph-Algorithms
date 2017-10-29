//dijkstra types
//better infact

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii > v[100000];
int visited[100000];
int dist[10000];

int prim(int s)
{
	memset(visited,0,sizeof(visited));
	for(int i=0;i<10000;i++)	dist[i]=INT_MAX;
	//priority_queue<pii, vector<pii>, greater<pii> > q;	//either do this or give distance in negative
	priority_queue<pii > q;
	int alpha=0;
	dist[s]=0;
	q.push(pii(0,s));
	while(!q.empty())
	{
		int q=q.top().first;
		int p=q.top().second;
		q.pop();
		if(visited[p])	continue;
		visited[p]=1;
		alpha+=q;
		for(int i=0;i<v[p].size();i++)
		{
			
			//int charlie=v[p][i].first;
			int delta=v[p][i].second;
			if(visited[delta]==0)
			{
				q.push(pii(-dist[delta],delta));
				visited[delta]=1;
			}
		}
	}
	return alpha;

}

int main()
{
	int nodes,edges,x,y,wt;
	cin>>nodes>>edges;
	for(int i=1;i<=edges;i++)
	{
		cin>>x>>y>>wt;
		v[x].push_back(pii(wt,y));
		v[y].push_back(pii(wt,x));
	}
	int ans=prim(1);
	cout<<ans;
}