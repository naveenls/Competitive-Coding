#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	map<int,vector<int> > mp;
	map<int,int> cnt;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(mp.find(a)!=mp.end())
		{
			mp[a].push_back(b);
			cnt[a]++;
		}
		else
		{
			mp[a]={b};
			cnt[a]=1;
		}
		
		if(mp.find(b)!=mp.end())
		{
			mp[b].push_back(a);
			cnt[b]++;
		}
		else
		{
			mp[b]={a};
			cnt[b]=1;
		}
	}
	int start;
	for(auto itr=cnt.begin();itr!=cnt.end();itr++)
	{
		if((itr->second)==1)
		{
			start=itr->first;
			break;
		}
	}

	vector<int> ans;
	ans.push_back(start);
	
	int prev=-1;
	while(true)
	{
		int next=-1;
		for(auto ele:mp[start])
		{
			if(ele!=prev)
			{
				next=ele;
				break;
			}
		}
		if(next==-1)
			break;
			
		prev=start;
		start=next;
		ans.push_back(start);
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
