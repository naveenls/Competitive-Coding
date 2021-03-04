#include<bits/stdc++.h>
using namespace std;
string s;

	long long n;
	int k;
	
pair<long long,long long> binary_search(long long l,long long r,int k)
{
	while(l<r)
	{
		
		if(r-l<=4*k)
			return {l,r};
			
		long long mid=(l+r)/2;
		
		cout<<l<<' '<<mid<<endl;
		cin>>s;
		
		if(s=="Yes")
		{
			l=max(1LL,l-k);
			r=min(n,mid+k);
		}
		else
		{
			l=max(1LL,mid-k);
			r=min(n,r+k);
		}
	}
}
int main()
{	
	srand(time(NULL));
	
	cin>>n>>k;
	
	if(n==1)
	{
		cout<<1<<' '<<1<<endl;
		cin>>s;
		
		return 0;
	}
	
	if(k==0)
	{
		long long l=1,r=n;
		
		while(l<=r)
		{				
			long long mid=(l+r)/2;
			
			cout<<l<<' '<<mid<<endl;
			cin>>s;
			
			if(s=="Yes")
			{
				if(l==mid)
				{
					return 0;
				}
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
	}
	
	while(true)
	{
		pair<long long,long long> p=binary_search(1,n,k);
		long long d=rand();
		
		long long point=p.first+d%(p.second-p.first);
		cout<<point<<' '<<point<<endl;
		cin>>s;
		
		if(s=="Yes")
		{
			return 0;
		}
	}
	
	return 0;
}
