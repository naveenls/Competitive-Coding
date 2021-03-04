#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long double n;
		cin>>n;
		
		long double ans=0;
		
		for(long double i=0;i<n;i++)
		{
			ans+=(n/(n-i));
		}
		cout<<fixed<<setprecision(5)<<ans<<endl;
	}
	return 0;
}
