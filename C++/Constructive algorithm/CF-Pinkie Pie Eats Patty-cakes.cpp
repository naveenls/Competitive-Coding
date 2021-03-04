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
		
		int arr[n+1]={0};
		
		int a;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			arr[a]++;			
		}
		
		int ma=0;
		
		for(int i=1;i<=n;i++)
		{
			ma=max(ma,arr[i]);
		}
		
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(arr[i]==ma)
			{
				cnt++;
			}
		}
			
		cout<<(n-cnt+1-ma)/(ma-1)<<endl;
	}
	
	return 0;
}
