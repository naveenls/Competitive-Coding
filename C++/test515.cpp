#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		long long k;
		cin>>n>>k;
		
		int f[n];
		for(int i=0;i<n;i++)
			cin>>f[i];
			
		long long DP[n+1];
		DP[n]={0};
		
		for(int i=n-1;i>=0;i--)
		{
			int temp[101]={0};
			
			DP[i]=1e18;
			
			long long sum=0;
			for(int j=i;j<n;j++)
			{
				temp[f[j]]++;
				
				if(temp[f[j]]==2)
				{
					sum+=2;	
				}
				else if(temp[f[j]]>2)
				{
					sum++;
				}
				
				DP[i]=min(DP[i],k+sum+DP[j+1]);
			}
		}
		
		cout<<DP[0]<<endl;
	}
}
