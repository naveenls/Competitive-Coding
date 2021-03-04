#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

long long value[maxN];
int c[maxN];

int n,q;

void solve(long long a,long long b)
{	
	long long max_end[n+1];
	
	long long first=-1e13,second=-1e13;
	long long c1=-1,c2=-1;
	
	for(int i=1;i<=n;i++)
	{
		max_end[i]=-1e13;
	}
	
	for(int i=0;i<n;i++)
	{
		long long val1=value[i]*b;
		long long val2=value[i]*a + max_end[c[i]];
		long long val3=-1e18;
		
		if(c1==c[i])
		{
			val3=value[i]*b+second;
		}
		else
		{
			val3=value[i]*b+first;
		}
		
		long long ma=max(val1,val2);
		ma=max(ma,val3);
		
		if(ma>max_end[c[i]])
		{
			max_end[c[i]]=ma;
			
			if (ma>first) 
	        { 
	        	if(c1==c[i])
	        	{
	        		first=ma;
				}
				else
				{
					second = first; 
	            	c2=c1;
	            	
	            	first = ma; 
	            	c1=c[i];	
				}
	        } 

	        else if (ma > second)
			{
				second = ma;
				c2=c[i]; 	
			}
		}
	}
	cout<<max(0LL,first)<<endl;
}
int main()
{
	cin>>n>>q;
	
	for(int i=0;i<n;i++)
		cin>>value[i];
		
	for(int i=0;i<n;i++)
		cin>>c[i];
		
	long long a,b;
	
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		solve(a,b);
	}
	return 0;
}
