#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	sort(arr+1,arr+n+1);
	long long pre[n+1];
	pre[0]=0;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+arr[i];
	}
	int j=1;
	int cnt[n+1];
	for(int i=1;i<=n;i++)
	{
		while((long long)arr[i]*(i-j+1)-(pre[i]-pre[j-1])>k)
		{
			j++;
		}
		cnt[i]=i-j+1;
	}
	int ma=0;
	int val;
	for(int i=1;i<=n;i++)
	{
		if(ma<cnt[i])
		{
			ma=cnt[i];
			val=arr[i];
		}
	}
	cout<<ma<<' '<<val<<endl;
	/*
	vector< pair<int,int> > v;
	v.push_back({arr[0],1});
	int sz=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]==arr[i-1])
			v[sz].second++;
		else
		{
			sz++;
			v.push_back({arr[i],1});
		}
	}
	int j=0;
	for(int i=0;i<v.size();i++)
	{
		int temp=k;
		
	}
	/**/
	return 0;
}
