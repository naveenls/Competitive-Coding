#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

long long val[2*maxN+1]={0};

void BuildTree(long long arr[],int ind,int start,int end)
{        
        if(start==end)
        {
            val[ind]=arr[start];
        }
        else
        {
            long long mid=(start+end)/2;
            BuildTree(arr,2*ind+1,start,mid);
            BuildTree(arr,2*ind+2,mid+1,end);

            val[ind]=val[2*ind+1] + val[2*ind+2];
        }
}

void Update(long long diff,int pos,int ind,int start,int end)
{
	if(pos<start || pos>end)
		return;

	if(start==end)
	{
		val[ind]+=diff;
	}
	else
	{
		int mid=(start+end)>>1;
		Update(diff,pos,2*ind+1,start,mid);
		Update(diff,pos,2*ind+2,mid+1,end);	
		val[ind]=val[2*ind+1] + val[2*ind+2];
	}
}

long long get_sum(int ind,int start,int end,int l,int r)
{
	if(start>r || end<l)
		return 0;

	if(start>=l && end<=r)
	{
		return val[ind];
	}
	else
	{
		int mid=(start+end)>>1;
		long long sum1=get_sum(2*ind+1,start,mid,l,r);
		long long sum2=get_sum(2*ind+2,mid+1,end,l,r);	
		return sum1+sum2;
	}
}

vector<int> adj[maxN];
int arr[maxN];
int inT[maxN];
int sz[maxN];

int time_=1;

int dfs(int i,int p)
{
	inT[i]=++time_;
	sz[i]=1;
	
	for(auto ch:adj[i])
	{
		if(ch!=p)
			sz[i]+=dfs(ch,i);
	}
	
	return sz[i];
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0,-1);
	
	vector<pair<int,int> > vec;
	for(int i=0;i<n;i++)
	{
		vec.push_back({inT[i],i});
	}
	
	sort(vec.begin(),vec.end());
	
	long long temp[n];
	map<int,int> mp;
	
	for(int i=0;i<n;i++)
	{
		temp[i]=arr[vec[i].second];
		mp[vec[i].second]=i;
	}
	
	BuildTree(temp,0,0,n-1);
	
	char c;
	
	for(int i=0;i<m;i++)
	{
		cin>>c;
		if(c=='U')
		{
			cin>>u>>v;
			u--;
			
			int ind=mp[u];
			
			Update(v-temp[ind],ind,0,0,n-1);
			
			temp[ind]=v;	
		}
		else
		{
			cin>>u;
			u--;
			
			int ind=mp[u];
						
			cout<<get_sum(0,0,n-1,ind,ind+sz[u]-1)<<endl;
		}	
	}
}
