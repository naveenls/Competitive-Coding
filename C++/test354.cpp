#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	
	map<int,long long> mp;
	
	int a;
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		mp[a]++;		
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>a;
		mp[a]--;
	}
	
	auto itr=mp.rbegin();
	
	long long sum=0;
	while(itr!=mp.rend())
	{
		sum+=itr->second;
		itr++;
		
		if(sum>0)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	
	cout<<"NO"<<endl;
	return 0;
}
