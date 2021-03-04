#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,v;
	cin>>n>>v;
	int arr[3003]={0};
	int post_pone[3003]={0};
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		arr[a]+=b;
	}
	
	int ans=0;
	for(int i=1;i<3002;i++)
	{
		int temp=v;
		if(temp>post_pone[i])
		{
			ans+=post_pone[i];
			temp-=post_pone[i];
		}
		else
		{
			ans+=temp;
			temp=0;
		}
		
		if(arr[i]<temp)
		{
			ans+=arr[i];			
		}
		else
		{
			
			ans+=temp;
			post_pone[i+1]=arr[i]-temp;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
