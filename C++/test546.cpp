#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> pii;

bool check(pii a,long long ra,pii b,long long rb)
{
	long long distSq=(a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
	long long Sq=ra*ra+rb*rb+2*ra*rb;
	
	if(distSq>=Sq)
	{
		return false;	
	}
	if(distSq<=max(ra*ra,rb*rb))
	{
		return false;
	}
	if((a.first+b.first)%2 || (a.second+b.second)%2)
	{
		return false;
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		long long x[n],y[n];
		long long r[n];
		
		multiset<pair<pair<long long,long long> ,long long> > ms;
		
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i]>>r[i];
			
			ms.insert({{x[i],y[i]},4*r[i]*r[i]});
		}
		
		long long ans=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(check(make_pair(x[i],y[i]),r[i],make_pair(x[j],y[j]),r[j]))
				{
					long long dist=(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
					
					long long a=(x[i]+x[j])/2;
					long long b=(y[i]+y[j])/2;
					
					if(ms.find({{a,b},dist})!=ms.end())
					{
						ans+=ms.count({{a,b},dist});						
					}
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
