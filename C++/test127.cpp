#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	int DP[n][m];
	for(int i=0;i<n;i++)
	{
		DP[i][m-1]=s[i][m-1]-'0';
	}
	for(int i=0;i<n;i++)
	{
		for(int j=m-2;j>=0;j--)
		{
			if(s[i][j]=='1')
				DP[i][j]=DP[i][j+1]+1;
			else
				DP[i][j]=0;
		}
	}
	int ma=0;
	for(int j=0;j<m;j++)
	{
		vector<int> v(n);
		for(int i=0;i<n;i++)
		{
			v[i]=DP[i][j];
		}
		sort(v.begin(),v.end(),greater<int> ());
		for(int i=0;i<n;i++)
		{
			ma=max(ma,(i+1)*(v[i]));
		}
	}
	cout<<ma<<endl;
	return 0;
}
