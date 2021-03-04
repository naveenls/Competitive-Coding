#include<bits/stdc++.h>
using namespace std;

const int maxN=2e5;

long long val[3*maxN+1]={0};

void Update(long long value,int pos,int ind,int start,int end)
{
	if(pos<start || pos>end)
		return;

	if(start==end)
	{
		val[ind]=max(val[ind],value);
	}
	else
	{
		int mid=(start+end)>>1;
		Update(value,pos,2*ind+1,start,mid);
		Update(value,pos,2*ind+2,mid+1,end);	
		val[ind]=max(val[2*ind+1] , val[2*ind+2]);
	}
}

long long get_max(int ind,int start,int end,int l,int r)
{
	if(start>r || end<l)
		return 0;

	if(start>=l && end<=r)
	{
		return val[ind];
	}
	else
	{
		int mid=(start+end)>>1;
		long long m1=get_max(2*ind+1,start,mid,l,r);
		long long m2=get_max(2*ind+2,mid+1,end,l,r);	
		return max(m1,m2);
	}
}


int main()
{
	int n;
	cin>>n;
	
	int a[n],b[n];
	long long h[n];
	
	set<int> s;
	
	vector<pair<pair<int,int>,int> > v(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>h[i];
		
		v[i]={{b[i],a[i]},i};
		s.insert(a[i]);
		s.insert(b[i]);	
	}
	
	map<int,int> mp;
	int st=0;
	
	for(auto e:s)
	{
		mp[e]=st++;
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	long long DP[n];
	
	long long ma=0;
	
	for(int i=0;i<n;i++)
	{
		int j=v[i].second;
		
		long long val=get_max(0,0,st-1,0,mp[b[j]]-1);
		DP[i]=val+h[j];
		
		//cout<<j<<' '<<val<<endl;	
		Update(DP[i],mp[a[j]],0,0,st-1);
		ma=max(ma,DP[i]);
	}
	
	cout<<ma<<endl;
	return 0;
}
