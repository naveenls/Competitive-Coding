#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

long long power(long long x, long long y, long long m) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}

long long modInverse(long long a, long long m) 
{ 
    return power(a, m-2, m);
} 

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		long long m;
		cin>>n>>m;
		
		vector<int> arr(n-1);
		for(int i=0;i<n-1;i++)
		{
			cin>>arr[i];
		}
		
		sort(arr.begin(),arr.end());
		
		long long ans=1;
		
		int prev_val=0;
		long long prev_cnt=1;
		
		long long num_edges=0;
		
		for(int i=0;i<n-1;)
		{
			int j=i+1;
			
			while(j<n-1 && arr[j]==arr[j-1])
				j++;
				
			if(arr[i]!=prev_val+1)
			{
				ans=0;
			}
			long long curr=j-i;
			
			long long val=prev_cnt*curr%mod;
			ans=(ans*val)%mod;
			
			num_edges+=(curr)*(curr-1)/2;
			
			i=j;
			prev_cnt=curr;
			prev_val=arr[i];
		}
		
		if(num_edges<m)
		{
			ans=0;
		}
		
		long long num=1;
		long long denom=1;
		
		for(long long j=num_edges;j>num_edges-m;j--)
		{
			num=(num*j)%mod;
		}
		for(int j=1;j<=m;j++)
		{
			denom=(denom*j)%mod;
		}
		
		cout<<ans*num%mod*modInverse(denom,mod)%mod<<endl;
	}
	return 0;
}
