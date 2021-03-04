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
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];	
		}
	
		int arr[n]={0};
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			long long temp;
			long long temp1=(long long)i+a[i];
			if(temp1<0)
				temp=n-abs(temp1)%n;
			else
				temp=temp1%n;
				
			arr[temp]++;
			if(arr[temp]>=2)
			{
				flag=1;
				break;
			}
		}
		for(int i=0;i<n;i++)
			cout<<arr[i]<<' ';
		cout<<endl;
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
