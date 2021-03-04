#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	
	map<int,vector<int> > mp;
	int val;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d", &val);
			mp[val].push_back(i*n+j);
		}
	
	int ans = 0;
	
	for(auto itr=mp.begin();itr!=mp.end();itr++)
	{
		for(auto itr1 = itr;itr1!=mp.end();itr1++)
		{
			ans = max(ans, max_connected(itr->second, itr1->second));		
		}
	}
	return 0;
}

