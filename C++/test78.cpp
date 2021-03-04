#include<bits/stdc++.h>
using namespace std;

long long p=1e9+7;

long long power(long long x, long long y) 
{ 
    long long res = 1; 
  
    x = x % p;  
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 

int main()
{
	long long n,x;
	cin>>n>>x;
	long long arr[n];
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=sum-arr[i];
	}
	sort(arr,arr+n);
	long long v=arr[0];
	int i=0;
	int cnt=0;
	while(i<n)
	{
		int j=i;
		for(;j<n;j++)
		{
			if(arr[j]==v)
			{
				cnt++;
			}
			else
			{
				break;
			}
		}
		//cout<<cnt<<' '<<v<<endl;
		if(cnt && cnt%x==0)
		{
			cnt/=x;
			v++;
		}
		else
		{
			break;
		}
		i=j;
	}
	while(cnt%x==0)
	{
		cnt=cnt/x;
		v++;
	}
	v=min(v,sum);
	cout<<power(x,v)<<endl;
	return 0;
}
