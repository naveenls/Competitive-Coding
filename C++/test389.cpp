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
		long long x;
		cin>>x;
		
		long long arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		sort(arr,arr+n);
		
		int ind=lower_bound(arr,arr+n,x)-arr;
		
		if(ind==n)
		{
			cout<<n<<endl;
		}
		else
		{
			int cnt=0;
			
			long long prev=x;
			
			for(int j=ind;j<n;j++)
			{
				if(arr[j]<=prev)
				{
					cnt++;
					prev=2*arr[j];
				}
				else
				{
					while(prev<arr[j])
					{
						prev*=2;
						cnt++;
					}
					cnt++;
					prev=2*arr[j];
				}
			}
			cnt+=ind;
			
			cout<<cnt<<endl;
		}
	}
	return 0;
}
