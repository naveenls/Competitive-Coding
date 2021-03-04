#include<bits/stdc++.h>
using namespace std;

long double power(long double x,int y)
{
	long double res=1;
	while(y>0)
	{
		if(y%2)
		{
			res=res*x;
		}
		x=x*x;
		y/=2;
	}
	return res;
}
int main()
{
	int n,m;
	cin>>m>>n;
	
	long double arr[m];
	for(int i=1;i<=m;i++)
	{
		arr[i-1]=power((long double)i/m,n);
	}
	/*
	for(int i=0;i<m;i++)
	{
		cout<<arr[i]<<endl;
	}
	*/
	long double ans=0;
	for(int i=0;i<m-1;i++)
	{
		ans-=(long double)arr[i];
	}
	ans+=(long double)m*arr[m-1];
	cout<<fixed<<setprecision(12)<<ans<<endl;
}
