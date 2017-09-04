#include<iostream>
#include<cstring>
using namespace std;
void kmp(char text[10000],char pat[10000])
{
	int lps[10000];
	
	lps[0]=0;
	int n=strlen(text);
	int  m=strlen(pat);
	int i=1;int j=0;
	//preprocessing
	while(i<m)
	{
		if(pat[i]==pat[j])
		{
			lps[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j!=0)
			{
				j=lps[j-1];
				
			}
			else{
				lps[i]=0;
				i++;
			}
	
		}
	}

		//actual string matching
		
		
	i=0;
	j=0;
		while(i<n)
		{
			while(i<n&&j<m&&text[i]==pat[j])
			{
				i++;
				j++;
			}
			
			if(j==m)
			{
			printf("found at %d\n",i-j);
			j=lps[j-1];
		}
			else if(i<n&&text[i]!=pat[j])
			{
				//mismatch
				if(j!=0)
				{
					j=lps[j-1];
				}
				else{
					i++;
				}
				
				
				
			}
		}



}
int main()
{
	kmp("pranav is good coder","av");
}
