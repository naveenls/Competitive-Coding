#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<pair<long long,int> > v(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first;
		v[i].second=i;
	}
	
	sort(v.begin(),v.end());
	
	long long DP[n];
	DP[0]=DP[1]=1e18;
	DP[2]=v[2].first-v[0].first;
	
	int pre[n];
	pre[2]=-1;
	 
	for(int i=3;i<n;i++)
	{
		long long temp1=DP[i-3]+v[i].first-v[i-2].first;
		long long temp2=DP[i-1]+v[i].first-v[i-1].first;
		
		if(temp1<temp2)
		{
			DP[i]=temp1;
			pre[i]=i-3;
		}
		else
		{
			DP[i]=temp2;
			pre[i]=pre[i-1];
		}
	}
	
	int ans[n];
	int start=n-1;
	
	int team=1;
	
	while(start!=-1)
	{
		for(int j=pre[start]+1;j<=start;j++)
		{
			ans[v[j].second]=team;
		}
		team++;
		start=pre[start];
	}
	
	cout<<DP[n-1]<<' '<<team-1<<endl;
	for(int i=0;i<n;i++)
		cout<<ans[i]<<' ';
		
	return 0;
}
