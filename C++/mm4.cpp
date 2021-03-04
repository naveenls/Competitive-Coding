#include<bits/stdc++.h>
using namespace std;

const int maxN=55;
bool col[maxN][maxN];
string arr[maxN];
int n,m;

void dfs(int u,int v)
{
	if(u>=n || u<0 || v>=m || v<0)
		return;
		
	if(col[u][v])
		return;
	else if(arr[u][v]=='#')
		return;
	
	col[u][v]=1;
	dfs(u+1,v);
	dfs(u-1,v);
	dfs(u,v-1);
	dfs(u,v+1);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]=='B')
				{
					if(i+1<n)
					{
						if(arr[i+1][j]=='.')
						{
							arr[i+1][j]='#';
						}
						else if(arr[i+1][j]=='G')
						{
							flag=1;
							break;
						}
					}
					if(i>0)
					{
						if(arr[i-1][j]=='.')
						{
							arr[i-1][j]='#';
						}
						else if(arr[i-1][j]=='G')
						{
							flag=1;
							break;
						}
					}
					
					if(j+1<m)
					{
						if(arr[i][j+1]=='.')
						{
							arr[i][j+1]='#';
						}
						else if(arr[i][j+1]=='G')
						{
							flag=1;
							break;
						}
					}
					if(j>0)
					{
						if(arr[i][j-1]=='.')
						{
							arr[i][j-1]='#';
						}
						else if(arr[i][j-1]=='G')
						{
							flag=1;
							break;
						}
					}
				}
			}
		}
		if(flag)
		{
			cout<<"No"<<endl;
			continue;
		}
		memset(col,0,sizeof(col));
		
		dfs(n-1,m-1);
		
		flag=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]=='G')
				{
					if(!col[i][j])
					{
						flag=1;
						break;
					}
				}
			}
		}
		
		if(flag)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;	
}
