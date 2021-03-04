#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	string arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]!='#' && arr[i][j]!='.')
				v.push_back({i,j});
		}
	}
	
	int DP[n][m];
	int DP1[n][m];
	
	for(int i=0;i<n;i++)
	{
		if(arr[i][0]=='#')
			DP[i][0]=1;
		else
			DP[i][0]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(arr[i][j]=='#')
			{
				DP[i][j]=1+DP[i][j-1];
			}
			else
				DP[i][j]=DP[i][j-1];
		}
	}
	
	for(int i=0;i<m;i++)
	{
		if(arr[0][i]=='#')
			DP1[0][i]=1;
		else
			DP1[0][i]=0;
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='#')
			{
				DP1[i][j]=1+DP1[i-1][j];
			}
			else
				DP1[i][j]=DP1[i-1][j];
		}
	}
	
	int k;
	cin>>k;
	
	char c;
	int temp;
	
	vector<pair<int,int> > pos(k);
	for(int i=0;i<k;i++)
	{
		cin>>c>>temp;
		if(c=='S')
		{
			pos[i]={temp,0};
		}
		else if(c=='N')
		{
			pos[i]={-temp,0};
		}
		else if(c=='E')
		{
			pos[i]={0,temp};
		}
		else
		{
			pos[i]={0,-temp};
		}
	}
	
	string s="";
	
	for(auto ind:v)
	{
		int a=ind.first;
		int b=ind.second;
		
		bool flag=0;
		
		for(int i=0;i<k;i++)
		{
			int t1=a,t2=b;
			
			a+=pos[i].first;
			b+=pos[i].second;
			
			if(a<0 || a>=n || b<0 || b>=m)
			{
				flag=1;
				break;	
			}
			
			if(a==t1)
			{
				int temp=min(b,t2);
				int b1=max(b,t2);
				
				if(temp && DP[a][b1]-DP[a][temp-1]!=0)
				{
					flag=1;
					break;
				}
				if(!temp && DP[a][b1]!=0)
				{
					flag=1;
					break;
				}				
			}
			else
			{
				int temp=min(a,t1);
				int a1=max(a,t1);
				
				if(temp && DP1[a1][b]-DP1[temp-1][b]!=0)
				{
					flag=1;
					break;
				}
				if(!temp && DP1[a1][b]!=0)
				{
					flag=1;
					break;
				}
			}
		}
		if(!flag)
			s.push_back(arr[ind.first][ind.second]);	
	}
	
	sort(s.begin(),s.end());
	
	if(s.size()==0)
	{
		cout<<"no solution"<<endl;
		return 0;
	}
	cout<<s<<endl;
	return 0;
}
