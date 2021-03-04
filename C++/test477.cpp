#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int k;
	
	vector<int> v[2];
	int temp;
	
	for(int i=0;i<2;i++)
	{
		cin>>k;
		
		while(k--)
		{
			cin>>temp;
			v[i].push_back(temp);
		}
	}
	
	int ans[2][n];
	int rem[2][n];
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans[i][j]=-1;
			rem[i][j]=v[i].size();
		}
	}
	
	queue<pair<int,int> > q;
	queue<int> type;
	
	type.push(0);
	type.push(0);
	
	q.push({0,0});
	q.push({0,1});
	
	while(!q.empty())
	{
		int t=type.front();
		type.pop();
		
		int ind=q.front().first;
		int p=q.front().second;
		q.pop();
		
		ans[p][ind]=t;
		
		//cout<<p<<' '<<ind<<endl;
		if(t)
		{
			for(auto x:v[1-p])
			{
				//cout<<x<<endl;
				int j=(ind-x+n)%n;
				
				rem[1-p][j]--;
				
				if(!rem[1-p][j] && ans[1-p][j]==-1)
				{
					type.push(0);
					q.push({j,1-p});
				}
			}
		}
		else
		{
			for(auto x:v[1-p])
			{
				int j=(ind-x+n)%n;
				
				if(ans[1-p][j]==-1)
				{
					type.push(1);
					q.push({j,1-p});
				}
			}
		}
	}
	
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(ans[i][j]==1)
			{
				cout<<"Win ";
			}
			else if(ans[i][j]==0)
			{
				cout<<"Lose ";
			}
			else
			{
				cout<<"Loop ";
			}
		}
		cout<<endl;
	}
	return 0;
}
