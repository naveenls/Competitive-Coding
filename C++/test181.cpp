#include<bits/stdc++.h>
using namespace std;

const int maxM=101;
vector<int> adj[maxM];
int color[maxM]={0};

int n;

bool dfs(int i,int col)
{
	if(!color[i])
	{
		//cout<<i<<' '<<col<<endl;
		color[i]=col;
		bool flag=true;
		
		for(auto ch:adj[i])
		{
			flag=flag&dfs(ch,3-col);
		}
		return flag;
	}
	else
	{
		if(color[i]==col)
			return true;
		else
			return false;
	}
}
bool check(int i,int j,vector<pair<int,int> > &v)
{
	int a=min(v[i].first,v[i].second);
	int b=max(v[i].first,v[i].second);
	
	int c=v[j].first;
	int d=v[j].second;
	
	int cnt=0;
	
	for(int i=a;i<=b;i++)
	{
		if(i==c || i==d)
			cnt++;
	}
	
	int eq=0;
	if(c==a || c==b)
		eq++;
	if(d==a || d==b)
		eq++;
	
	if(cnt==1 && eq==0)
		return true;
	return false;
	
}
int main()
{
	int m;
	cin>>n>>m;
	
	vector<pair<int,int> > v(m);
	for(int i=0;i<m;i++)
	{
		cin>>v[i].first>>v[i].second;
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i!=j)
			{
				if(check(i,j,v))
				{
					//cout<<i<<' '<<j<<endl;
					adj[i].push_back(j);
				}
			}
		}
	}
	
	for(int i=0;i<m;i++)
	{
		if(!color[i])
		{
			if(!dfs(i,1))
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
	}
	
	for(int i=0;i<m;i++)
	{
		//cout<<color[i]<<' ';
		if(color[i]==1)
			cout<<'o';
		else
			cout<<'i';
	}
	return 0;
}
