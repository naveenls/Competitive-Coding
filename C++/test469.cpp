#include<bits/stdc++.h>
using namespace std;

int r;
long double b;
long double v,e,f;

long double calc(int x)
{	
	long double ans=0;
	long double val=(v-f*r)/(v-f*(long double)(r-min(r,x)));
	
	ans+=log(val)/f;
	
	if(x>r)
	{
		val=(long double)1-e/v*(long double)(x-r);
		
		ans+=-log(val)/e;
	}
	
	return ans;
}
int main()
{
	int n;
	cin>>n;
	
	while(n)
	{	
		int arr[n+1];
		arr[0]=0;
		
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}	
		
		cin>>b;
		cin>>r>>v>>e>>f;
		
		long double DP[n+1];
		DP[0]=0;
		
		for(int i=1;i<=n;i++)
		{
			DP[i]=1e18;
			for(int j=i-1;j>=0;j--)
			{
				DP[i]=min(DP[j]+calc(arr[i]-arr[j])+b,DP[i]);		
			}
		}
		
		cout<<DP[n]-b<<endl;
		cin>>n;
	}
	
	return 0;
}
