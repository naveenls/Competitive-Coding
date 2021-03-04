#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long n,r;
		cin>>n>>r;
		
		if(r>=n)
		{			
			long long ans=1+ n*(n-1)/2;
			
			cout<<ans<<endl;
		}
		else
		{
			long long ans=r*(r+1)/2;
			cout<<ans<<endl;
		}
	}
	return 0;
}
