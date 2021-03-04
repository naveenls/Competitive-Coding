#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long l,r,m;
		cin>>l>>r>>m;
		
		long long ma=m+r-l;
		long long mi=m+l-r;
				
		for(long long a=l;a<=r;a++)
		{
			long long mi1=max(mi,a);
			
			long long t1=ma/a;
			long long t2=(mi+a-1)/a;
			
			if(t1>t2 || (t1==t2 && t2))
			{
				long long rem=ma-t1*a;
				cout<<a<<' '<<r<<' '<<r-rem<<endl;
				break;
			}
		}
	}
	return 0;
}
