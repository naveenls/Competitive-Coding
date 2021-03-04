#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5+1;

int main()
{
	int n;
	cin>>n;
	
	int arr[maxN]={0};
	int a;
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr[a]++;
	}
	
	vector<pair<int,int> > v;
	for(int i=0;i<maxN;i++)
	{
		if(arr[i])
		{
			v.push_back({i,arr[i]});
		}
	}
	int start=0,end=0;
	
	int t_size=v[0].second;
	int ma=v[0].second;
	
	int ind=0;
	
	for(int i=1;i<v.size();i++)
	{
		if(v[i].first==v[i-1].first+1)
		{
			t_size+=v[i].second;
			if(t_size>ma)
			{
				ma=t_size;
				ind=i;
			}
			
			if(v[i].second==1)
			{
				t_size=1;
			}
		}
		else
		{
			t_size=v[i].second;
			
			if(t_size>ma)
			{
				ma=t_size;
				ind=i;
			}
		}
	}
	cout<<ma<<endl;
	
	int start_ind=ind;
	
	for(int i=ind-1;i>=0;i--)
	{
		if(v[i].first+1==v[i+1].first)
		{
			if(v[i].second==1)
			{
				start_ind=i;
				break;
			}
			else
			{
				start_ind=i;
			}
		}
		else
			break;
	}
	for(int i=start_ind;i<=ind;i++)
	{
		cout<<v[i].first<<' ';
		v[i].second--;
	}
	for(int i=ind;i>=start_ind;i--)
	{
		while(v[i].second--)
		{
			cout<<v[i].first<<' ';
		}
	}
	return 0;
}
