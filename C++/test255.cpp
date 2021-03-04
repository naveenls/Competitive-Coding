#include<bits/stdc++.h>
using namespace std;

long long mod=998244353;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int mx=max(n,m);
	
	long long a[mx]={0},b[mx]={0};
	
	char c;
	
	for(int i=0;i<n;i++)
	{
		cin>>c;
		a[n-i-1]=c-'0';	
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>c;
		b[m-i-1]=c-'0';
	}
	
	for(int i=m-2;i>=0;i--)
	{
		b[i]+=b[i+1];
	}
	
	long long p=1;
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i])
		{
			ans=(ans+ b[i]*p%mod)%mod;
		}
		p=(p*2)%mod;	
	}
	cout<<ans<<endl;
	return 0;
}
