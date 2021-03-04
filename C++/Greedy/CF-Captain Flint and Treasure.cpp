#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5;

int arr[maxN];
bool col[maxN]={0};

vector<int> adj[maxN];
vector<int> before[maxN];
vector<int> after[maxN];
long long maxVal[maxN];

long long dfs(int i)
{
	//cout<<i<<' '<<col[i]<<endl;
	
	if(col[i]==0)
	{
		col[i]=1;
		
		maxVal[i]=arr[i];
		
		for(auto ch:adj[i])
		{
			long long val=dfs(ch);
			if(val<0)
			{
				after[i].push_back(ch);
			}
			else
			{
				maxVal[i]+=val;
				before[i].push_back(ch);
			}
		}
		
		return maxVal[i];
	}
	else
	{
		return maxVal[i];
	}
}

void find_order(int i,vector<int> &order)
{
	for(auto ch:before[i])
	{
		find_order(ch,order);
	}
	order.push_back(i);
	
	for(auto ch:after[i])
	{
		find_order(ch,order);
	}
}
int main()
{
	int n;
	cin>>n;
	
	int b[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		
		if(b[i]!=-1)
		{
			b[i]--;
			adj[b[i]].push_back(i);
		}
	}
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(col[i]==0)
		{
			dfs(i);
		}
		
		ans+=maxVal[i];
	}
	
	vector<int> order;
	
	for(int i=0;i<n;i++)
	{
		if(b[i]==-1)
		{
			find_order(i,order);
		}
	}
	
	cout<<ans<<endl;
	for(auto ele:order)
	{
		cout<<ele+1<<' ';
	}
	
	return 0;
}
