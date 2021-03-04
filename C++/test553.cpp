#include<bits/stdc++.h>
using namespace std;

int k=0;
int cnt_top=0;

multiset<pair<long long,int> > top;
multiset<pair<long long,int> > rem;

multiset<long long> ligh;
multiset<long long> fire;

long long total_sum=0;
long long top_sum=0;

void ins(int t,long long d)
{
	if(t==0)
	{
		fire.insert(d);
		
		top.insert({d,0});
		top_sum+=d;
		
		if(top.size()>k)
		{
			auto val=*top.begin();
			top_sum-=val.first;
			
			rem.insert(val);
			top.erase(top.begin());

			cnt_top-=val.second;
		}
	}
	else
	{
		ligh.insert(d);
		
		k++;
		if(rem.size())
		{
			auto val=*rem.rbegin();
			top.insert(val);
			cnt_top+=val.second;
			
			top_sum+=val.first;
			
			rem.erase(rem.find(val));
		}
		
		top.insert({d,1});
		top_sum+=d;
		cnt_top++;
		
		if(top.size()>k)
		{
			auto val=*top.begin();
			top_sum-=val.first;
			
			rem.insert(val);
			top.erase(top.begin());

			cnt_top-=val.second;
		}
	}
}

void del(int t,int d)
{
	if(t==0)
	{
		fire.erase(fire.find(d));
		
		if(rem.find({d,0})!=rem.end())
		{
			rem.erase(rem.find({d,0}));
		}
		else
		{
			top.erase(top.find({d,0}));
			top_sum-=d;
			
			if(rem.size())
			{
				auto val=*rem.rbegin();
				top_sum+=val.first;
				cnt_top+=val.second;
				
				top.insert(val);
				rem.erase(rem.find(val));
			}
		}
	}
	else
	{
		ligh.erase(ligh.find(d));
		
		k--;
		
		if(rem.find({d,1})!=rem.end())
		{
			rem.erase(rem.find({d,1}));
			
			if(top.size()>k)
			{
				auto val=*top.begin();
				top_sum-=val.first;
				
				rem.insert(val);
				top.erase(top.begin());
	
				cnt_top-=val.second;
			}
		}
		else
		{
			top.erase(top.find({d,1}));
			top_sum-=d;
			cnt_top--;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	int t;
	long long d;
	
	for(int i=0;i<n;i++)
	{
		cin>>t>>d;
		
		total_sum+=d;
		
		if(d>0)
		{
			ins(t,d);
		}
		else
		{
			del(t,-d);
		}
		
		//cout<<total_sum<<' '<<top_sum<<' '<<k<<' '<<cnt_top<<endl;
		if(cnt_top==k && cnt_top!=0)
		{
			long long sum=total_sum+top_sum;
			
			if(fire.size())
			{
				sum+=(*fire.rbegin());
			}
			sum-=(*top.begin()).first;
		
			cout<<sum<<endl;
		}
		else
			cout<<total_sum+top_sum<<endl;
	}
}
