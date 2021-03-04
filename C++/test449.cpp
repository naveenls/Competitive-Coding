#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	
	long long a[m],b[n];
	long long s1=0,s2=0;
	
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		s1+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		s2+=b[i];
	}
	
	sort(a,a+m,greater<long long> ());
	sort(b,b+n,greater<long long> ());
	
	long long sum=0;
	long long mi=1e18;
	
	for(long long i=0;i<m && (i+1)*s2<=1e18 ;i++)
	{
		sum+=a[i];
		mi=min(mi,s1-sum+(i+1)*s2);		
	}
	
	sum=0;
	for(long long i=0;i<n && (i+1)*s1<=1e18;i++)
	{
		sum+=b[i];
		mi=min(mi,s2-sum+(i+1)*s1);		
	}
	
	cout<<mi<<endl;
	return 0;
}
