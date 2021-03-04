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
		
		int a;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		sort(arr,arr+n);
		
		bool flag=0;
		
		for(int k=1;k<1024;k++)
		{
			set<int> s;
			bool fa=0;
			for(int i=0;i<n;i++)
			{
				s.insert(arr[i]^k);
			}
			
			if(s.size()==n)
			{
				int i=0;
				for(auto ele:s)
				{
					if(ele!=arr[i])
					{
						fa=1;
						break;
					}
					i++;
				}
			}
			if(!fa)
			{
				flag=1;
				cout<<k<<endl;
				break;
			}
		}
		if(!flag)
		{
			cout<<-1<<endl;
		}
	}
	return 0;
	
}
