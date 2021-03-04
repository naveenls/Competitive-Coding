#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{	
	map<int,int> freq;
	int temp;
	
	map<int,int> mp1,mp2;
	
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		freq[temp]++;
		mp1[temp]++;
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		freq[temp]++;
		mp2[temp]++;
	}
	
	for(auto itr=freq.begin();itr!=freq.end();++itr)
	{
		//cout<<itr->first<<' '<<itr->second<<endl;
		if(itr->second%2)
		{
			cout<<-1<<endl;
			return;
		}
	}

	int min_val=min(mp1.begin()->first,mp2.begin()->first);

	vector<int> first,second;
	
	for(auto itr=mp1.begin();itr!=mp1.end();++itr)
	{
		int val=itr->first;
		
		while(itr->second--)
		{
			if(mp2[val])
			{
				mp2[val]--;
			}
			else
			{
				first.push_back(val);
			}
		}
	}
	
	for(auto itr=mp2.begin();itr!=mp2.end();++itr)
	{
		while(itr->second)
		{
			second.push_back(itr->first);
			itr->second--;
		}
	}
	
	multiset<int> final;
	for(int i=0;i<first.size();i+=2)
	{
		final.insert(first[i]);
	}
	for(int i=0;i<second.size();i+=2)
	{
		final.insert(second[i]);
	}
	
	long long ans=0;

	int size=final.size();
		
	auto itr=final.begin();
	 
	for(int i=0;i<size/2;i++)
	{
		ans+=(long long)min(2*min_val,*itr);
		itr++;
	}
	
	cout<<ans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		solve(n);
	}
	return 0;
}
