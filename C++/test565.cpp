#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long x,y,z;
		cin>>z>>y>>x;
		
		long long x1,y1,z1;
		cin>>z1>>y1>>x1;
		
		long long ans=0;
		
		ans+=2*min(x,y1);
		
		long long temp=min(x,y1);
		x-=temp;
		y1-=temp;
		
		if(x1>x+z)
		{
			ans-=(x1-x-z)*2;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
