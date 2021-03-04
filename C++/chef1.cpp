#include<bits/stdc++.h>
using namespace std;

int main()
{
    
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int ans=1e7;
		ans=min(ans,abs(a+b-(c+d)));
		ans=min(ans,abs(a+c-(b+d)));
		ans=min(ans,abs(a+d-(b+c)));
		ans=min(ans,abs(a-(d+b+c)));
		ans=min(ans,abs(b-(a+d+c)));
		ans=min(ans,abs(c-(b+a+d)));
		ans=min(ans,abs(d-(b+a+c)));
		cout<<ans<<endl;		
	}
	return 0;
}
