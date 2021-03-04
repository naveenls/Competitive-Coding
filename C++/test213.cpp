#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	long long a,b;
	
	vector<pair<long long,pair<long long,long long> > > v(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		v[i]={b-a,{a,b}};
	}
	sort(v.begin(),v.end());
	
	long long sum=0;
	
	for(int i=0;i<n;i++)
	{
		long long j=i+1;
		sum+=(v[i].second.first*(j-1) + v[i].second.second*(n-j));
	}
	cout<<sum<<endl;
	return 0;
}
