#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
vector<int> v;
vector<int> pre_sum;

int count_val(int i)
{
	int ind=lower_bound(v.begin(),v.end(),i)-v.begin();
	int n=v.size();
	
	if(ind==n)
	{
		return pre_sum[n-1];
	}
	else
	{
		int temp=0;
		if(ind)
			temp=pre_sum[ind-1];
			
		return temp + (n-ind)*i; 
	}
}
int main()
{
	int n;
	cin>>n;
	
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		mp[temp]++;
	}
	
	for(auto ele:mp)
	{
		v.push_back(ele.second);
	}
	sort(v.begin(),v.end());
	pre_sum.push_back(v[0]);
	
	for(int i=1;i<v.size();i++)
	{
		pre_sum.push_back(v[i]+pre_sum[i-1]);
	}
	int ma=0;
	pair<int,int> r_c;
	
	for(int i=1;i<=sqrt(n);i++)
	{
		int cnt=count_val(i);
		
		if(i*i<=cnt)
		{
			int temp=(cnt/i)*i;
			if(temp>ma)
			{
				ma=temp;
				r_c={i,cnt/i};
			}
		}
	}
	
	int ans[r_c.first][r_c.second];
	memset(ans,0,sizeof(ans));
	
	vector<pair<int,int> > v;
	for(auto ele:mp)
	{
		v.push_back({min(ele.second,r_c.first),ele.first});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	int x=0,y=0;
	temp=ma;
	
	for(int i=0;i<v.size();i++)
	{	
		while(v[i].first-- && temp--)
		{
			ans[x][y]=v[i].second;
			x++,y++;
			
			x%=r_c.first;
			y%=r_c.second;
			
			if(ans[x][y]!=0)
				x=(x+1)%r_c.first;
		}
	}
	
	cout<<ma<<endl;
	cout<<r_c.first<<' '<<r_c.second<<endl;
	
	for(int i=0;i<r_c.first;i++)
	{
		for(int j=0;j<r_c.second;j++)
			cout<<ans[i][j]<<' ';
		cout<<endl;
	}
	return 0;	
}
