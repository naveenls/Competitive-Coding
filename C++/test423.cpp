#include<bits/stdc++.h>
using namespace std;

int find_max(long long sum,int t_a,int t_b,long long a,long long b)
{
	int cnt=sum/a;
	cnt=min(t_a,cnt);
	
	t_a-=cnt;
	sum-=cnt*a;
	
	return cnt+min(sum/b,(long long)t_b);
}
int main()
{
	int m;
	cin>>m;
	while(m--)
	{
		int n;
		long long T,a,b;
		
		cin>>n>>T>>a>>b;
		
		int t_a=0,t_b=0;
		
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i])
				t_b++;
			else
				t_a++;	
		}

		map<long long,long long> mp;
		map<long long,long long> cnta,cntb;
		
		long long t;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			if(arr[i])
				mp[t]+=b,cntb[t]++;
			else
				mp[t]+=a,cnta[t]++;
		}
		
		int size=mp.size();
		
		vector<pair<long long,long long> > v(size);

		int start=0;
		for(auto ele:mp)
		{
			v[start]={ele.first,ele.second};
			start++;
		}
		
		int ma=0;
		int num_ele=0;
		
		long long sum=0;
		
		for(int i=0;i<size;i++)
		{
			long long tt=v[i].first-1;
						
			if(tt>=sum)
			{
				int ans=num_ele;
				ans+=find_max(tt-sum,t_a,t_b,a,b);
				
				ma=max(ma,ans);
			}
			num_ele+=cnta[v[i].first]+cntb[v[i].first];
			t_a-=cnta[v[i].first];
			t_b-=cntb[v[i].first];
			sum+=v[i].second;
		}
		
		if(T>=sum)
		{
			ma=n;
		}
		
		cout<<ma<<endl;
	}
	return 0;
}
