#include<bits/stdc++.h>
using namespace std;

const int maxN=500;

int arr[maxN+1][maxN+1];
char ans[maxN+1][maxN+1];

int n;

bool dfs(int i,int j)
{
	if(i>n || j>n)
		return false;
		
	if(!arr[i][j])
		return false;
	
	if(i==n && j==n)
		return true;
		
	if(dfs(i+1,j))
	{
		ans[i][j]='D';
		return true;
	}
	
	if(dfs(i,j+1))
	{
		ans[i][j]='R';
		return true;
	}
	
	return false;
}
int main()
{
	cin>>n;
		
	int s_x=1,s_y=1;
	int e_x=n,e_y=n;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			arr[i][j]=0;
	}
	
	vector<pair<int,int> > v;
	
	v.push_back({1,1});
	arr[1][1]=1;
	
	string s;
	
	while(e_x-s_x + e_y-s_y > n)
	{
		cout<<"? "<<s_x+1<<' '<<s_y<<' '<<e_x<<' '<<e_y<<endl;
		cin>>s;
		
		if(s=="YES")
		{
			s_x++;
		}
		else
		{
			s_y++;
		}
		arr[s_x][s_y]=1;
		v.push_back({s_x,s_y});
	}
	
	int i=v.size()-1;
	
	arr[n][n]=1;
	
	while(i>=0)
	{
		cout<<"? "<<v[i].first<<' '<<v[i].second<<' '<<e_x<<' '<<e_y-1<<endl;
		cin>>s;
		
		if(s=="YES")
		{
			e_y--;
		}
		else
		{
			e_x--;
		}
		
		arr[e_x][e_y]=1;
				
		i--;
	}
	
	dfs(1,1);
	
	int x=1,y=1;
	
	cout<<"! ";
	while(x<n || y<n)
	{
		cout<<ans[x][y];
		
		if(ans[x][y]=='D')
			x++;
		else
			y++;
	}
	return 0;
}
