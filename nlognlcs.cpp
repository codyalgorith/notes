//nlogn lcs
//condition elements of both sequences should be distinct 
/*logic behind this approach is very simple
take the smaller array and find an array of locations of the elements of this smaller array into larger array
now find o(nlogn) lis in this array formed 
which is the answer also
*/
#include<iostream>
#include<cstring>

using namespace std;

int mapper[50000];
int a[50000];
int b[50000];
int r[50000];
int k;
int ceilbinary(int t[50000],int beg,int end,int item)
{
	if(t[end]<item) return -1;
	
	
	while(beg<end)
	{
		int mid=(beg+end)/2;
		if(t[mid]==item)return mid;
		else if(t[mid]<item)beg=mid+1;
		else end=mid;
		
		
		
		
	}
	return end;
}
int lis()
{
	int t[50000];
	int sizeoflis=1;
	
	t[0]=r[0];
	for(int i=1;i<k;++i)
	{
		if(r[i]>t[sizeoflis-1])
		{
			t[sizeoflis]=r[i];
			sizeoflis++;
		}
		else{
			int pos=ceilbinary(t,0,sizeoflis-1,r[i]);
			t[pos]=r[i];
		}
	}
	
	return sizeoflis;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	memset(mapper,-1,sizeof(mapper));
	int answer;
if(n>m)
{
		
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		mapper[a[i]]=i;
	}
	 k=0; //size of array r
	for(int j=0;j<m;++j)
	{
		scanf("%d",&b[j]);
		
		if(mapper[b[j]]!=-1)
		{
			r[k]=mapper[b[j]];
			k++;
		}
	}
	
 answer=lis();//now lis on r
}
else{ //if n<m
		
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	
	for(int i=0;i<m;++i)
	{
		scanf("%d",&b[i]);
		mapper[b[i]]=i;
	}
	k=0;
	for(int j=0;j<n;++j)
	{
	//	scanf("%d",&b[j]);
		
		if(mapper[a[j]]!=-1)
		{
			r[k]=mapper[a[j]];
			k++;
		}
	}
 answer=lis();//now lis on r
}
	printf("%d\n",answer);
	
	
	
}
