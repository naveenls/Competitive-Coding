#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<pair<int,int> > v(n);
	
	for(int i=0;i<n;i++)
		cin>>v[i].first;
		
	for(int i=0;i<n;i++)
		cin>>v[i].second;
		
	sort(v.begin(),v.end());
	
	int d[201]={0};
	int DP[n];
	
	DP[0]=v[0].second;
	
	for(int i=1;i<n;i++)
		DP[i]=DP[i-1]+v[i].second;
		
	int min_cost=1e9;
	
	for(int i=0;i<n;)
	{
		int j=i+1;
		
		while(j<n && v[j].first==v[j-1].first)
			j++;
			
		int len=j-i;
		
		int cost=DP[n-1]-DP[j-1];
		
		int extra=max(0,i-(len-1));
		
		int start=1;
		while(extra)
		{
			cost+=start*(min(extra,d[start]));
			extra-=min(extra,d[start]);
			
			start++;
		}
		
		min_cost=min(min_cost,cost);
		
		for(int k=i;k<j;k++)
		{
			d[v[k].second]++;
		}
		i=j;
	}
	cout<<min_cost<<endl;
	return 0;
}
