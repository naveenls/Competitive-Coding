#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		string arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		bool ok[n][m];
		bool visited[n][m];
		memset(visited,0,sizeof(visited));
		
		ok[n-1][m-1]=1;
		
		for(int i=n-2;i>=0;i--)
		{
			if(arr[i][m-1]=='#')
			{
				ok[i][m-1]=false;
			}
			else
			{
				ok[i][m-1]=ok[i+1][m-1];
			}
		}
		
		for(int j=m-2;j>=0;j--)
		{
			if(arr[n-1][j]=='#')
			{
				ok[n-1][j]=false;
			}
			else
			{
				ok[n-1][j]=ok[n-1][j+1];
			}
		}
		
		for(int i=n-2;i>=0;i--)
		{
			for(int j=m-2;j>=0;j--)
			{
				if(arr[i][j]=='#')
				{
					ok[i][j]=false;
					continue;
				}
				
				ok[i][j]=ok[i+1][j] | ok[i][j+1];
			}
		}
		
		vector< pair<int,int> > v[26];
		
		string ans="";
		
		v[arr[0][0]-'a'].push_back({0,0});
		visited[0][0]=true;
		
		int x,y;
		for(int i=0;i<n+m-1;i++)
		{
			int j=0;
			while(j<26 && v[j].size()==0)
				j++;
			
			//cout<<j<<endl;
			
			ans.push_back((char)j+'a');
				
			vector<pair<int,int> > temp;
			
			for(auto pr:v[j])
			{
				temp.push_back(pr);
			}
			for(int k=0;k<26;k++)
				v[k].clear();
				
			for(auto pr:temp)
			{
				x=pr.first,y=pr.second;
								
				if(x<n-1 && ok[x+1][y] && !visited[x+1][y])
				{
					v[arr[x+1][y]-'a'].push_back({x+1,y});
					visited[x+1][y]=true;
				}
				if(y<m-1 && ok[x][y+1] && !visited[x][y+1])
				{
					v[arr[x][y+1]-'a'].push_back({x,y+1});
					visited[x][y+1]=true;
				}
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
