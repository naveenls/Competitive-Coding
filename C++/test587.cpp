#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()

long long find_ans(long long n)
{
	long long ans=0;
	
	for(long long m=1;m<n;m++)
	{
		long long l_sum= m*(m+1)/2;
		long long r_sum= n*(n+1)/2 - l_sum;
		
		long long diff = l_sum - r_sum;
		
		if(diff < 0 || diff > n-1)
		{
			continue;
		}
		
		long long l1 = max (1LL + diff ,m);
		long long l2 = min ( n , m+diff);
								
		ans+=(l2-l1+1);
	}
	
	return ans;
}

int main()
{
	for(long long n=1;n<=1000;n++)
	{		
		long long t_sum = 2*n*(n+1) + 1;
		long long l= t_sum - 8*(n-1);
		long long r= t_sum;
		
		l = sqrt(l);
		r = sqrt(r);
		
		long long ans=0;
		while(l<=r)
		{
			if(l%2 && (t_sum - l*l)%8==0 && (t_sum -l*l)>=0)
			{
				long long diff=(t_sum - l*l)/8;
			
				long long m = (l-1LL)>>1LL;
				
			    if(diff ==0)
				{
				    ans+= (n*(n-1)/2 -(n-m)*m);
				    l++;
				    continue;
				}
				
				long long l1 = max (1LL + diff ,m);
				long long l2 = min ( n , m+diff);
								
				ans+=(l2-l1+1);
			}
			
			l++;
		}
		
		if(ans!=find_ans(n))
		{
			cout<<n<<endl;
		}
	}
	return 0;
}
