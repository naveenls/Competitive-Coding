#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int w_pos[n][n];
		int m[n][n];
		
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			for(int j=0;j<n;j++)
			{
				cin>>temp;
				temp--;
					
				w_pos[i][temp]=j;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			for(int j=0;j<n;j++)
				cin>>m[i][j],m[i][j]--;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<w_pos[i][j]<<' ';
			cout<<endl;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<m[i][j]<<' ';
			cout<<endl;
		}
		
		int w_p[n],m_p[n];
		memset(w_p,-1,sizeof(w_p));
		memset(m_p,-1,sizeof(m_p));
		
		for(int i=0;i<n;i++)
		{
			map<int,int> mp;
			
			for(int j=0;j<n;j++)
			{
				if(m_p[j]==-1 && w_p[m[j][i]]==-1)
				{
					if(mp.find(m[j][i])==mp.end())
					{
						mp[m[j][i]]=j;
					}
					else
					{
						int men=mp[m[j][i]];
						int women=m[j][i];
						
						if(w_pos[women][j]<w_pos[women][men])
						{
							mp[women]=j;
						}
					}
				}
			}
			
			for(auto ele:mp)
			{
				m_p[ele.second]=ele.first;
				w_p[ele.first]=ele.second;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<' '<<m_p[i]+1<<endl;
		}
	}
	return 0;
}
