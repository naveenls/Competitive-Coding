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
		
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]==k)
				flag=1;
				
		}
		if(!flag)
		{
			cout<<"no"<<endl;
			continue;
		}
		if(flag && n==1)
		{
			cout<<"yes"<<endl;
			continue;
		}
		flag=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]>=k)
			{
				if(i+1<n && arr[i+1]>=k)
				{
					flag=1;
					break;
				}
				else if(i+2<n && arr[i+2]>=k)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<"yes"<<endl;
		}
		else
			cout<<"no"<<endl;
	}
	return 0;
}
