#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii > v[100000];
int fat[100000];
int dist[10000];

int prim(int s)
{
	memset(fat,0,sizeof(fat));
	for(int i=0;i<10000;i++)	dist[i]=INT_MAX;
	//priority_queue<pii, vector<pii>, greater<pii> > q;
	priority_queue<pii > q;
	int alpha=0;
	dist[s]=0;
	q.push(pii(0,s));
	while(!q.empty())
	{
		int q=q.top().first;
		int p=q.top().second;
		q.pop();
		if(fat[p])	continue;
		fat[p]=1;
		alpha+=q;
		for(int i=0;i<v[p].size();i++)
		{
			
			//int charlie=v[p][i].first;
			int delta=v[p][i].second;
			if(fat[delta]==0)
			{
				q.push(pii(-dist[delta],delta));
				fat[delta]=1;
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