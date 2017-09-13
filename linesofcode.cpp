#include<bits/stdc++.h>
using namespace std;
int main()
{
	fstream f;
	f.open("code.txt",ios::in);

	string s;
	int lines=0;
	while(!f.eof())
	{
		getline(f,s,'\n');

		bool flag=false;

		for(int i=0;i<s.length();++i)
		{
			if(s[i]!=' '&&s[i]!='\t')
			{
				flag=true;
				break;

			}
		}


		if(!flag)
		{
			continue;
		}

		bool comments=true;

		for(int i=0;i<s.length();++i)
		{
		if(s[i]==' '||s[i]=='\t')
		{
			continue;
		}
		if(s[i]=='/')
		{
			if(i<s.length()&&s[i+1]=='/')
			{
			break;
			}
			else 
			{
				comments=false;
				break;

			}
		}
		else{
			comments=false;
			break;
		}



		}

if(comments==true)
	continue;
	
	bool multiline=true;
	for(int i=0;i,s.length();++i)
	{
		if(s[i]==' '||s[i]=='\t')
		{
			continue;
		}
		if(s[i]=='/')
		{
			if(i<s.length()&&s[i+1]=='*')
			{
				break;
			}
			else{
				multiline=false;
				break;
			}
		}

		multiline=false;
		break;
	}
	if(multiline)
	{
		bool f1= true;
		while(f1&& !f.eof())
		{
			if(f1)
			{
				getline(f,s,'\n');
			}


			for(int i=0;i<s.length();++i)
			{
				if(s[i]==' '&&s[i]=='\t')
					continue;
				if(s[i]=='*')
				{
					if(i<s.length()-1&&s[i+1]=='/')
					{
						f1=false;
						break;
					}
					else break;

				}


				break;
			}

			continue;
		}
		
	}
	lines++;
	
	}

	cout<<lines<<"\n";

	return 0;
	}
