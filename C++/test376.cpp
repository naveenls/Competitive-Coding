#include<bits/stdc++.h>
using namespace std;

const int maxN=80;
const int maxM=1e5+1;

int DP[maxN+1][maxM+1];
vector<pair<int,int> > v;

int n, m;

int main()
{
	cin>>n>>m;
	
	int x,s;
	
	for(int i=0;i<n;i++)
	{
		cin>>x>>s;
		v.push_back({x,s});
	}
	
	sort(v.begin(),v.end());
	
	vector<int> pre(m+1);
	
	for(int j=1;j<=m;j++)
	{
		DP[n][j]=1e9+j;
		pre[j]=1e9;
	}
	
	DP[n][m+1]=m+1;
	
	for(int j=m;j>=1;j--)
	{
		DP[n][j]=min(DP[n][j],DP[n][j+1]);
	}
	
	for(int i=n-1;i>=0;i--)
	{
		for(int start=1;start<=m;start++)
		{
			int extra=max(0,v[i].first-v[i].second-start);
			
			int ind=min(m+1,v[i].first+v[i].second+extra+1);
			
			DP[i][start]=DP[i+1][ind]-ind+extra;
			DP[i][start]=min(DP[i][start],pre[start]);
			
			pre[start]=DP[i][start];
			DP[i][start]+=start;
		}
		DP[i][m+1]=m+1;
		
		for(int j=m;j>=1;j--)
		{
			DP[i][j]=min(DP[i][j],DP[i][j+1]);
		}
	}
	
	cout<<pre[1]<<endl;
	return 0;
}
