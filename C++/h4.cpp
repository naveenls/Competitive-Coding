#include<bits/stdc++.h>
using namespace std;

int main()
{
		long long n,x;
		cin>>n>>x;
		long long arr[2*n+1];
		arr[0]=0;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
			
		}
		for(int i=n+1;i<2*n+1;i++)
		{
			arr[i]=arr[i-n];
		}
		
		long long prefix[2*n+1]={0};
		for(int i=1;i<=n;i++)
		{
			prefix[i]=arr[i]*(arr[i]+1)/2;
			prefix[i+n]=prefix[i];
		}
		for(int i=1;i<2*n+1;i++)
			prefix[i]+=prefix[i-1];
			
		int start=0;
		long long initial=sum;
		long long ma=0;
		for(int i=n+1;i<2*n+1;i++)
		{
			initial+=arr[i];
			
			while(initial>x)
			{
				initial-=arr[start];
				start++;
			}
			long long extra=x-initial;
			long long possib=prefix[i]-prefix[start-1];
			
			if(extra)
			{
				long long temp=arr[start-1];
				long long temp1=temp-extra;
				possib+=(temp*(temp+1)/2 -temp1*(temp1+1)/2);
			}
			ma=max(possib,ma);
			
		}
		cout<<ma<<endl;
		
	
	return 0;
}
