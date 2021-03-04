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
		if(n%2==0)
		{
			long double ans=1/(sin(360/(4*n)));
			cout<<setpercision(10)<<ans<<endl;
		}
		else
		{
			long double ans=1/(tan(360/(4*n)));
			cout<<setpercision(10)<<ans<<endl;
		}
	}
	
	return 0;
}
