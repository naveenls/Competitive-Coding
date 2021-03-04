#include<bits/stdc++.h>
using namespace std;

int main()
{

		int n,m;
		cin>>n>>m;
		
		int sx,sy;
		cin>>sx>>sy;
		
		vector<pair<int,int> > ans;
		
		for(int j=sy;j<=m;j++)
		{
			ans.push_back({sx,j});
		}
		for(int j=sy-1;j>=1;j--)
		{
			ans.push_back({sx,j});
		}
		
		bool flag=1;
		
		for(int i=1;i<sx;i++)
		{
			if(flag)
			{
				for(int j=1;j<=m;j++)
				{
					ans.push_back({i,j});
				}
				flag=1-flag;
			}
			else
			{
				for(int j=m;j>=1;j--)
				{
					ans.push_back({i,j});
				}
				flag=1-flag;
			}
		}
		
		for(int i=sx+1;i<=n;i++)
		{
			if(flag)
			{
				for(int j=1;j<=m;j++)
				{
					ans.push_back({i,j});
				}
				flag=1-flag;
			}
			else
			{
				for(int j=m;j>=1;j--)
				{
					ans.push_back({i,j});
				}
				flag=1-flag;
			}
		}
		
		for(auto ele:ans)
		{
			cout<<ele.first<<' '<<ele.second<<endl;
		}
	
	return 0;
}
