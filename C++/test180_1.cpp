#include<bits/stdc++.h>
using namespace std;

const int maxN=5010,maxT=5010;
int n,T;

double DP[maxN][maxT];
bool flag[maxN][maxT];

double arr[maxN];
int Ttime[maxN];

double find_ans(int i,int rem)
{
	if(i==n)
		return 0;
	
	if(flag[i][rem])
		return DP[i][rem];
		
	
	double pre=1;
	double ans=0;
	
	for(int j=1;j<=min(Ttime[i],rem);j++)
	{
		if(j==Ttime[i])
		{
			ans+=pre*(1+find_ans(i+1,rem-j));
		}
		else
		{
			ans+=pre*arr[i]*(find_ans(i+1,rem-j) + 1); 
		}
		pre*=(1-arr[i]);
	}
	DP[i][rem]=ans;
	flag[i][rem]=1;
	
	return ans;
}
int main()
{
	cin>>n>>T;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i]>>Ttime[i];
		arr[i]/=100;
	}
	memset(flag,0,sizeof(flag));
	
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=T;j++)
		{
			cout<<find_ans(i,j)<<' ';
		}
		cout<<endl;
	}
	return 0;
}

