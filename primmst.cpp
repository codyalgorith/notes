/*prim's algorithm*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
vector<vector< pair<int,int> > >adj;
int taken[3200]={0};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    for(int i=0;i<=3000;++i)
    {
        adj.push_back(vector<pair<int,int> >());
    }
    int n,m;
    scanf("%d %d",&n,&m);
    //input graph 
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back(make_pair(b,c));
        
        adj[b].push_back(make_pair(a,c));
        
        
        
    }
    int source;
    scanf("%d",&source);
    long long mstcost=0;
    
    priority_queue< pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > >  pq;//syntax for using priority queue as min heap
    pq.push(pair<int,int>(0,source));
    taken[source]=1;
    //enqueing all the neighbours of source into pq
    for(int i=0;i<adj[source].size();++i)
    {
        pair<int,int> neigh=adj[source][i];
        if(taken[neigh.first]==0)
        {
            pq.push(pair<int,int>(neigh.second,neigh.first));
        }
    }
    while(!pq.empty())
    {
        pair<int,int> front=pq.top();//taking top of priority queue weight,vertice pair
        pq.pop();
        int weight=front.first;  //next minimum weight to be added to mst (if not already added)
        int u=front.second;//this vertice to be added if not already added and cycle is not possible
       if(taken[u]==0){ 
           taken[u]=1;  //now included
           mstcost+=(long long)weight;//weight increased
           for(int i=0;i<adj[u].size();++i)
            {
            pair<int,int> neigh=adj[u][i];
               if(taken[neigh.first]==0)  //neigh will be pushed in if its not already there
               {
                   pq.push(pair<int,int>(neigh.second,neigh.first));
               }
                }
             }
    }
    printf("%lld\n",mstcost);
    return 0;
}
