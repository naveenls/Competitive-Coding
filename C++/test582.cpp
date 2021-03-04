#include<bits/stdc++.h>
using namespace std;

int find_min(int l,int r,int arr[])
{
	if(r<l)
		return 0;
		
	if(l==r)
	{
		return min(1,arr[l]);
	}
	
	int min_ind=l;
	int mi=arr[l];
	
	for(int i=l;i<=r;i++)
	{
		if(arr[i]<mi)
		{
			mi=arr[i];
			min_ind=i;
		}
	}
	
	for(int i=l;i<=r;i++)
	{
		arr[i]-=mi;
	}
	
	return min(r-l+1,mi + find_min(l,min_ind-1,arr) + find_min(min_ind+1,r,arr));
}
int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<find_min(0,n-1,arr);
	/*
	long long DP[n+1];
	DP[n]=0;
	
	for(int i=n-1;i>=0;i--)
	{
		int mi=arr[i];
		
		map<int,int> cnt;
		cnt[arr[i]]++;
		
		if(arr[i]!=0)
			DP[i]=1 + DP[i+1];
		else
			DP[i]=DP[i+1];
		
		for(int j=i+1;j<n;j++)
		{
			mi=min(mi,arr[j]);
			cnt[arr[j]]++;
						
			long long num_moves=DP[j+1] + mi + (j-i+1) - cnt[mi];
			
			DP[i]=min(DP[i],num_moves);
		}
	}
	
	cout<<DP[0]<<endl;
	*/
	
	return 0;
}
