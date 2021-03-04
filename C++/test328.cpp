#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	long double a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	long double b[m+1];
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];	
	}
	
	long double x;
	cin>>x;
	
	long double len[m+1];
	
	for(int i=1;i<=m;i++)
		len[i]=1e18;
		
	for(int i=1;i<=m;i++)
	{
		long double sum=0;
		
		for(int j=i;j<=m;j++)
		{
			int l=j-i+1;
			sum+=b[j];
			
			len[l]=min(sum,len[l]);
		}
	}
	
	int ans_len=0;
	for(int i=1;i<=n;i++)
	{
		long double sum=0;
		for(int j=i;j<=n;j++)
		{
			sum+= a[j];
			
			long double temp=x/sum;
			
			int l=1,r=m;
			int ans=-1;
			
			while(l<=r)
			{
				int mid=(l+r)/2;
				
				if(len[mid]<=temp)
				{
					ans=mid;
					l=mid+1;
				}
				else
				{
					r=mid-1;
				}
			}
			if(ans==-1)
			{
				break;
			}
			
			if((j-i+1)*ans>ans_len)
			{				
				ans_len=(j-i+1)*ans;
			}
		}
	}
	
	cout<<ans_len<<endl;

	return 0;
}
