#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int l,r;
	cin>>l>>r;
	
	int limit=sqrt(r);
	
	bool is_prime[r-l+1]={0};
	
	for(int i=0;i<=r-l;i++)
	{
	    is_prime[i]=1;
	}
	
	for(int i=2;i<=limit;i++)
	{
        for(int j=max(i*i,(l+i-1)/i * i);j<=r;j+=i)
	   {
            is_prime[j-l]=0;
	   }
	}
	
    int cnt=0;
	
	for(int x=l;x<=r;x++)
	{
		if(x%2)
		{
			if(is_prime[x-l])
			{
				cnt++;
			}
		}
		else
		{
			if(x%16==0)
			{
				continue;
			}
			else if(x%8==0)
			{
				if(x==8)
					cnt++;
			}
			else if(x%4==0)
			{
				if(is_prime[x/4-l])
				{
					cnt++;
				}
			}
			else
			{
				cnt++;
			}
		}
		
	}
	cout<<cnt<<endl;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve(); 
	}
	return 0;
}
