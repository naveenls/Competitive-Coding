#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int arr[n];
		int brr[n];
		
		int diff=0;
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[n-i-1];
			if(arr[n-i-1]==2)
			{
				diff++;
			}
			else
			{
				diff--;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			cin>>brr[i];
		}
		
		int DP[n];
		if(brr[n-1]==2)
		{
			DP[n-1]=1;
		}
		else
		{
			DP[n-1]=-1;
		}
		
		for(int i=n-2;i>=0;i--)
		{
			if(brr[i]==2)
			{
				DP[i]=1;
			}
			else
			{
				DP[i]=-1;
			}
			//cout<<DP[i]<<endl;
			
			DP[i]+=DP[i+1];
		}
		
		map<int,int> mp;
		for(int i=0;i<n;i++)
		{
			if(mp.find(DP[i])==mp.end())
			{
				mp[DP[i]]=i;
			}
		}
		
		if(mp.find(0)==mp.end())
		{
			mp[0]=n;
		}
		
		int mi=2*n;
		
		if(mp.find(-diff)!=mp.end())
		{
			mi=mp[-diff];
		}

		for(int i=0;i<n;i++)
		{
			if(arr[i]==2)
			{
				diff--;
			}
			else
			{
				diff++;
			}
			//cout<<diff<<endl;
			if(mp.find(-diff)!=mp.end())
			{
				mi=min(mi,i+1+mp[-diff]);
			}
		}
		cout<<mi<<endl;
	}
	return 0;
}
