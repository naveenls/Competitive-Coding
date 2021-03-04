#include <bits/stdc++.h>
using namespace std;

int find_parent(int i,vector<int> &par)
{
	if(par[i]==i)
		return par[i];
		
	par[i]=find_parent(par[i],par);
	return par[i];
}

int find_comp(vector<int> &v1,vector<int> &v2,int n)
{
	vector<int> temp(n);
	
	for(int i=0;i<n;i++)
		temp[i]=i;
		
	for(int i=0;i<n;i++)
	{
		if(v1[i]!=v2[i])
		{
			int a=find_parent(v1[i],temp);
			int b=find_parent(v2[i],temp);
			
			if(a!=b)
			{
				temp[a]=b;
			}
		}
		temp[i]=find_parent(v1[i],temp);
	}
	
	set<int> s;
	for(int i=0;i<n;i++)
	{
		s.insert(find_parent(i,temp));
	}
	return s.size();
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	vector<int> DSU1[m+2];
	vector<int> DSU2[m+2];
	
	for(int i=0;i<n;i++)
	{
		DSU1[0].push_back(i);
		DSU2[m+1].push_back(i);	
	}
	
	vector<pair<int,int> > V(m+1);
	
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v,u--,v--;
		V[i]={u,v};
		
		DSU1[i]=DSU1[i-1];
		
		int a=find_parent(u,DSU1[i]);
		int b=find_parent(v,DSU1[i]);
		
		if(a<b)
		{
			DSU1[i][b]=a;
		}
		else if(a>b)
		{
			DSU1[i][a]=b;
		}
	}
	
	for(int i=m;i>=1;i--)
	{
		u=V[i].first;
		v=V[i].second;
		
		DSU2[i]=DSU2[i+1];
		
		int a=find_parent(u,DSU2[i]);
		int b=find_parent(v,DSU2[i]);
		
		if(a<b)
		{
			DSU2[i][b]=a;
		}
		else if(a>b)
		{
			DSU2[i][a]=b;
		}
	}
	
	int k;
	cin>>k;
	
	int l,r;
	
	for(int i=0;i<k;i++)
	{
		cin>>l>>r;
		
		cout<<find_comp(DSU1[l-1],DSU2[r+1],n)<<endl;
	}
	return 0;
}

