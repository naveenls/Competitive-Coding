#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	long long arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	long long s1[n-k+1]={0};
	int l[n-k+1];
	for(int i=0;i<k;i++)
	{
		s1[0]+=arr[i];
		l[0]=0;
	}
	
	long long sum=s1[0];
	for(int i=1;i<n-k+1;i++)
	{

		long long temp=arr[i+k-1]+sum-arr[i-1];
		sum=temp;
		
		if(temp>s1[i-1])
		{
			s1[i]=temp;
			l[i]=i;
		}
		else
		{
			s1[i]=s1[i-1];
			l[i]=l[i-1];
		}
	}
	
	long long s2[n-k+1]={0};
	int l2[n-k+1];
	for(int i=n-1;i>=n-k;i--)
	{
		s2[n-k]+=arr[i];
		l2[n-k]=n-k;
	}
	
	sum=s2[n-k];
	for(int i=n-k-1;i>=0;i--)
	{

		long long temp=sum+arr[i]-arr[i+k];
		sum=temp;
		
		if(temp>=s2[i+1])
		{
			s2[i]=temp;
			l2[i]=i;
		}
		else
		{
			s2[i]=s2[i+1];
			l2[i]=l2[i+1];
		}
	}
	long long mx=0;
	int left=-1;
	int right=-1;
	
	for(int i=k;i<n-k+1;i++)
	{
		long long temp=s1[i-k]+s2[i];
		if(temp>mx)
		{
			mx=temp;
			left=l[i-k];
			right=l2[i];
		}
	}
	cout<<left+1<<' '<<right+1<<endl;
	return 0;
	
}
