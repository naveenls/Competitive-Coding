#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	long long x[n],p[m];
	long long gcd=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>p[i];
	}
	
	for(int i=0;i<n-1;i++)
	{
		gcd=__gcd(x[i+1]-x[i],gcd);
	}
	for(int i=0;i<m;i++)
	{
		if(gcd%p[i]==0)
		{
			cout<<"YES"<<endl;
			cout<<x[0]<<' '<<i+1<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	
	return 0;
}
