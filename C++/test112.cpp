#include<bits/stdc++.h>
using namespace std;
long long n,m;

long long calc(long long x)
{
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		res+=min((x-1)/i,m);
	}
	return res;
}
int main()
{
	cin>>n>>m;
	long long k ;
	cin>>k;
	
	long long lo=1,hi=n*m+1;
	
	while(lo<hi)
	{
		long long mid=(lo+hi)/2;
		if(calc(mid)<k)
		{
			lo=mid+1;
		}
		else
		{
			hi=mid;
		}
		
	}
	cout<<lo-1<<endl;
	
	return 0;
}
