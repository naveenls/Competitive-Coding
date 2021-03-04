#include<bits/stdc++.h>
using namespace std;

const int N=2000;

string s[N];

int n,m;

int count(int i,int j)
{
	if(i<0 || i>=n || j<0 || j>=m || s[i][j]!='.')
		return -1;
		
	int cnt=0;
	
	if(i+1<n && s[i+1][j]=='.')
	{
		cnt++;
	}
	if(i && s[i-1][j]=='.')
	{
		cnt++;
	}
	if(j+1<m && s[i][j+1]=='.')
	{
		cnt++;
	}
	if(j && s[i][j-1]=='.')
	{
		cnt++;
	}
	
	return cnt;
}

pair<int,int> get(int i,int j)
{
	if(i+1<n && s[i+1][j]=='.')
	{
		return {i+1,j};
	}
	if(i && s[i-1][j]=='.')
	{
		return {i-1,j};
	}
	if(j+1<m && s[i][j+1]=='.')
	{
		return {i,j+1};
	}
	if(j && s[i][j-1]=='.')
	{
		return {i,j-1};
	}
	
	return {-1,-1};
}
int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
		
	queue<pair<int,int> > q;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{			
			if(count(i,j)==1)
			{
				q.push({i,j});
			}
		}
	}
	
	while(!q.empty())
	{
		auto pr=q.front();
		q.pop();
		
		int x=pr.first,y=pr.second;
		
		if(s[x][y]=='.')
		{
			auto pr=get(x,y);
			
			int x1=pr.first;
			int y1=pr.second;
			
			if(x1==-1 || y1==-1)
			{
				cout<<"Not unique"<<endl;
				return 0;
			}
				
			if(x1>x)
			{
				s[x][y]='^';
				s[x1][y1]='v';
			}
			else if(x1<x)
			{
				s[x][y]='v';
				s[x1][y1]='^';
			}
			else if(y1>y)
			{
				s[x][y]='<';
				s[x1][y1]='>';
			}
			else
			{
				s[x][y]='>';
				s[x1][y1]='<';
			}
						
			if(count(x1+1,y1)==1)
			{
				q.push({x1+1,y1});
			}
			if(count(x1-1,y1)==1)
			{
				q.push({x1-1,y1});
			}
			if(count(x1,y1+1)==1)
			{
				q.push({x1,y1+1});
			}
			if(count(x1,y1-1)==1)
			{
				q.push({x1,y1-1});
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='.')
			{
				cout<<"Not unique"<<endl;
				return 0;
			}
		}
	}
	
	for(int i=0;i<n;i++)
		cout<<s[i]<<endl;
		
	return 0;
}
