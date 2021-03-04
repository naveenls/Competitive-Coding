#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		int w[n],c[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>c[i]>>w[i];
		}
		
		int mask=(1<<n);
		
		long long ma=0;
		
		for(int i=0;i<mask;i++)
		{
			long long sum=0;
			long long cost=0;
			
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					sum+=w[j];
					cost+=c[j];
				}
			}
			
			if(cost<=k)
			{
				ma=max(ma,sum);
			}
		}
		cout<<ma<<endl;
	}
	return 0;
}
