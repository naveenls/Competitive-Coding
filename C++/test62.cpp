#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n+1]={0};
	int p[n][32]={0};
	int t;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		int temp=t;
		int ind=0;
		while(temp)
		{
			p[i][ind]=temp%2;
			temp/=2;
			ind++;
		}
	}
		
	for(int i=n;i>=1;i--)
	{
		int temp=n/i;
		int temp1=n%i;
		
		arr[0]+=temp;
		arr[i]-=temp;
		
		arr[1]+=1;
		arr[temp1+1]-=1;
	}
	for(int i=1;i<n;i++)
	{
		arr[i]+=arr[i-1];
	}
	
	int bits[n][32]={0};
	for(int i=0;i<n;i++)
	{
		int temp=i;
		int ind=0;
		while(temp)
		{
			bits[i][ind]=temp%2;
			temp/=2;
			ind++;
		}
	}
	int ans[32];
	for(int i=0;i<32;i++)
	{
		long long sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=(long long)bits[j][i]*arr[j];
			//cout<<bits[j][i]<<' '<<arr[j]<<endl;
		}
		sum%=2;
		//cout<<i<<' '<<sum<<endl;
		ans[i]=sum;
	}
	long long answer=0;
	for(int i=0;i<32;i++)
	{
		long long sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=(long long)p[j][i];
		}
		sum+=ans[i];
		sum%=2;
		if(sum)
		{
			answer+=(1<<i);
		}
	}
	cout<<answer<<endl;
	return 0;
}
