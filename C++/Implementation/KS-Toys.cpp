#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	
	long long e[n],r[n];
	
	priority_queue<pair<long long,int> > pq;
	
	long long t_sum=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>e[i]>>r[i];
		t_sum+=e[i];		
	}
	
	long long ma=t_sum;
	int rem=0;
	
	int curr_rem=0;
	long long curr_sum=t_sum;
	
	for(int i=0;i<n;i++)
	{
		pq.push({e[i]+r[i],i});
		curr_sum+=e[i];
		
		while(pq.size() && pq.top().first > t_sum)
		{
			t_sum-=e[pq.top().second];
			curr_sum-=2*e[pq.top().second];
			
			pq.pop();
			
			curr_rem++;
		}
		
		if(curr_sum>ma)
		{
			ma=curr_sum;
			rem=curr_rem;
		}
	}
	
	if(pq.size())
	{
		cout<<curr_rem<<' '<<"INDEFINITELY"<<endl;
	}
	else
	{
		cout<<rem<<' '<<ma<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
