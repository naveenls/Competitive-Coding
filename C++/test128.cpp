#include<bits/stdc++.h>
using namespace std;
const int maxN=2*1e5;

long long DP[maxN+1][2];

int col[maxN+1][2];

long long arr[maxN+1];

int n;

long long dfs(int i,int dir)
{
	if(i<=0 || i>n)
		return 0;
		
	if(col[i][dir]==2)
		return DP[i][dir];
		
	else if(col[i][dir]==1)
		return -1;
		
	col[i][dir]=1;
	long long find;
	
	if(dir==0)
		find=dfs(i-arr[i],1);	
	else
		find=dfs(i+arr[i],0);
		
		
	if(find==-1)
		DP[i][dir]=-1;
	else
		DP[i][dir]=arr[i]+find;
		
	col[i][dir]=2;
	return DP[i][dir];
}
int main()
{
	cin>>n;
	
	arr[1]=-2;
	for(int i=2;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	memset(col,0,sizeof(col));
	col[1][0]=1;
	col[1][1]=1;
	
	for(int i=2;i<=n;i++)
	{
		if(col[i][0]==0)
			dfs(i,0);
			
		if(col[i][1]==0)
			dfs(i,1);
	}
	
	for(int i=1;i<=n-1;i++)
	{
		int temp=DP[i+1][0];
		if(temp==-1)
			cout<<-1<<endl;
		else
			cout<<temp+i<<endl;
	}
	return 0;
}
