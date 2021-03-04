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
		
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		vector<int> v;
		int sz=0;
		
		v.push_back(1);
		
		for(int i=1;i<n;i++)
		{
			if(arr[i]==arr[i-1])
			{
				v[sz]++;	
			}	
			else
			{
				v.push_back(1);
				sz++;
			}
		}
		
		int sum[sz+1];
		sum[0]=0;
		
		for(int i=1;i<=sz;i++)
		{
			sum[i]=v[i-1];
			sum[i]+=sum[i-1];
		}
		
		int ma=0;
		int g=0,s=0,b=0;
		
		int i=1;
		int j=2;
		int k=2;
		
		while(j<=sz && sum[j]-sum[i]<=sum[i])
		{
			j++;
		}
		
		if(j>sz)
		{
			cout<<0<<' '<<0<<' '<<0<<endl;
			continue;
		}
		
		while(k<=sz && sum[k]-sum[j]<=sum[i])
		{
			k++;
		}
		
		if(k>sz)
		{
			cout<<0<<' '<<0<<' '<<0<<endl;
			continue;
		}
		
		if(sum[k]-sum[j]<=sum[i])
		{
			cout<<0<<' '<<0<<' '<<0<<endl;
		}
		else if(sum[k]>n/2)
		{
			cout<<0<<' '<<0<<' '<<0<<endl;
		}
		else
		{
			while(k<=sz && sum[k]<=n/2)
			{
				k++;
			}
			
			k--;

			cout<<sum[i]<<' '<<sum[j]-sum[i]<<' '<<sum[k]-sum[j]<<endl;
		}
		
	}
	return 0;
}
