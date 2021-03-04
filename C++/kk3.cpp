#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		int arr[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>arr[i][j];
			}
		}
		
		int dist1[n][m],dist2[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				dist1[i][j]=i+j;
				dist2[i][j]=n-i+m-j-2;
			}
		}
		
		map<int,int> mp;
		map<int,int> mp1;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(dist1[i][j]<dist2[i][j])
				{
					mp[dist1[i][j]]+=arr[i][j];
					mp1[dist1[i][j]]++;
				}
				else if(dist1[i][j]>dist2[i][j])
				{
					mp[dist2[i][j]]+=arr[i][j];
					mp1[dist2[i][j]]++;
				}
			}
		}
		
		int ans=0;
		for(auto itr=mp.begin();itr!=mp.end();++itr)
		{
			ans+=min(itr->second,mp1[itr->first]-itr->second);
		}
		cout<<ans<<endl;
	}
	return 0;
}
