//kruskal bitches

//union set DS used. Check codemonk v2.0 for it

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> pipe;

vector<pair<int,pair<int,int> > > p;
int id[1000000],nodes,edges;
int x,y,weight,minimumcost,cost;

void initialise()
{
	for(int i=0;i<1000000;i++)	id[i]=i;
}

int root(int x)	//to find the parent
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void union1(int x, int y)	//to make parent
{
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}

int kruskal()	//main func.
{
	int minimumcost=0;
	for(int i=0;i<edges;i++)
	{
		x=p[i].second.first;
		y=p[i].second.second;
		cost=p[i].first;

		if(root(x)!=root(y))
		{
			minimumcost+=cost;
			union1(x,y);
		}
	}
	return minimumcost;
}

int main()
{
	initialise();
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y>>weight;
		p.push_back(pipe(weight,pii(x,y)))	;
	}
	sort(p.begin(),p.end());
	minimumcost=kruskal();
	cout<<minimumcost;
}