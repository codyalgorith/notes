/*simply removes multiple edges  before calculating the shortest path


example
edges 1 2 1 (u v w)
and 1 2 3
 will be present as 1 2 1in graph only

*/


#include<bits/stdc++.h>
using namespace std;
#define INF 99999999
long long dis[100020];
int p[100020];
vector< vector< pair<int,long long > > > adj;
priority_queue< pair<long long,int>  ,vector<pair<long long,int> >,greater<pair<long long ,int > > > pq;
void printpath(int src,int des)
{
	if(p[des]==-1) {cout<<des ;return ;}
	else {
		printpath(src,p[des]);
		cout<<" "<<des;

}

}
int main()
{

	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;++i)
	{
		dis[i]=INF;
		p[i]=-1;
		adj.push_back(vector<pair<int ,long long > >());
	}

	for(int i=0;i<m;++i)
	{
		int a,b;long long c;
		cin>>a>>b>>c;

		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}

	if(n==1)
	{
		cout<<"1";
		return 0;
	}
dis[1]=0;
p[1]= -1;

	 for(int i=1;i<=n;++i)
	 {
	 	sort(adj[i].begin(),adj[i].end());
	 }



	 for(int i=1;i<=n;++i)
	 {
	 	vector<pair<int ,long long > > v;

	 	for(int j=0;j<adj[i].size();++j)
	 	{
	 		if(v.size()==0)
	 		{
	 			v.push_back(adj[i][j]);
	 		}
	 		else {

	 			if(adj[i][j].first != v[v.size()-1].first)
	 			{
	 				v.push_back(adj[i][j]);
	 			}
	 		}
	 	}

	 	adj[i].clear();
	 	for(int k=0;k<v.size();++k)
	 	{
	 		adj[i].push_back(v[k]);
	 	}

	 }

	//for(int i=1;i<=n;++i)
	//{
	//	for(int j=0;j<adj[i].size();++j)
	//	{
	//		cout<<"("<<adj[i][j].first<<","<<adj[i][j].second<<") ";

	//	}
	//	cout<<"\n";
	//}

	pq.push(make_pair(0,1));

while(!pq.empty())
{

	pair<long long ,int > front=  pq.top();
	pq.pop();

	int u= front.second;
	long long d= front.first;
	//cout<<"  currently seeing "<<u<<"\n";
	if(dis[u]<d)continue;

	for(int i=0;i<adj[u].size();++i)
	{
		pair<int,long long > v= adj[u][i];

		//cout<<"under "<<u <<" talking about "<<v.first<<"\n";
		if(dis[v.first]>dis[u]+ v.second)
		{ //cout<<"hre\n";
			p[v.first]=u;

			dis[v.first]= dis[u]+ v.second;

			pq.push(make_pair(dis[v.first],v.first));
		}

	}

}
	//for(int i=1;i<=n;++i)
	//{//
	//	cout<<p[i]<<" "<<dis[i]<<"\n";
	//}
	if(p[n]==-1)
	{
		cout<<"-1\n";
		return 0;
	}

	printpath(1,n);





}
