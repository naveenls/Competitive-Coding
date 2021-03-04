#include<bits/stdc++.h>
using namespace std;
const int maxM=1e5+10;

long long mod=1e9+7;
set<pair<int,int> > s;
long long sum=0;
long long DP[maxM]={0};

void insert(vector<pair<int,int> > &v,int ind)
{
	sum+=DP[ind];
	s.insert({v[ind].first,ind});
}

void remove_top()
{
	auto pr=*s.rbegin();
	sum=(sum-DP[pr.second]+mod)%mod;
	s.erase(pr);
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<pair<int,int> > v(m);
	
	for(int i=0;i<m;i++)
	{
		cin>>v[i].second;
		cin>>v[i].first;
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0;i<m;i++)
		swap(v[i].first,v[i].second);
	
	long long equal_sum=0;
	
	for(int i=m-1;i>=0;i--)
	{
		if(v[i].second==n)
		{
			DP[i]=1;
		}
		while(s.size() && s.rbegin()->first > v[i].second)
		{
			remove_top();
		}
		
		if(i<m-1 && v[i+1].second==v[i].second)
		{
			equal_sum=(equal_sum+DP[i+1])%mod;
		}
		else
		{
			equal_sum=0;
		}
		DP[i]+=(sum-equal_sum)%mod;
		insert(v,i);
	}
	long long ans=0;
	
	for(int i=0;i<m;i++)
	{
		if(v[i].first==0)
			ans=(ans+DP[i])%mod;
	}
	cout<<ans<<endl;
	
	return 0;
}
