#include<bits/stdc++.h>
using namespace std;
const int maxN=1000;
int n,m;

bool mark[maxN][maxN];
string arr[maxN];

void dfs(int i,int j)
{
	if(i>=0 && i<n && j>=0 && j<m)
	{
		if(arr[i][j]=='#' && !mark[i][j])
		{
			//cout<<i<<' '<<j<<endl;
			mark[i][j]=1;
			dfs(i+1,j);
			dfs(i-1,j);
			dfs(i,j+1);
			dfs(i,j-1);
		}
	}
}
int main()
{

	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	memset(mark,0,sizeof(mark));
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='#' && !mark[i][j])
			{
				cnt++;
				dfs(i,j);
			}
		}
	}
	bool flag=0;
	bool ak[n];
	for(int i=0;i<n;i++)
	{
		int last_pos=-1;
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='#')
			{
				if(last_pos==-1)
					last_pos=j;
				else
				{
					if(last_pos!=j-1)
					{
						flag=1;
						break;
					}
					else
						last_pos=j;
				}
			}
		}
		if(last_pos==-1)
		{
			ak[i]=0;
		}
		else
		{
			ak[i]=1;
		}
		if(flag)
			break;
	}
	if(flag){
		cout<<-1;
		return 0;
	}
	bool bk[m];
	for(int i=0;i<m;i++)
	{
		int last_pos=-1;
		bool f=0;
		for(int j=0;j<n;j++)
		{
			if(arr[j][i]=='#')
			{
				if(last_pos==-1)
					last_pos=j;
				else
				{
					if(last_pos!=j-1)
					{
						flag=1;
						break;
					}
					else
						last_pos=j;
				}
			}
		}
		if(last_pos==-1)
		{
			bk[i]=0;
		}
		else
		{
			bk[i]=1;
		}
		if(flag)
			break;
	}
	if(flag)
	{
		cout<<-1;//<<"hi";
		return 0;
	}
	int c1=0,c2=0;
	for(int i=0;i<n;i++)
	{
		if(ak[i]==0)
		{
			c1++;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(bk[i]==0)
		{
			c2++;
		}
	}
	if(c1 && !c2)
	{
		cout<<-1;//<<"hi2";
		return 0;
	}
	if(c2 && !c1)
	{
		cout<<-1;//<<"hi3";
		return 0;
	}

	cout<<cnt<<endl;
	return 0;
}
