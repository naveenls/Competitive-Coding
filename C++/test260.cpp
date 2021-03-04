#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n+1];
	
	arr[n]=-1;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	map<pair<int,int>,int> mp;
	map<int,pair<int,int> > ind;
	
	int DP[n]={0};
	DP[0]=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]==arr[i-1])
		{
			DP[i]=DP[i-1]+1;
		}
		else
		{
			DP[i]=1;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=arr[i+1])
		{
			mp[{-DP[i],i}]=arr[i];
			ind[i]={arr[i],DP[i]};
		}
	}
	int cnt=0;
	
	while(mp.size())
	{
		cnt++;
		
		auto itr=mp.begin();
		
		int index=(*itr).first.second;
		int value=(*itr).second;
		
		auto it=ind.find(index);
		
		if(it==ind.begin() || it==(--ind.end()))
		{
			mp.erase(itr);
			ind.erase(index);	
		}
		else
		{
			--it;
			int ind1=(*it).first;
			int val1=(*it).second.first;
			int len1=(*it).second.second;
			
			++it,++it;
			
			int ind2=(*it).first;
			int val2=(*it).second.first;
			int len2=(*it).second.second;
			
			if(val2==val1)
			{
				mp.erase(itr);
				mp.erase(mp.find({-len1,ind1}));
				mp.erase(mp.find({-len2,ind2}));
				
				ind.erase(index);
				ind.erase(ind1);
				ind.erase(ind2);
				
				mp[{-(len1+len2),ind1}]=val1;
				ind[ind1]={val1,len1+len2};
			}
			else
			{
				mp.erase(itr);
				ind.erase(index);
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
