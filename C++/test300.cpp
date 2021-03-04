#include<bits/stdc++.h>
using namespace std;

int n,m;
const int maxN=500;

string arr[maxN];
bool col[maxN][maxN];

vector<char> type;
vector<pair<int,int> > seq;

int r_i,r_j;

void dfs(int i,int j)
{
	if(i<0 || i>=n || j<0 || j>=m)
		return;
	
	if(arr[i][j]=='#' || col[i][j])
		return;
		
	col[i][j]=1;
	
	type.push_back('B');
	seq.push_back({i+1,j+1});
	
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
	
	if(j!=r_j || i!=r_i)
	{
		type.push_back('D');
		seq.push_back({i+1,j+1});
		
		type.push_back('R');
		seq.push_back({i+1,j+1});
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!col[i][j] && arr[i][j]!='#')
			{
				r_i=i,r_j=j;
				dfs(i,j);
			}
		}
	}
	cout<<seq.size()<<endl;
	
	for(int i=0;i<seq.size();i++)
	{
		cout<<type[i]<<' '<<seq[i].first<<' '<<seq[i].second<<endl;
	}
	return 0;
}
