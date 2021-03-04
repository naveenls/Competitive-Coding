#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int l=0,r=n-1;
	
	int cnt=0;
	
	int last_val=-1;
	string ans="";
	
	bool flag=0;
	
	while(l<=r)
	{
	//	cout<<last_val<<' '<<l<<' '<<r<<endl;
		if(arr[l]>arr[r])
		{
			if(arr[r]>last_val)
			{
				cnt++;
				
				last_val=arr[r];
				r--;
				ans.push_back('R');
			}
			else if(arr[l]>last_val)
			{
				cnt++;
				
				last_val=arr[l];
				l++;
				ans.push_back('L');
			}
			else
			{
				break;
			}
		}
		else if(arr[l]<arr[r])
		{
			if(arr[l]>last_val)
			{
				cnt++;
				
				last_val=arr[l];
				l++;
				ans.push_back('L');	
			}
			else if(arr[r]>last_val)
			{
				cnt++;
				
				last_val=arr[r];
				r--;
				ans.push_back('R');
			}
			else
			{
				break;
			}
		}
		else if(arr[l]>last_val)
		{
			flag=1;
			break;
		}
		else
		{
			break;
		}
	}
	
	if(flag)
	{
		int cnt1=1;
		
		for(int i=l+1;i<=r;i++)
		{
			if(arr[i]>arr[i-1])
			{
				cnt1++;
			}
			else
			{
				break;
			}
		}
		int cnt2=1;
		
		for(int i=r-1;i>=l;i--)
		{
			if(arr[i]>arr[i+1])
			{
				cnt2++;
			}
			else
			{
				break;
			}
		}
		if(cnt2>cnt1)
		{
			cnt+=cnt2;
			while(cnt2--)
			{
				ans.push_back('R');
			}
		}
		else
		{
			cnt+=cnt1;
			while(cnt1--)
			{
				ans.push_back('L');
			}
		}
		cout<<cnt<<endl;
		cout<<ans<<endl;
	}
	else
	{
		cout<<cnt<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
