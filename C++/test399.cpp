#include<bits/stdc++.h>
using namespace std;

int find_parent(int i,int par[])
{
	if(i==par[i])
		return i;
		
	par[i]=find_parent(par[i],par);
	return par[i];
}

int main()
{
	int n;
	cin>>n;
	
	int cnt[26]={0};
	int par[26];
	
	for(int i=0;i<26;i++)
	{
		par[i]=i;
	}
	
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		set<char> ss;
		
		for(int j=0;j<s.size();j++)
		{
			cnt[s[j]-'a']++;
			ss.insert(s[j]);
		}
		
		auto itr=ss.begin();
		char start=*itr;
		
		++itr;
		while(itr!=ss.end())
		{
			int a=find_parent(start-'a',par);
			int b=find_parent(*itr-'a',par);
			
			if(a!=b)
			{
				par[b]=a;
			}
			++itr;
		}
	}
	
	set<int> ans;
	for(int i=0;i<26;i++)
	{
		if(cnt[i])
		{
			ans.insert(find_parent(i,par));
		}
	}
	cout<<ans.size()<<endl;
	
	return 0;
}
