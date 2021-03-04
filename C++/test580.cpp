#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		
		int x;
		cin>>x;
		
		vector<int> v[x];
		
		for(int i=0;i<s.size();i++)
		{			
			v[i%x].push_back(s[i]-'0');
		}
		
		vector<int> res[x];
		
		bool not_poss=false;
		
		for(int i=0;i<x;i++)
		{	
			res[i].resize(v[i].size());
		
			for(int j=0;j<v[i].size();j++)
				res[i][j]=-1;
				
			for(int j=0;j<v[i].size();j++)
			{				
				if(v[i][j]==0)
				{
					if(j)
					{
						res[i][j-1]=0;
					}
					if(j+1<v[i].size())
					{
						res[i][j+1]=0;
					}
				}
			}
			
			for(int j=0;j<v[i].size();j++)
			{				
				if(v[i][j]==1)
				{
					if(j && res[i][j-1]!=0)
					{
						res[i][j-1]=1;
					}
					else if(j+1<v[i].size() && res[i][j+1]!=0)
					{
						res[i][j+1]=1;
					}
					else
					{
						not_poss=true;
						break;
					}
				}
			}
			
			if(not_poss)
				break;
				
			for(int j=0;j<v[i].size();j++)
			{
				if(res[i][j]==-1)
					res[i][j]=0;
			}
		}
		
		if(not_poss)
		{
			cout<<-1<<endl;
		}
		else
		{
			int ptr[x]={0};
			
			for(int i=0;i<s.size();i++)
			{
				cout<<res[i%x][ptr[i%x]];
				ptr[i%x]++;
				
			}
			cout<<endl;
		}
	}
	return 0;
}
