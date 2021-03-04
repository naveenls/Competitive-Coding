#include<bits/stdc++.h>
using namespace std;
const int maxN=2*1e5+10;

vector<int> adj[maxN];

int par[maxN];
int num_01[maxN]={0};
int num_10[maxN]={0};
bool col[maxN]={0};

int b[maxN];
int c[maxN];

void dfs1(int i,int p)
{
	par[i]=p;
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			dfs1(ch,i);
		}
	}
}	
void dfs(int i,int p)
{
	if(col[i]==1)
	{
		num_01[i]=0;
		num_10[i]=0;
		return;
	}

	col[i]=1;
	
	if(b[i]==0 && c[i]==1)
		num_01[i]++;
	else if(b[i]==1 && c[i]==0)
		num_10[i]++;
		
	for(auto ch:adj[i])
	{
		if(ch!=p)
		{
			dfs(ch,i);
			num_01[i]+=num_01[ch];
			num_10[i]+=num_10[ch];
		}
	}
}
int main()
{
	int n;
	cin>>n;
	
	long long a_;
	int b_,c_;
	
	int c1=0;
	int c2=0;
	
	vector<pair<long long,int> > v(n);

	for(int i=0;i<n-1;i++)
	{
		cin>>a_>>b_>>c_;
		v.push_back({a_,i});
		b[i]=b_;
		c[i]=c_;
		
		c1+=b_;
		c2+=c_;
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>c_>>b_;
		c_--;
		b_--;
		
		adj[c_].push_back(b_);
		adj[b_].push_back(c_);
	}
	
	if(c1!=c2)
		cout<<-1<<endl;
	else
	{
		sort(v.begin(),v.end());
		dfs1(0,-1);
		
		long long ans=0;
		
		for(auto ele: v)
		{
			if(col[ele.second]==0)
			{
				long long num_a=0;
				long long num_b=0;
				
				for(auto ch:adj[ele.second])
				{
					if(ch!=par[ele.second])
					{
						dfs(ch,ele.second);
						num_a+=num_01[ch];
						num_b+=num_10[ch];
					}
				}
				
				int i=ele.second;
				if(b[i]==0 && c[i]==1)
					num_a++;
				else if(b[i]==1 && c[i]==0)
					num_b++;
					
				ans+= (long long)(min(num_a,num_b)*ele.first);
				num_01[i]=num_a-min(num_a,num_b);
				num_10[i]=num_b-min(num_a,num_b);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
