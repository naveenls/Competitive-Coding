#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	string s[n];
	int arr[n][m];
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		for(int j=0;j<m;j++)
			arr[i][j]=s[i][j]-'0';
	}
	
	if(n>=4 && m>=4)
	{
		cout<<-1<<endl;
	}
	else if(m<2 || n<2)
	{
		cout<<0<<endl;
	}
	else
	{
		if(m==2 || n==2)
		{
			vector<int> adj[4];
			
			adj[0]={1,2};
			adj[1]={0,3};
			adj[2]={0,3};
			adj[3]={1,2};
			
			if(n==2)
			{
				int DP[m+1][4];
				
				for(int i=0;i<4;i++)
				{
					DP[m][i]=0;
				}
				
				for(int j=m-1;j>=0;j--)
				{
					bool f1=(arr[0][j]);
					bool f2=(arr[1][j]);
					
					for(int stat=0;stat<4;stat++)
					{
						DP[j][stat]=1e9;
						
						bool a=(stat&2);
						bool b=(stat&1);
							
						int cnt=(a!=f1) + (b!=f2);
							
						for(auto ele:adj[stat])
						{
							DP[j][stat]=min(DP[j][stat],DP[j+1][ele]+cnt);
						}
					}
				}
				
				int mi=1e9;
				
				for(int i=0;i<4;i++)
					mi=min(mi,DP[0][i]);
					
				cout<<mi<<endl;
			}
			else
			{
				int DP[n+1][4];
				
				for(int i=0;i<4;i++)
				{
					DP[n][i]=0;
				}
				
				for(int j=n-1;j>=0;j--)
				{
					bool f1=(arr[j][1]);
					bool f2=(arr[j][0]);
					
					for(int stat=0;stat<4;stat++)
					{
						DP[j][stat]=1e9;
						
						bool a=(stat&2);
						bool b=(stat&1);
							
						int cnt=(a!=f1) + (b!=f2);
							
						for(auto ele:adj[stat])
						{
							DP[j][stat]=min(DP[j][stat],DP[j+1][ele]+cnt);
						}
					}
				}
				
				int mi=1e9;
				
				for(int i=0;i<4;i++)
					mi=min(mi,DP[0][i]);
					
				cout<<mi<<endl;
			}
		}
		else 
		{
			vector<int> adj[8];
			
			adj[0]={5,2};
			adj[1]={4,3};
			adj[2]={0,7};
			adj[3]={1,6};
			adj[4]={1,6};
			adj[5]={0,7};
			adj[6]={4,3};
			adj[7]={2,5};
			
			
			if(n==3)
			{
				int DP[m+1][8];
				
				for(int i=0;i<8;i++)
				{
					DP[m][i]=0;
				}
				
				for(int j=m-1;j>=0;j--)
				{
					bool f1=(arr[0][j]);
					bool f2=(arr[1][j]);
					bool f3=(arr[2][j]);
				
					for(int stat=0;stat<8;stat++)
					{
						DP[j][stat]=1e9;
						
						bool a=(stat&4);
						bool b=(stat&2);
						bool c=(stat&1);
							
						int cnt=(a!=f1) + (b!=f2) + (c!=f3);
							
						for(auto ele:adj[stat])
						{
							DP[j][stat]=min(DP[j][stat],DP[j+1][ele]+cnt);
						}
						
					}
				}
				
				int mi=1e9;
				
				for(int i=0;i<8;i++)
					mi=min(mi,DP[0][i]);
					
				cout<<mi<<endl;
			}
			else
			{
				int DP[n+1][8];
				
				for(int i=0;i<8;i++)
				{
					DP[n][i]=0;
				}
								
				for(int j=n-1;j>=0;j--)
				{
					bool f1=(arr[j][2]);
					bool f2=(arr[j][1]);
					bool f3=(arr[j][0]);
						
					for(int stat=0;stat<8;stat++)
					{
						DP[j][stat]=1e9;
						
						bool a=(stat&4);
						bool b=(stat&2);
						bool c=(stat&1);
							
						int cnt=(a!=f1) + (b!=f2) + (c!=f3);
							
						for(auto ele:adj[stat])
						{
							DP[j][stat]=min(DP[j][stat],DP[j+1][ele]+cnt);
						}
						
					}
				}
				
				int mi=1e9;
				
				for(int i=0;i<8;i++)
					mi=min(mi,DP[0][i]);
					
				cout<<mi<<endl;
			}
		}
	}
	return 0;
}
