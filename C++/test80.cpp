#include<bits/stdc++.h>
using namespace std;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2); 
    p = (p * p) ;
  
    return (y%2 == 0)? p : (x * p) ; 
} 

int main()
{
    long long k,b,n,t;
    cin>>k>>b>>n>>t;
    int start=0;
    int end=n;
    int ans=n;
    while(start<=end)
    {
    	int mid=(start+end)/2;
    	
    	long long pre=0;
    	bool flag=0;
    	
    	for(int j=0;j<n-mid;j++)
    	{
    		pre=pre*k+b;
    		if(pre>t)
    		{
    			flag=1;
    			break;
			}
		}
		if(flag)
		{
			start=mid+1;
		}
		else
		{
			pre=pre+power(k,n-mid);
			if(pre>t)
			{
				start=mid+1;
			}
			else
			{
				ans=mid;
				end=mid-1;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
