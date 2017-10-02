#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<pair<int,pair<int,int> > >  edgelist;
int p[3100];
int rnk[3100]={0};
int findset(int i)
{
    if(i==p[i])return i;
    else return p[i]=findset(p[i]);
}
void unionset(int a,int b)
{
    if(findset(a)!=findset(b))
    {
        int x=findset(a);
        int y=findset(b);
        if(rnk[x]>rnk[y])
        {
            p[y]=x;
            
        }
        else{
            p[x]=y;
            if(rnk[x]==rnk[y])rnk[y]++;
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    int m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        rnk[i]=0;
        p[i]=i;
    }
    for(int i=0;i<m;++i)
    {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        edgelist.push_back(make_pair(w,pair<int,int>(a,b)));
        
        
    }
    sort(edgelist.begin(),edgelist.end());
    int count=0;//when count reaches n-1 we are done 
    long long totalcost=0;
    for(int i=0;i<m&&count<n;++i)
    {
        pair<int,pair<int,int> > v=edgelist[i];
        if(findset(v.second.first)!=findset(v.second.second))
        {
            totalcost+=(long long)(v.first);
            count++;
            unionset(v.second.second,v.second.first);
        }
    }
    printf("%lld\n",totalcost);
    return 0;
}
