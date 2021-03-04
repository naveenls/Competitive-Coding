#include<bits/stdc++.h>
using namespace std;

int find_par(int i,int par[])
{
	if(i==par[i])
		return i;
		
	par[i]=find_par(par[i],par);
	return par[i];
}

void solve()
{
	int n,m;
	cin>>n>>m;
	
	int par[n];
	for(int i=0;i<n;i++)
	{
		par[i]=i;
	}
	
	int cnt=n;
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v,u--,v--;
		
		int a=find_par(u,par);
		int b=find_par(v,par);
		
		if(a!=b)
		{
			par[a]=b;
			cnt--;
		}
	}
	
	cout<<n+cnt-2<<endl;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve(); 
	}
	return 0;
}
