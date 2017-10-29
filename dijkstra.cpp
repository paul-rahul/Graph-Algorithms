//Like if our shortest path is 1 4 3 5
//So what would happen is it would store 1 in position of 4 and so forth

#include<bits/stdc++.h>
#define inf 0x7fffffff

using namespace std;

typedef pair<int,int> pii;

vector<pii> v[100005];
int fat[100005];
int e[100005];
int preev[100005];

void printpath(int src)
{
	if(preev[src]!=-1)	
	printpath(preev[src]);
	cout<<src<<" ";
}
void dijkstra(int x)
{
	int p,alpha,delta,whiskey,b;
	//priority_queue<pii,vector< pii >,greater< pii > > q;
	priority_queue<pii > q;	
	e[x]=0;
	q.push(pii(0,x));
	while(!q.empty())
	{
		p=q.top().second;	//node
		//alpha=q.top().first;	//node weight	
		q.pop();
        if(fat[p])	continue;
        fat[p]=1;
        for(b=0;b<v[p].size();b++)
		{
			delta=v[p][b].first;	//node
			whiskey=v[p][b].second;	//w8 m8

			if((!fat[delta]) && e[p]+whiskey<e[delta])
			{
				e[delta]=e[p]+whiskey;
				q.push(pii(-e[delta],delta));
				preev[delta]=p;
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int nodes,edges,x,y,wt,start;
	cin>>nodes>>edges;
	for(int i=1;i<=nodes;i++) v[i].clear();
	for(int i=1;i<=edges;i++)
	{
		cin>>x>>y>>wt;;
		v[x].push_back(pii(y,wt));
		v[y].push_back(pii(x,wt));
	}
	start=1;
	// memset(e,inf,sizeof(e));
	// memset(fat,0,sizeof(fat));
	// memset(preev,-1,sizeof(preev));
	for(int i=1;i<=nodes;i++)	e[i]=inf;
	for(int i=1;i<=nodes;i++)	fat[i]=0;
	for(int i=1;i<=nodes;i++)	preev[i]=-1;
	dijkstra(start);
	if(e[nodes]==inf)	cout<<"-1"<<endl;	//For taking out the nodes through which have been incase of shortest path.
	else printpath(nodes);		//This recursive function stores value of current node in prev node so that we can jump back.
}