#include<bits/stdc++.h>
using namespace std;

int compare(string s,string t)
{
	if(s==t)
	{
		return -2;
	}
	else if(s>t)
	{
		return -1;	
	}
	else
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]<t[i])
				return i;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	
	string s[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	
	for(int j=0;j<s[0].size();j++)
	{
		if(j && s[0][j]=='?')
		{
			s[0][j]='0';
		}
		
		if(!j && s[0][j]=='?')
		{
			s[0][j]='1';
		}
	}
	
	for(int i=1;i<n;i++)
	{
		if(s[i].size()>s[i-1].size())
		{
			for(int j=0;j<s[i].size();j++)
			{
				if(j && s[i][j]=='?')
				{
					s[i][j]='0';
				}
				
				if(!j && s[i][j]=='?')
				{
					s[i][j]='1';
				}
			}
		}
		else if(s[i].size()==s[i-1].size())
		{
			bool flag=0;
			string temp=s[i];
			
			for(int j=0;j<s[i].size();j++)
			{
				if(s[i][j]!='?')
				{
					if(s[i][j]>s[i-1][j])
					{
						flag=1;
					}
				}
				else
				{
					if(flag)
					{
						s[i][j]='0';
					}
					else
					{
						s[i][j]=s[i-1][j];
					}
				}
			}
			
			int tt=compare(s[i],s[i-1]);
			if(tt==-1)
			{
				continue;
			}
			else
			{
				int j=tt;
				
				if(tt==-2)
					j=s[i].size()-1;
				
				while(j>=0)
				{
					if(temp[j]=='?' && s[i-1][j]!='9')
					{
						s[i][j]=1+s[i-1][j];
						break;
					}
					j--;
				}
				
				if(j<0)
				{
					cout<<"NO"<<endl;
					return 0;
				}
				
				for(int k=j+1;k<s[i].size();k++)
				{
					if(temp[k]=='?')
					{
						s[i][k]='0';
					}
				}
			}
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}
}
