#include<bits/stdc++.h>
using namespace std;

const int maxN=5*1e5+10;

vector<int> adj[maxN];
int num[maxN];
bool col[maxN]={0};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b,a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);	
	}
	
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		v[i]={num[i],i};
	}
	
	sort(v.begin(),v.end());
	vector<int> ans;
	
	for(int i=0;i<n;i++)
	{
		set<int> s;
		for(auto ch:adj[v[i].second])
		{
			if(col[ch])
			{
				s.insert(num[ch]);
			}
		}
		int a=1;
		for(auto ele:s)
		{
			if(ele==a)
			{
				a++;
			}
			else
			{
				break;
			}
		}
		
		if(a!=v[i].first)
		{
			cout<<-1<<endl;
			return 0;
		}
		col[v[i].second]=1;
		ans.push_back(v[i].second+1);
	}
	for(auto ele:ans)
	{
		cout<<ele<<' ';
	}
	return 0;
	
}
