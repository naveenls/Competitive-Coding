#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		
		cin>>n>>k;
		
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		sort(arr,arr+n,greater<int> ());
	
		vector<pair<int,int> > count(k);
		
		for(int i=0;i<k;i++)
		{
			cin>>count[i].first;
			if(count[i].first==1)
			{
				count[i].first=n+1;
			}
			count[i].second=i;
		}
		
		sort(count.begin(),count.end());
		reverse(count.begin(),count.end());
		
		vector<vector<int> > v(k);
		
		for(int i=0;i<k;i++)
		{			
			v[i].push_back(arr[i]);
			
			if(count[i].first==n+1)
				count[i].first=1;
		}
		
		int j=0;
		for(int i=n-1;i>=0;i--)
		{
			if(j==k)
				break;
				
			if(v[j].size()<count[j].first)
			{
				v[j].push_back(arr[i]);
			}
			else
			{
				j++;
				i++;
			}
		}
		
		long long sum=0;
		for(int i=0;i<k;i++)
		{
			sort(v[i].begin(),v[i].end());
			sum+=(v[i][0]+v[i][count[i].first-1]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
