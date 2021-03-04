#include<bits/stdc++.h>
using namespace std;

void print_path(int i,int j)
{
	vector<pair<int,int> > ans;
	while(i)
	{
		ans.push_back({i,j});
		i--;
	}
	while(j)
	{
		ans.push_back({i,j});
		j--;
	}
	ans.push_back({0,0});
	
	reverse(ans.begin(),ans.end());
	for(auto pr:ans)
	{
		cout<<'('<<pr.first+1<<','<<pr.second+1<<')'<<' ';
	}
	cout<<endl;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	
	int arr[n][m];
	vector<pair<int,pair<int,int> > > v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			v.push_back({i+j,{i,j}});
		}
	}
	sort(v.begin(),v.end());
	int sum=0;
	for(int i=k-1;i>=0;i--)
	{
		sum+=(v[i].first+1);
	}
	cout<<sum<<endl;
	for(int i=k-1;i>=0;i--)
	{
		print_path(v[i].second.first,v[i].second.second);
	}
	return 0;
}
