#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long n;
		cin>>n;
		
		int m;
		cin>>m;
		
		long long a[m],b[m];
		
		long long ma=0;
		
		for(int i=0;i<m;i++)
		{
			cin>>a[i]>>b[i];
			ma=max(ma,b[i]);
		}
		vector<pair<long long,int> > v;
		
		for(int i=0;i<m;i++)
		{
			if(a[i]>=ma)
			{
				v.push_back({a[i],i});
			}
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		
		if(n>v.size())
		{
			long long sum=0;
			bool flag=0;
			
			n-=v.size();
						
			for(int i=0;i<v.size();i++)
			{
				sum+=v[i].first;
				
				if(ma==b[v[i].second])
				{
					flag=1;
				}
			}
			
			if(flag)
			{
				long long n1=n;
				
				cout<<sum+n1*ma<<endl;
			}
			else
			{
				long long ma1=0;
				for(int i=0;i<m;i++)
				{
					if(b[i]==ma)
					{
						ma1=max(ma1,a[i]);
					}
				}
				long long n1=n-1;
				
				cout<<sum+n1*ma +ma1<<endl;
			}
		}
		else
		{
			long long sum=0;
			for(int i=0;i<n;i++)
			{
				sum+=v[i].first;
			}
			cout<<sum<<endl;
		}
		
	}
	return 0;
}
