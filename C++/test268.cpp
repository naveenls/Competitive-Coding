#include<bits/stdc++.h>
using namespace std;

const int maxN=50000;
const int maxK=500;

vector<int> adj[maxN];
long long cnt[maxN][maxK+1];

int n,k;

long long dfs(int i,int p)
{
	long long ans=0;
	
	cnt[i][0]=1;
	
	vector<long long> arr[k+1];
	int num_ch=0;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			ans+=dfs(ch,i);
			num_ch++;
			
			for(int j=1;j<=k;j++)
			{
				cnt[i][j]+=cnt[ch][j-1];
				
				arr[j].push_back(cnt[ch][j-1]);
			}
		}
	}
	ans+=cnt[i][k];
	
	for(int t=1;t<k;t++)
	{
		if(t<k-t)
		{
			long long sum1=0,sum2=0;
			for(int j=0;j<num_ch;j++)
			{
				sum1+=arr[t][j];
				sum2+=arr[k-t][j];
			}
			ans+=sum1*sum2;
			
			for(int j=0;j<num_ch;j++)
			{
				ans-=arr[t][j]*arr[k-t][j];
			}
		}
		else if(t==k-t)
		{
		    long long sum1=0;
		    long long sum2=0;
		    
			for(int j=0;j<num_ch;j++)
			{
				sum1+=arr[t][j];
				sum2+=arr[t][j]*arr[t][j];
			}
			ans+=(sum1*sum1-sum2)/2;
		}
		else
		{
		    break;
		}
	}
	return ans;
}
int main()
{
	int n,k;
	cin>>n>>k;
	
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--,v--;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	memset(cnt,0,sizeof(cnt));
	cout<<dfs(0,-1)<<endl;	
}
