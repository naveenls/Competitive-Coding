#include<bits/stdc++.h>
using namespace std;
const int maxN=1010;
int countW[maxN]={0};
int countB[maxN]={0};

long long DP[maxN][2];
int n,m,x,y;

long long find_min(int col,int start)
{
	if(start==m+1)
		return 0;
		
	if(DP[start][col]!=-1)
		return DP[start][col];
		
	DP[start][col]=LONG_MAX;
	
	if(start+x>m+1)
		DP[start][col];

	for(int j=start+x-1;j<min(start+y,m+1);j++)
	{
		long long temp;
		if(col==0)
		{
			temp=countB[j]-countB[start-1]+find_min(1,j+1);
		}	
		else
		{
			temp=countW[j]-countW[start-1]+find_min(0,j+1);
		}
		
		DP[start][col]=min(DP[start][col],temp);
	}
	return DP[start][col];
}
int main()
{

	cin>>n>>m>>x>>y;
	string arr[n];
	memset(DP,-1,sizeof(DP));
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='#')
				countW[j+1]++;	
		}	
	}
	for(int i=1;i<=m;i++)
	{
		countB[i]=n-countW[i];
		countW[i]+=countW[i-1];
		countB[i]+=countB[i-1];
	}
	cout<<min(find_min(0,1),find_min(1,1))<<endl;
	return 0;
}
