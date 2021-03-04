#include<bits/stdc++.h>
using namespace std;

const int maxN=210;

long long DP[maxN][maxN][maxN];
int r,g,b;

int R[maxN];
int G[maxN];
int B[maxN];

long long find_max(int i,int j,int k)
{
	int t=(i==r) + (j==g) + (k==b);
	if(t>=2)
	{
		return 0;
	}
	
	if(DP[i][j][k]!=-1)
	{
		return DP[i][j][k];
	}
	
	long long ans=0;
	if(t==1)
	{
		if(i==r)
		{
			ans=G[j]*B[k] + find_max(i,j+1,k+1);
		}
		else if(j==g)
		{
			ans=R[i]*B[k] + find_max(i+1,j,k+1);
		}
		else
		{
			ans=G[j]*R[i] + find_max(i+1,j+1,k);
		}
	}
	else
	{
		ans=max(ans,G[j]*B[k] + find_max(i,j+1,k+1));
		ans=max(ans,R[i]*B[k] + find_max(i+1,j,k+1));
		ans=max(ans,G[j]*R[i] + find_max(i+1,j+1,k));
	}
	
	DP[i][j][k]=ans;
	return ans;
}
int main()
{
	cin>>r>>g>>b;
	
	for(int i=0;i<r;i++)
	{
		cin>>R[i];
	}
	for(int i=0;i<g;i++)
	{
		cin>>G[i];
	}
	for(int i=0;i<b;i++)
	{
		cin>>B[i];
	}
	
	sort(R,R+r,greater<long long> ());
	sort(G,G+g,greater<long long> ());
	sort(B,B+b,greater<long long> ());
	
	memset(DP,-1,sizeof(DP));
	cout<<find_max(0,0,0)<<endl;
	
	return 0;
	
}
