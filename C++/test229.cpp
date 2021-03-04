#include<bits/stdc++.h>
using namespace std;

/*
const int maxN=2*1e5;
vector<pair<int,int> > adj[maxN];

long long num_0[maxN];
long long num_1[maxN];
long long num_10[maxN];

long long dfs(int i,int p)
{
	num_0[i]=0;
	num_1[i]=0;
	num_10[i]=0;
	
	long long ans=0;
	
	vector<long long> zero,one,one_zero;
	
	for(auto ch:adj[i])
	{
		if(ch.first!=p)
		{
			ans+=2;
			
			if(ch.second)
			{
				ans+=dfs(ch.first,i);
				num_1[i]+=num_1[ch.first]+1;
				num_10[i]+=num_0[ch.first]+num_10[ch.first];
				
				ans+=num_0[ch.first] + num_10[ch.first];
				ans+=2*num_1[ch.first];

				ans-=(num_1[ch.first]+1)*(num_0[ch.first]+num_10[ch.first]);
				
				one.push_back(num_1[ch.first]+1);
				one_zero.push_back(num_0[ch.first]+num_10[ch.first]);
			}
			else
			{
				ans+=dfs(ch.first,i);
				num_0[i]+=num_0[ch.first]+1;
				
				ans+=num_1[ch.first];
				ans+=2*num_0[ch.first];
				
				zero.push_back(num_0[ch.first]+1);
			}
		}
	}

	for(int i=0;i<zero.size();i++)
	{
		for(int j=i+1;j<zero.size();j++)
		{
			ans+=2*(zero[i]*zero[j]);
		}
		
		for(int j=0;j<one.size();j++)
		{
			ans+=zero[i]*one[j];
		}
	}
	
	for(int i=0;i<one.size();i++)
	{
		for(int j=i+1;j<one.size();j++)
		{
			ans+=2*(one[i]*one[j]);
		}
		
		for(int j=0;j<one_zero.size();j++)
		{
			ans+=one[i]*one_zero[j];
		}
	}

	return ans;
}*/

int find_parent(int i,int par[])
{
	if(i==par[i])
	{
		return i;
	}
	par[i]=find_parent(par[i],par);
	return par[i];
	
}
int main()
{
	
	int n;
	cin>>n;
	
	int x,y,c;
	
	int par_0[n],par_1[n];
	long long sz_0[n],sz_1[n];
	
	for(int i=0;i<n;i++)
	{
		par_0[i]=par_1[i]=i;
		sz_0[i]=sz_1[i]=1;
	}
	
	
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y>>c;
		x--,y--;
		
		if(c==1)
		{
			int a=find_parent(x,par_1);
			int b=find_parent(y,par_1);
			
			if(a!=b)
			{
				sz_1[a]+=sz_1[b];
				par_1[b]=a;
			}
		}
		else
		{
			int a=find_parent(x,par_0);
			int b=find_parent(y,par_0);
			
			if(a!=b)
			{
				sz_0[a]+=sz_0[b];
				par_0[b]=a;
			}
		}
	}
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(par_0[i]==i)
		{
			ans+=(sz_0[i])*(sz_0[i]-1);
		}
		if(par_1[i]==i)
		{
			ans+=(sz_1[i])*(sz_1[i]-1);
		}
		
		int a=find_parent(i,par_0);
		int b=find_parent(i,par_1);
		
		ans+=(sz_0[a]-1)*(sz_1[b]-1);
	}
	cout<<ans<<endl;
	
	return 0;
}
