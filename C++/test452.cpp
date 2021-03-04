#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5;

int val[3*maxN+1]={0};

void Update(int new_val,int pos,int ind,int start,int end)
{
	if(pos<start || pos>end)
		return;

	if(start==end)
	{
		val[ind]=new_val;
	}
	else
	{
		int mid=(start+end)>>1;
		Update(new_val,pos,2*ind+1,start,mid);
		Update(new_val,pos,2*ind+2,mid+1,end);	
		val[ind]=max(val[2*ind+1] , val[2*ind+2]);
	}
}

int get_sum(int ind,int start,int end,int l,int r)
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
		int ma1=get_sum(2*ind+1,start,mid,l,r);
		int ma2=get_sum(2*ind+2,mid+1,end,l,r);	
		return max(ma1,ma2);
	}
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	vector<set<pair<int,int> > > v(n+1);
	
	int temp[maxN+1]={0};
	int DP[n];
	int DP_inv[n];
	
	int lis=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1)
		{
			DP[i]=1;
			
			if(!temp[arr[i]])
			{
				temp[arr[i]]=1;
				Update(1,1,0,1,maxN);
			}
		}
		else
		{
			int ma=get_sum(0,1,maxN,1,arr[i]-1);
			
			DP[i]=ma+1;
			
			if(DP[i]>temp[arr[i]])
			{
				Update(DP[i],arr[i],0,1,maxN);
				temp[arr[i]]=DP[i];
			}
		}
		
		lis=max(lis,DP[i]);
	}

	memset(val,0,sizeof(val));
	memset(temp,0,sizeof(temp));
	
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]==maxN)
		{
			DP_inv[i]=1;
			
			if(!temp[arr[i]])
			{
				temp[arr[i]]=1;
				Update(1,arr[i],0,1,maxN);
			}
		}
		else
		{
			int ma=get_sum(0,1,maxN,arr[i]+1,maxN);
			
			DP_inv[i]=ma+1;
			
			if(DP_inv[i]>temp[arr[i]])
			{
				Update(DP_inv[i],arr[i],0,1,maxN);
				temp[arr[i]]=DP_inv[i];
			}
		}		
	}

	int ans[n];
	map<int,int> mp;
	
	for(int i=0;i<n;i++)
	{
		if(DP[i]+DP_inv[i]-1==lis)
		{
			mp[lis-DP[i]]++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(DP[i]+DP_inv[i]-1==lis)
		{
			if(mp[lis-DP[i]]==1)
			{
				ans[i]=3;
			}
			else
			{
				ans[i]=2;
			}
		}
		else
		{
			ans[i]=1;
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
