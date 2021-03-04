#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,g,m;
	cin>>n>>g>>m;

	if(m>=n)
	{
		m=n+m%n;	
	}
		
	set<int> a;
	
	for(int i=0;i<n;i++)
	{
		a.insert(i);
	}
	
	vector<int> clock[n];
	vector<int> aclock[n];
		
	int ind;
	char c;
	
	int ans[g]={0};
	
	for(int i=0;i<g;i++)
	{
		cin>>ind>>c;
		ind--;
		
		if(c=='C')
		{
			clock[ind].push_back(i);
		}
		else
		{
			aclock[ind].push_back(i);
		}
	}
	
	for(int i=m;i>=0 && a.size() ; i--)
	{
		vector<int> erase;
				
		for(auto j:a)
		{
			int ini=(j-i)%n;
			
			bool fl=0;
			
			ini=(ini+n)%n;
			
			if(clock[ini].size())
			{
				fl=1;
				for(auto ind:clock[ini])
				{
					ans[ind]++;
				}
			}
			
			ini=(j+i)%n;
			
			if(aclock[ini].size())
			{
				fl=1;
				for(auto ind:aclock[ini])
				{
					ans[ind]++;
				}
			}
			
			if(fl)
				erase.push_back(j);
		}
		
		for(auto j:erase)
			a.erase(j);
	}
	
	for(int i=0;i<g;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve(); 
	}
	return 0;
}
