#include<bits/stdc++.h>
using namespace std;

long long find_pre(vector<long long> &v)
{	
	int n=v.size();
	
	long long temp[n];
	temp[n-1]=v[n-1];
	
	for(int i=n-2;i>=0;i--)
	{
		temp[i]=max(v[i],v[i]+temp[i+1]);
	}
	return temp[0];
}

long long find_suff(vector<long long> &v)
{	
	int n=v.size();
	
	long long temp[n];
	temp[0]=v[0];
	
	for(int i=1;i<n;i++)
	{
		temp[i]=max(v[i],v[i]+temp[i-1]);
	}
	return temp[n-1];
}

long long maxSubArraySum(vector<long long> &a, int size) 
{ 
    long long max_so_far = -1e18, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<long long> arr[n];
	long long sum[n],prefix[n],suffix[n];
	
	int tt;
	for(int i=0;i<n;i++)
	{
		cin>>tt;
		arr[i].resize(tt);
		
		long long sum_t=0;
		for(int j=0;j<tt;j++)
		{
			cin>>arr[i][j];
			sum_t+=arr[i][j];
		}
		sum[i]=sum_t;
	}
	
	for(int i=0;i<n;i++)
	{
		prefix[i]=find_pre(arr[i]);
		suffix[i]=find_suff(arr[i]);
	}
	/*
	for(int i=0;i<n;i++)
	{
		cout<<sum[i]<<' '<<prefix[i]<<' '<<suffix[i]<<endl;
	}
	*/
	int big[m+1];
	for(int i=1;i<=m;i++)
	{
		cin>>big[i];
		big[i]--;
	}
	
	long long suff[m+1];
	suff[0]=0;
	
	for(int i=1;i<=m;i++)
	{
		suff[i]=max(suffix[big[i]],sum[big[i]]+suff[i-1]);
	}
	
	long long pre[m+2];
	pre[m+1]=0;
	for(int i=m;i>=1;i--)
	{
		pre[i]=max(prefix[big[i]],sum[big[i]]+pre[i+1]);
	}
	
	long long max_val=-1e18;
	for(int i=0;i<=m;i++)
	{
		max_val=max(max_val,suff[i]+pre[i+1]);
	}
	
	long long max_s_sum[n];
	for(int i=0;i<n;i++)
	{
		max_s_sum[i]=maxSubArraySum(arr[i],arr[i].size() );
	}
	for(int i=1;i<=m;i++)
	{
		max_val=max(max_val,max_s_sum[big[i]]);
	}
	cout<<max_val<<endl;
	return 0;
}
