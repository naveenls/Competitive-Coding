#include<bits/stdc++.h>
using namespace std;

long long b_search(long long val)
{
	long long l=1,r=1e5;
	
	long long ans;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		
		if(mid*(mid-1)/2<=val)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
int main()
{
	long long a00,a01,a10,a11;
	
	cin>>a00>>a01>>a10>>a11;
	
	if(!a00 && !a01 && !a10 && !a11)
	{
		cout<<0<<endl;
		return 0;
	}	
	long long z=b_search(a00);
	long long o=b_search(a11);
	
	if(a01==0 && a10==0)
	{
		if(z==1)
			z=0;
			
		if(o==1)
			o=0;
	}
	if(z*(z-1)/2 != a00 || o*(o-1)/2 != a11)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	
	if(a01 + a10 != (z+o)*(z+o-1)/2 - a00 -a11)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	int ans[z+o];
	
	if(z==0)
	{
		while(o--)
		{
			cout<<1;	
		}	
		cout<<endl;
		return 0;
	}	
	int k=a10/z;
	int rem=a10%z;
	
	for(int i=0;i<k;i++)
		cout<<1;
	
	for(int i=0;i<z-rem;i++)
	{
		cout<<0;
	}
	
	if(o-k)
		cout<<1;
	
	for(int i=0;i<rem;i++)
		cout<<0;
		
	for(int i=0;i<o-k-1;i++)
		cout<<1;
	
	return 0;
}
