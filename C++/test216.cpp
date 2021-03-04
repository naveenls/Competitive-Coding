#include<bits/stdc++.h>
using namespace std;

long long maxSubArraySum(long long a[], int size) 
{ 
    long long max_so_far = 0, max_ending_here = 0; 
  
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

long long maxSubArraySum1(long long a[],int n,int x)
{
	long long suff[n];
	long long pre[n];
	
	suff[0]=a[0];
	
	for(int i=1;i<n;i++)
	{
		suff[i]=max(a[i],a[i]+suff[i-1]);
	}
	
	pre[n-1]=a[n-1];
	
	for(int i=n-2;i>=0;i--)
	{
		pre[i]=max(a[i],pre[i+1]+a[i]);
	}
	long long max_val=0;
	
	long long max_so_far = 0, max_ending_here = 0, 
       start =0, end = 0, s=0; 
  
  	for(int i=0;i<n;i++)
  	{
  		a[i]*=-1;	
	}
	x=abs(x);
	
    for (int i=0; i< n; i++ ) 
    { 
        max_ending_here += a[i]; 
  
        if (max_so_far <= max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
  
        if (max_ending_here <= 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
        else
        {
        	long long val1=0;
        	if(s)
        	{
        		val1=max(val1,suff[s-1]);
			}
			long long val2=0;
			if(i<n-1)
			{
				val2=max(val2,pre[i+1]);
			}
			max_val=max(max_val,max_ending_here*x+val1+val2);
		}
    } 
    return max_val;
}

long long maxSubArraySum2(long long a[],int n)
{
	long long suff[n];
	long long pre[n];
	
	suff[0]=a[0];
	
	for(int i=1;i<n;i++)
	{
		suff[i]=max(a[i],a[i]+suff[i-1]);
	}
	
	pre[n-1]=a[n-1];
	
	for(int i=n-2;i>=0;i--)
	{
		pre[i]=max(a[i],pre[i+1]+a[i]);
	}
	
	long long pre_max[n];
	long long suff_max[n];
	
	suff_max[0]=suff[0];
	for(int i=1;i<n;i++)
	{
		suff_max[i]=max(suff[i],suff_max[i-1]);
	}
	
	pre_max[n-1]=pre[n-1];
	
	for(int i=n-2;i>=0;i--)
	{
		pre_max[i]=max(pre[i],pre_max[i+1]);
	}
	long long ma=0;
	for(int i=0;i<n;i++)
	{
		long long val1=0;
		
		if(i)
			val1=max(val1,suff_max[i-1]);
			
		long long val2=max(0LL,pre_max[i]);
		
		ma=max(ma,val1+val2);
	}
	return ma;
}

int main()
{
	int n,x;
	cin>>n>>x;
	
	long long arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	if(x>0)
	{
		long long val=maxSubArraySum(arr,n);
		cout<<max(0LL,val*x)<<endl;
	}
	else if(x<0)
	{
		long long val=maxSubArraySum(arr,n);
		val=max(maxSubArraySum1(arr,n,x),val);
		cout<<max(0LL,val)<<endl;
	}
	else
	{
		long long val=maxSubArraySum(arr,n);
		val=max(val,maxSubArraySum2(arr,n));
		
		cout<<max(0LL,val)<<endl;
	}
	return 0;
}
