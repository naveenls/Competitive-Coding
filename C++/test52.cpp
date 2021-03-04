#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int num_pairs=n/2;
	
	if(n==1 && k!=0)
	{
		cout<<-1<<endl;
		return 0;		
	}
	if(n==1 && k==0)
	{
		cout<<1<<endl;
		return 0;
	}
	if(k<num_pairs)
	{
		cout<<-1<<endl;
	}
	else
	{
		int ans[n];
		for(int i=0;i<n;i++)
		{
			ans[i]=i+1;
		}
		k-=num_pairs;
		int temp=n-1;
		if(n%2)
		{
			temp--;
		}
		while(k)
		{
			int x=ans[temp];
			x=(1e9)/x;
			k++;
			x=min(x,k);
			
			ans[temp]*=x;
			ans[temp-1]*=x;
			temp-=2;
			k-=x;
		}
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
