#include<bits/stdc++.h>
using namespace std;

const int maxN=2*1e5+10;

long long val[3*maxN+1];
long long val1[3*maxN+1];

void Update(long long new_val,int pos,int ind,int start,int end,int f)
{
	if(pos<start || pos>end)
		return;

	if(start==end)
	{
		if(f==0)
		{
			val[ind]=max(val[ind],new_val);
		}
		else
		{
			val1[ind]=max(val1[ind],new_val);
		}
	}
	else
	{
		int mid=(start+end)>>1;
		Update(new_val,pos,2*ind+1,start,mid,f);
		Update(new_val,pos,2*ind+2,mid+1,end,f);	
		
		if(f==0)
		{
			val[ind]=max(val[2*ind+1] , val[2*ind+2]);
		}
		else
		{
			val1[ind]=max(val1[2*ind+1],val1[2*ind+2]);
		}		
	}
}

long long get_sum(int ind,int start,int end,int l,int r,int f)
{
	if(start>r || end<l)
		return -1e18;

	if(start>=l && end<=r)
	{
		if(f==0)
		{
			return val[ind];
		}
		else
		{
			return val1[ind];
		}
	}
	else
	{
		int mid=(start+end)>>1;
		long long v1=get_sum(2*ind+1,start,mid,l,r,f);
		long long v2=get_sum(2*ind+2,mid+1,end,l,r,f);	
	
		return max(v1, v2);
	}
}

void set_min()
{
	for(int i=0;i<=3*maxN;i++)
	{
		val[i]=val1[i]=-1e18;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	int c;
	cin>>c;
	
	long long x[c],y[c];
	
	set<long long> s;
	
	vector<pair<long long,pair<int,int> > > v;
	
	for(int i=0;i<c;i++)
	{
		cin>>x[i]>>y[i];
		s.insert(y[i]);
		
		v.push_back({x[i],{2,i}});
	}
	
	int h;
	cin>>h;
	
	long long x1[h],y1[h];
	
	for(int i=0;i<h;i++)
	{
		cin>>x1[i]>>y1[i];
		s.insert(y1[i]);
		
		v.push_back({x1[i],{1,i}});
	}
	
	sort(v.begin(),v.end());
	
	map<long long,int> mp;
	
	int cnt=0;
	for(auto ele:s)
	{
		mp[ele]=cnt;
		cnt++;
	}
	
	set_min();
	
	long long ma_val[h]={0};
	
	for(int i=0;i<v.size();i++)
	{
		int type=v[i].second.first;		
		int ind=v[i].second.second;
		
		if(type==1)
		{
			long long a1=get_sum(0,0,cnt,0,mp[y1[ind]],1);
			long long a2=get_sum(0,0,cnt,mp[y1[ind]],cnt,0);	
			
			long long ma=max(x1[ind]+y1[ind]+a1,x1[ind]-y1[ind] + a2);
			
			ma_val[ind]=max(ma_val[ind],ma);
		}
		else
		{
			Update(-x[ind]+y[ind],mp[y[ind]],0,0,cnt,0);
			Update(-x[ind]-y[ind],mp[y[ind]],0,0,cnt,1);
		}	
	}
	
	set_min();
	
	for(int i=v.size()-1;i>=0;i--)
	{
		int type=v[i].second.first;		
		int ind=v[i].second.second;
		
		if(type==1)
		{
			long long a1=get_sum(0,0,cnt,0,mp[y1[ind]],1);
			long long a2=get_sum(0,0,cnt,mp[y1[ind]],cnt,0);
			
			long long ma=max(-x1[ind]+y1[ind]+a1,-x1[ind]-y1[ind] + a2);
			
			ma_val[ind]=max(ma_val[ind],ma);			
		}
		else
		{
			Update(x[ind]+y[ind],mp[y[ind]],0,0,cnt,0);
			Update(x[ind]-y[ind],mp[y[ind]],0,0,cnt,1);			
		}	
	}
	
	long long mi=1e18;
	int ind;
	
	for(int i=0;i<h;i++)
	{
		if(mi>ma_val[i])
		{
			mi=ma_val[i];
			ind=i;
		}
	}
	cout<<mi<<endl;
	cout<<ind+1<<endl;
	
	return 0;
}
