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
		
		bool flag[n]={0};
		flag[0]=1;
		flag[n-1]=1;
		
		for(int i=1;i<n-1;i++)
		{
			if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
			{
				flag[i]=1;
			}
			if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
			{
				flag[i]=1;
			}
		}
		
		vector<int> ans;
		for(int i=0;i<n;i++)
		{
			if(flag[i])
			{
				ans.push_back(arr[i]);
			}
		}
		cout<<ans.size()<<endl;
		for(auto ele:ans)
		{
			cout<<ele<<' ';
		}
		cout<<endl;
	}
	return 0;
}
