#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	double d;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		cin>>d;
	}
	int ma=1;
	int DP[n];
	DP[0]=1;
	for(int i=1;i<n;i++)
	{
		DP[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[i]>=arr[j])
				DP[i]=max(DP[i],DP[j]+1);
		}

		ma=max(ma,DP[i]);
	}
	cout<<n-ma<<endl;
	return 0;
}
