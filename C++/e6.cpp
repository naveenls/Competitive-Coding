#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long long l,r;
	cin>>l>>r;
	long long ans=0;
	bool flag=0;
	if(l<r)
	{
		long long d=(r-l);
		
		long long n=(-1+sqrt(1+8*d))/2;
		ans+=n;
		r-=n*(n+1)/2;
		
		if(l==r)
		{
			flag=1;
		}
		
		long long count1=(-n+sqrt(n*n+4*r))/2;
		long long count2=(-n-1+sqrt((n+1)*(n+1)+4*l))/2;
		
		ans+=count2 + count1;
		
		l-=(count2*(count2+1) + count2*n);
		r-=(count1*(count1)+count1*n);
		if(flag)
		{
			swap(l,r);
		}
	}
	else
	{
		long long d=(l-r);
		long long n=(-1+sqrt(1+8*d))/2;
		ans+=n;
		l-=n*(n+1)/2;
		
		long long count1=(-n+sqrt(n*n+4*l))/2;
		long long count2=(-n-1+sqrt((n+1)*(n+1)+4*r))/2;
		
		ans+=count2 + count1;
		
		r-=(count2*(count2+1) + count2*n);
		l-=(count1*(count1)+count1*n);
	}
	cout<<ans<<' '<<l<<' '<<r<<endl;
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
