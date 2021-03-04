#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long long base=1001;
	
	int n,s;
	cin>>n>>s;
	
	vector<int> v[n];
	
	int c;
	
	map<long long,long long> mp;
	
	for(int i=0;i<n;i++)
	{
		cin>>c;
		v[i].resize(c);
		
		for(int j=0;j<c;j++)
		{
			cin>>v[i][j];
		}
		
		sort(v[i].begin(),v[i].end());
		
		for(int k=1;k<(1<<c);k++)
		{
			long long val=0;
			
			for(int j=0;j<c;j++)
			{
				if(k & (1<<j))
				{
					val=val*base + v[i][j];
				}
			}
			mp[val]++;
		}
	}

	long long ans=0;
	
	for(int i=0;i<n;i++)
	{
		long long val=0;
			
		for(int j=0;j<v[i].size();j++)
		{
			val=val*base + v[i][j];
		}
				
		ans+=(n-mp[val]);
	}
	
	cout<<ans<<endl;
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
