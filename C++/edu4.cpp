#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n,m;
	cin>>n>>m;
	
	int k;
	long long x, y;
	cin>>x>>k>>y;
	
	int pos[n];
	int arr[n];
	bool flag[n]={0};
	
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		a--;
		arr[i]=a;
		
		pos[a]=i;
	}
	
	int prev=-1;
	
	for(int i=0;i<m;i++)
	{
		cin>>a;
		a--;
		
		if(pos[a]<prev)
		{
			cout<<-1<<endl;
			return 0;
		}
		
		prev=pos[a];
		
		flag[pos[a]]=1;
	}
	
	
	vector<pair<int,int> > v;
	
	bool ff=0;
	
	int s,e;
	
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			if(ff==0)
			{
				s=i;
				ff=1;	
			}
		}
		else
		{
			if(ff==1)
			{
				e=i-1;
				ff=0;
				
				v.push_back({s,e});
			}
		}
	}
	
	if(ff)
	{
		v.push_back({s,n-1});
	}
	
	vector<pair<int,int> > v_new;
	
	for(auto ele:v)
	{
		//cout<<ele.first<<' '<<ele.second<<endl;
		int ma=0;
		
		for(int i=ele.first;i<=ele.second;i++)
		{
			ma=max(ma,arr[i]);
		}
		
		int ma1=0;
		
		if(ele.first)
		{
			ma1=max(ma1,arr[ele.first-1]);
		}
		if(ele.second<n-1)
		{
			ma1=max(ma1,arr[ele.second+1]);
		}
		
		v_new.push_back({ele.second-ele.first+1,ma1>ma? 1 : 0});
	}
	
	long long ans=0;
	
	for(auto ele:v_new)
	{
	//	cout<<ele.first<<' '<<ele.second<<endl;
		if(ele.first<k)
		{
			if(ele.second)
			{
				ans+=y*ele.first;
			}
			else
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		else
		{
			int rem=ele.first%k;

			if(x<=k*y)
			{
				ans+=rem*y;
				ans+=(ele.first/k)*x;
			}
			else
			{
				if(ele.second)
				{
					ans+=(ele.first)*y;	
				}
				else
				{
					ans+=(ele.first-k)*y;
					ans+=x;
				}
			}
		}
	//	cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
