#include<bits/stdc++.h>
using namespace std;

int n,m,t;
const int maxN=1000;

string arr[maxN];

bool check(int i,int j)
{
	if(i+1<n && arr[i][j]==arr[i+1][j])
	{
		return true;
	}
	if(j+1<m && arr[i][j]==arr[i][j+1])
	{
		return true;
	}
	if(i-1>=0 && arr[i][j]==arr[i-1][j])
	{
		return true;
	}
	if(j-1>=0 && arr[i][j]==arr[i][j-1])
	{
		return true;
	}
	return false;
}
int main()
{
	
	cin>>n>>m>>t;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	long long DP[n][m];
	memset(DP,-1,sizeof(DP));
	
	queue<pair<int,int> > q;
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(check(i,j))
			{
				flag=1;
				DP[i][j]=0;
				q.push({i,j});
			}
		}
	}
	
	while(!q.empty())
	{
		pair<int,int> pr=q.front();
		q.pop();
		
		int i=pr.first;
		int j=pr.second;
		
		if(i+1<n && -1==DP[i+1][j])
		{
			DP[i+1][j]=DP[i][j]+1;
			q.push({i+1,j});
		}
		if(j+1<m && -1==DP[i][j+1])
		{
			DP[i][j+1]=DP[i][j]+1;
			q.push({i,j+1});
		}
		if(i-1>=0 && -1==DP[i-1][j])
		{
			DP[i-1][j]=DP[i][j]+1;
			q.push({i-1,j});
		}
		if(j-1>=0 && -1==DP[i][j-1])
		{
			DP[i][j-1]=DP[i][j]+1;
			q.push({i,j-1});
		}
	}
	long long a,b,p;
	while(t--)
	{
		cin>>a>>b>>p;
		a--,b--;

		if(DP[a][b]==-1 || DP[a][b]>=p)
		{
			cout<<arr[a][b]<<endl;
		}
		else
		{
			long long temp=p-DP[a][b];
			if(temp%2==0)
			{
				cout<<arr[a][b]<<endl;
			}
			else
			{
				cout<<1-(arr[a][b]-'0')<<endl;
			}
		}
	}
}
