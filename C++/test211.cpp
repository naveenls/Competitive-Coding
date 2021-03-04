#include<bits/stdc++.h>
using namespace std;

const int maxN=1e7+1;
int main()
{
	int n;
	cin>>n;
	
	int arr[maxN]={0};
	
	int a[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		arr[a[i]]++;		
	}
	
	long long mi=1e18;
	
	pair<int,int> ans;
	
	for(int i=1e7;i>=1;i--)
	{
		int j=i;
		
		multiset<int> mset;
		while(j<maxN)
		{
			if(arr[j]>1)
			{
				mset.insert(j);
				mset.insert(j);
			}
			else if(arr[j]==1)
			{
				mset.insert(j);
			}
			j+=i;
		}
		
		if(mset.size()>1)
		{
			long long val1=*mset.begin();
			mset.erase(mset.begin());
			
			long long val2=*mset.begin();
			
			long long value=val1*val2/(long long)i;
			if(mi>value)
			{
				mi=value;
				ans={val1,val2};
			}
		}
	}
	int ind1,ind2;
	
	for(int i=0;i<n;i++)
	{
		if(ans.first==arr[i])
		{
			ind1=i;
			break;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(ans.second==arr[i] && i!=ind1 )
		{
			ind2=i;
			break;
		}
	}
	cout<<min(ind1,ind2)+1<<' '<<max(ind1,ind2)+1<<endl;
	return 0;
}
