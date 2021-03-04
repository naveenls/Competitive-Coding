#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		
		vector<pair<int,int> > dist;
		dist.push_back({arr[0],1});
		int sz=0;
		for(int i=1;i<n;i++)
		{
			if(arr[i]==arr[i-1])
			{
				dist[sz].second++;
			}
			else
			{
				sz++;
				dist.push_back({arr[i],1});
			}
		}
		
		int initial=1;
		for(auto ele:dist)
		{
			int temp=initial+ele.second-1;
			if(ele.first>=temp)
			{
				initial+=temp+1;
			}
			else
			{
				break;
			}
		}
		cout<<initial<<endl;
	}
	return 0;
}
