#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

map<int,int> countval;
int count_equal;

void clear()
{
	count_equal=0;
	countval.clear();
}

void insert(int a)
{	
	if(mp.find(a)!=mp.end())
	{
		countval[a]++;
		if(countval[a]==mp[a])
		{
			count_equal++;
		}
		else if(countval[a]==mp[a]+1)
		{
			count_equal--;
		}
	}
	//cout<<mp.size()<<endl;	
}

void replace(int a,int b)
{
	if(a==b)
		return;
		
	if(mp.find(a)!=mp.end())
	{
		countval[a]--;
		
		if(countval[a]==mp[a])
		{
			count_equal++;	
		}
		else if(countval[a]==mp[a]-1)
		{
			count_equal--;
		}
	}
	
	if(mp.find(b)!=mp.end())
	{
		countval[b]++;
		if(countval[b]==mp[b])
		{
			count_equal++;
		}
		else if(countval[b]==mp[b]+1)
		{
			count_equal--;
		}
	}
	//cout<<mp.size()<<endl;	
}

bool check()
{	
	return count_equal==mp.size();
}

int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	
	vector<int> v[p];
	int a[n];
	int b[m];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		v[i%p].push_back(i);
	}
	
	for(int i=0;i<m;i++)
		cin>>b[i],mp[b[i]]++;

	vector<int> ans;

	for(int t=0;t<p;t++)
	{
		if(v[t].size()>=m)
		{			
			clear();
			
			for(int i=0;i<m;i++)
			{
				insert(a[v[t][i]]);
			}
			
			if(check())
			{
				ans.push_back(v[t][0]+1);
			}
			
			for(int i=0;i<v[t].size()-m;i++)
			{
				int j=i+m;
				
				replace(a[v[t][i]],a[v[t][j]]);
				
				if(check())
				{
					ans.push_back(v[t][i+1]+1);
				}
			}
		}
	}
	
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	
	for(auto ele:ans)
		cout<<ele<<' ';
		
	
	return 0;
}
