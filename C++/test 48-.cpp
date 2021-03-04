#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int p[n];
	for(int i=0;i<n;i++)
		cin>>p[i];
		
	int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cnt+=(p[j]<p[i]);
		}
	}
	
	if(cnt==0)
	{
		cout<<0<<endl;
		return 0;
	}
	
	long double DP[cnt+1];
	DP[0]=0;
	DP[1]=1;
	
	for(int i=2;i<=cnt;i++)
	{
		DP[i]=4+DP[i-2];
	}
	cout<<DP[cnt]<<endl;

	return 0;
}
