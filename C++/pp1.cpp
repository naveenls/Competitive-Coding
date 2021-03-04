#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		
		int arr[n];
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		
		if(sum%x)
		{
			cout<<n<<endl;
			continue;
		}
		
		bool flag[n];
		for(int i=0;i<n;i++)
		{
			if(arr[i]%x==0)
			{
				flag[i]=1;
			}
			else
			{
				flag[i]=0;
			}
		}
		
		int c1=-1;
		for(int i=0;i<n;i++)
		{
			if(!flag[i])
			{
				c1=i;
				break;
			}
		}
		
		int c2=-1;
		for(int i=n-1;i>=0;i--)
		{
			if(!flag[i])
			{
				c2=i;
				break;
			}
		}
		
		if(c1==-1)
		{
			cout<<-1<<endl;
		}
		else
		{
			int mi=min(c1+1,n-c2);
			cout<<n-mi<<endl;
		}
	}
	return 0;
}
