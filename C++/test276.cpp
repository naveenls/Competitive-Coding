#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

int arr[maxN][20];
vector<int> adj[maxN];

long long odd[maxN][20];
long long even[maxN][20];

long long ans=0;

void dfs(int i,int p)
{
	
	vector<long long> odd_[20],even_[20];
	
	int num_child=0;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			dfs(ch,i);
			num_child++;
			
			for(int j=0;j<20;j++)
			{
				if(arr[i][j])
				{
					odd[i][j]+=even[ch][j];
					even[i][j]+=odd[ch][j];
				}
				else
				{
					odd[i][j]+=odd[ch][j];
					even[i][j]+=even[ch][j];
				}
				
				odd_[j].push_back(odd[ch][j]);
				even_[j].push_back(even[ch][j]);
			}
		}
	}
	
	for(int j=0;j<20;j++)
	{
		long long num_pairs=0;
		if(arr[i][j])
		{
			long long sum=0;
			long long sum1=0;
			
			for(int k=0;k<num_child;k++)
			{
				sum+=odd_[j][k];
				sum1+=even_[j][k];
				
				num_pairs-=(odd_[j][k]*odd_[j][k]);
				num_pairs-=(even_[j][k]*even_[j][k]);
				
				ans+=even_[j][k]*(1<<j);
			}
			num_pairs=(num_pairs + sum*sum + sum1*sum1)/2;
		}
		else
		{
			long long sum=0;
			long long sum1=0;
						
			for(int k=0;k<num_child;k++)
			{
				sum+=odd_[j][k];
				sum1+=even_[j][k];
				
				num_pairs-=(odd_[j][k]*even_[j][k]);
				
				ans+=odd_[j][k]*(1<<j);
			}
			num_pairs=(num_pairs + sum*sum1);
		}
		ans+=num_pairs*(1<<j);
	}
	//cout<<ans<<endl;
	for(int j=0;j<20;j++)
	{
		if(arr[i][j])
		{
			odd[i][j]++;
		}
		else
		{
			even[i][j]++;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	
	int temp;
	
	long long s=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		s+=temp;
		for(int j=0;j<20;j++)
		{
			arr[i][j]=temp%2;
			temp/=2;
		}
	}
	int u,v;
	
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v,u--,v--;
		
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}
	memset(odd,0,sizeof(odd));
	memset(even,0,sizeof(even));
	
	dfs(0,-1);
	cout<<ans+s<<endl;
}
