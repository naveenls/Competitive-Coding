#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<n-n/2;i++)
	{
		if(n%i==0)
		{
			//cout<<i<<endl;
			int temp[i]={0};
			for(int j=0;j<n;j++)
			{
				temp[j%i]+=arr[j];
			}
			//cout<<temp[0]<<endl;
			bool flag=0;
			for(int j=0;j<i;j++)
			{
				if(temp[j]==n/i)
				{
					flag=1;
					break;
				}
			}
			if(flag)
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}
