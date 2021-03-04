#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	
	cin>>n>>m;
	
	int max_poss[n],diff[n];
	for(int i=0;i<n;i++)
	{
		max_poss[i]=1e9;
		diff[i]=0;
	}
	
	vector<int> types;
	vector<pair<int,int> > range;
	vector<int> value;
	
	int type,l,r,val;
	for(int i=0;i<m;i++)
	{
		cin>>type>>l>>r>>val;
		
		l--,r--;
		
		types.push_back(type);
		range.push_back({l,r});
		value.push_back(val);
		
		if(type==1)
		{
			for(int j=l;j<=r;j++)
			{
				diff[j]+=val;
			}
		}
		else
		{
			for(int j=l;j<=r;j++)
			{
				max_poss[j]=min(max_poss[j],val-diff[j]);
			}
		}
	}
	
	int ans[n];
	for(int i=0;i<n;i++)
		ans[i]=max_poss[i];
	
	for(int i=0;i<n;i++)
	{
		if(max_poss[i]<-1e9)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	for(int i=0;i<m;i++)
	{
		type=types[i];
		l=range[i].first;
		r=range[i].second;
		val=value[i];
		
		if(type==1)
		{
			for(int j=l;j<=r;j++)
			{
				max_poss[j]+=val;
			}
		}
		else
		{
			int ma=-1e9;
			for(int j=l;j<=r;j++)
			{
				ma=max(max_poss[j],ma);
			}
			if(ma!=val)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
		cout<<ans[i]<<' ';
	return 0;
}
