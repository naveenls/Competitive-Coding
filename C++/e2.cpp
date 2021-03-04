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
		int arr[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		sort(arr+1,arr+n+1);
		int DP[n+1];
		DP[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(i>=arr[i])
			{
				DP[i]=max(DP[i-1],1+DP[i-arr[i]]);
			}
			else
			{
				//cout<<i<<' '<<arr[i]<<endl;
				DP[i]=DP[i-1];
			}
		}
		cout<<DP[n]<<endl;
	}
	return 0;
}
