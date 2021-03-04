#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+1;
map<int,int> mp;

bool check()
{
	//cout<<mp.size()<<endl;
	if(mp.size()>2)
		return false;
	
	if(mp.size()==1)
	{
		int cnt=(*mp.begin()).second;
		if(cnt==1)
			return true;
		
		else if((*mp.begin()).first==1)
			return true;
		
		else
			return false;
		
	}		
	
	int low=(*mp.begin()).first;
	int high=(*mp.rbegin()).first;
	
	int cnt1=mp[high];
	int cnt2=mp[low];
	
	if(high> low && low==1 && cnt2==1 )
	{
		return true;
	}
	
	if(high == low+1 && cnt1==1)
	{
		return true;
	}
	
	return false;
}
int main()
{
	int n;
	cin>>n;
	
	int freq[maxN]={0};
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];	
	}
	
	int mX=0;
	
	for(int i=0;i<n;i++)
	{
		
		if(mp.find(freq[arr[i]])!=mp.end())
		{
			mp[freq[arr[i]]]--;
			
			if(mp[freq[arr[i]]]==0)
			{
				mp.erase(freq[arr[i]]);
			}
		}
		freq[arr[i]]++;
		
		mp[freq[arr[i]]]++;
		
		if(check())
			mX=i+1;	
	}
	cout<<mX<<endl;
	return 0;
}
