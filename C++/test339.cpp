#include<bits/stdc++.h>
using namespace std;

const int maxN=3*1e5;

vector<pair<int,int> > adjG[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	int u,v,w;
		
	vector<pair<int,int> > V(m);
	
	map<int,pair<int,int> > mp;
	
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w,u--,v--;
		adjG[u].push_back({v,w});

		V[i]={w,i};
		mp[i]={u,v};
	}
	
	sort(V.begin(),V.end());
		
	int DP[m]={0};
	int max_DP[n]={0};
	
	int ma=0;
	
	for(int i=m-1;i>=0;)
	{
		int j=i-1;
		
		int ind=V[i].second;
		int vertex=mp[ind].second;
		
		DP[ind]=1+max_DP[vertex];
		
		while(j>=0 && V[j].first==V[j+1].first)
		{
			int ind=V[j].second;
			int vertex=mp[ind].second;
		
			DP[ind]=1+max_DP[vertex];
			
			j--;
		}
		
		for(int k=i;k>j;k--)
		{
			int ind=V[k].second;
			max_DP[mp[ind].first]=max(DP[ind],max_DP[mp[ind].first]);
			
			ma=max(ma,DP[ind]);
		}
		i=j;
	}
	cout<<ma<<endl;
}
