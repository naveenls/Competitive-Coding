#include<bits/stdc++.h>
using namespace std;
int n,h;

int find_diff(vector<pair<int,int> >  &arr,int mark)
{
	if(mark==2)
	{
		return abs(arr[0].first+arr[1].first-arr[n-1].first-arr[n-2].first);
	}
	else
	{
		int min_val=min(arr[0].first+arr[1].first+h,arr[1].first+arr[2].first);
		int max_val=max(arr[0].first+arr[n-1].first+h,arr[n-1].first+arr[n-2].first);
		
		return abs(max_val-min_val);
	}
}
int main()
{
	cin>>n>>h;
	
	if(n==2)
	{
		cout<<0<<endl<<2<<' '<<2<<endl;;
		return 0;
	}
	vector<pair<int,int> > arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].first;
		arr[i].second=i;
	}
	
	sort(arr.begin(),arr.end());
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i].first<<' '<<arr[i].second<<endl;
	}
	bool mark[n]={0};
	
	for(int i=0;i<n;i++)
	{
		mark[i]=2;
	}
	
	int diff1=find_diff(arr,1);
	int diff2=find_diff(arr,2);
	
	if(diff1<diff2)
	{
		mark[0]=1;
	}
	else
	{
		mark[0]=2;
	}
	
	int ans[n];
	for(int i=0;i<n;i++)
		ans[arr[i].second]=mark[i];
	return 0;
}
