#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
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
		
		int mi=1e9+1;
		
		bool f1=0;
		
		for(int i=0;i<n;i++)
		{
			if(arr[i]>0)
				mi=min(arr[i],mi);
			
			if(arr[i]<=0)
				f1=1;
		}
		
		if(mi==1e9+1)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			
			if(!f1)
			{
				sort(arr,arr+n);
				
				for(int i=0;i<n;i+=2)
				{
					if(i+1<n)
						swap(arr[i],arr[i+1]);
				}
				
				for(int i=0;i<n;i++)
					cout<<arr[i]<<' ';
					
				cout<<endl;
				continue;
			}
			
			vector<int> vals;
			
			for(int i=0;i<n;i++)
			{
				if(arr[i]!=mi)
				{
					vals.push_back(arr[i]);
				}
			}
			sort(vals.begin(),vals.end());
			
			for(int i=1;i<vals.size();i+=2)
			{
				if(i+1<vals.size())
					swap(vals[i],vals[i+1]);
			}
			cout<<mi<<' ';
			for(auto ele:vals)
				cout<<ele<<' ';
			cout<<endl;
		}
		
	}
	return 0;
}
