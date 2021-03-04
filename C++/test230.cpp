#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	int inv[n+1];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		inv[arr[i]]=i;
	}
	
	stack<int> s;
	
	int rg[n];
	memset(rg,-1,sizeof(rg));
	
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && arr[s.top()]<arr[i])
		{
			rg[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	
	while(!s.empty())
		s.pop();
	
	int lg[n];
	memset(lg,-1,sizeof(lg));
	
	for(int i=n-1;i>=0;i--)
	{
		while(!s.empty() && arr[s.top()]<arr[i])
		{
			lg[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	for(int i=0;i<n;i++)
	{
		//cout<<lg[i]<<' '<<rg[i]<<endl;
	}
	int ans=0;
	for(int i=1;i<n-1;i++)
	{
		int left=lg[i];
		left++;
					
		int right=rg[i];
		if(right==-1)
			right=n;
		right--;
		
		if(right-i==0 || i-left==0)
		{
			continue;
		}
		
		//cout<<i<<' '<<left<<' '<<right<<endl;
		int lenr=right-i;
		int lenl=i-left;
		
		if(right-i<i-left)
		{
			for(int j=i+1;j<=right;j++)
			{
				int temp=arr[i]-arr[j];
				
				if(temp>=1 && temp<=n && inv[temp]>=left && inv[temp]<i)
				{
					ans++;
				}
			}
		}
		else
		{
			for(int j=i-1;j>=left;j--)
			{
				int temp=arr[i]-arr[j];
				
				if(temp>=1 && temp<=n && inv[temp]>i && inv[temp]<=right)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
