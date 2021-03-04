#include<bits/stdc++.h>
using namespace std;
const int maxN=1000;
int n,m;
string arr[maxN];

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int DP[n][m];
	memset(DP,-1,sizeof(DP));
	
	pair<int,int> out;
	pair<int,int> start;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='E')
				out={i,j};
				
			if(arr[i][j]=='S')
				start={i,j};		
		}
	}
	DP[out.first][out.second]=0;
	
	queue<pair<int,int> > q;
	
	q.push({out.first,out.second});
	while(!q.empty())
	{
		auto pp=q.front();
		q.pop();
		
		int i=pp.first;
		int j=pp.second;
		int depth=DP[i][j];
		
		if(i+1<n && arr[i+1][j]!='T' && DP[i+1][j]==-1)
		{
			DP[i+1][j]=depth+1;
			q.push({i+1,j});
		}
		if(i>0 && arr[i-1][j]!='T' && DP[i-1][j]==-1)
		{
			DP[i-1][j]=depth+1;
			q.push({i-1,j});
		}
		
		if(j+1<m && arr[i][j+1]!='T' && DP[i][j+1]==-1)
		{
			DP[i][j+1]=depth+1;
			q.push({i,j+1});
		}
		if(j>0 && arr[i][j-1]!='T' && DP[i][j-1]==-1)
		{
			DP[i][j-1]=depth+1;
			q.push({i,j-1});
		}
	}
	
	int val=DP[start.first][start.second];
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(~DP[i][j] && arr[i][j]!='S' &&arr[i][j]!='E')
			{
				if(DP[i][j]<=val)
					ans+=(arr[i][j]-'0');
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
