#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	
	int arr[n];
	int seg[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int ind=0;
	
	map<int,pair<int,int> > mp1;
	
	for(int i=0;i<n;)
	{
		int j=i;
		
		while(j<n && (j-i)<=sqrt(n))
		{
			seg[j]=ind;
			j++;
		}
		
		mp1[ind]={i,j-1};
		
		ind++;
		i=j;
	}
	
	map<int,int> mp[ind];
	int start[ind]={0};
	
	int pref[n];
	pref[0]=arr[0];
	
	mp[0][arr[0]]++;
	
	for(int i=1;i<n;i++)
	{
		pref[i]=pref[i-1]^arr[i];
		mp[seg[i]][pref[i]]++;
	}
	
	int type,in,x;
	for(int i=0;i<q;i++)
	{
		cin>>type>>in>>x;
		
		if(type==1)
		{
			in--;
			
			for(int j=in;j<=mp1[seg[in]].second;j++)
			{
				mp[seg[j]][pref[j]]--;
				
				if(mp[seg[j]][pref[j]]==0)
				{
					mp[seg[j]].erase(pref[j]);
				}
				
				pref[j]^=(arr[in]^x);
			}
			
			for(int j=seg[in]+1;j<ind;j++)
			{
				start[j]^=(arr[in]^x);
			}
			arr[in]=x;
		}
		else
		{
			in--;
			
			int cnt=0;
			
			for(int j=in;j>=mp1[seg[in]].first;j--)
			{
				if((pref[j]^start[seg[j]])==x)
				{
					cnt++;	
				}
			}
			
			for(int j=seg[in]-1;j>=0;j--)
			{
				cnt+=mp[j][x^start[j]];
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
