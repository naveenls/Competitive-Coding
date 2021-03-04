#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,l,r,ql,qr;
	cin>>n>>l>>r>>ql>>qr;
	int arr[n+1];
	int r_sum=0,l_sum=0;
	arr[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		r_sum+=arr[i];
	}
	int ans=2*1e9;
	for(int i=0;i<=n;i++)
	{
		r_sum-=arr[i];
		l_sum+=arr[i];
		
		if(i<n-i)
		{
			ans=min(ans,l_sum*l+r_sum*r+(n-2*i-1)*qr);
		}
		else if(i>n-i)
		{
			ans=min(ans,l_sum*l+r_sum*r+(2*i-n-1)*ql);
		}
		else
		{
			ans=min(ans,l_sum*l+r_sum*r);
		}
	}
	cout<<ans<<endl;
	return 0;
}
