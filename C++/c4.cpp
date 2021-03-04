#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long arr[30];
		arr[0]=1;
		for(int i=1;i<30;i++)
		{
			arr[i]=(1<<i);
		}
		int flag=0;
		int i=0;
		int ans[30];
		for(;i<30;i++)
		{
			ans[i]=arr[i];
			//cout<<ans[i]<<endl;
			n-=arr[i];
			if(n==0)
			{
				flag=1;
				break;	
			}
			else if(n<0)
			{
				flag=2;
				break;
			}
		}
		
		if(flag==1)
		{
			cout<<i<<endl;
			for(int j=1;j<=i;j++)
			{
				cout<<ans[j]-ans[j-1]<<' ';
			}
			cout<<endl;
		}
		else
		{
			cout<<i<<endl;
			if(-ans[i-1]+n+ans[i]>=0)
			{
				ans[i]=n+ans[i];
			}
			else
			{
				
				long long temp=ans[i-1]+n+ans[i];
				//cout<<temp<<endl;
				if(temp%2==0)
				{
					ans[i-1]=temp/2;
					ans[i]=temp/2;
				}
				else
				{
					ans[i-1]=temp/2;
					ans[i]=temp-temp/2;
				}
			}
			for(int j=1;j<=i;j++)
			{
				cout<<ans[j]-ans[j-1]<<' ';
			}
			cout<<endl;
			//cout<<n/2-(1<<i)<<' '<<0<<endl;
		}
	}
	return 0;
}
