#include<bits/stdc++.h>

using namespace std;



int main()
{
	long long a,b;
	cin>>a>>b;
	long long ans=0;
	while(true)
	{
		ans+=(a/b);
		a=a%b;
		if(a==0)
		{
			break;
		}
		else
		{
			long long temp=b;
			b=a;
			a=temp;
		}
	}
	cout<<ans<<endl;
	return 0;
}
