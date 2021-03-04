#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	int n=s.size();
	int arr[n];
	arr[0]=0;
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[i-1])
			arr[i]=1;
		else
			arr[i]=0;
			
		arr[i]+=arr[i-1];
	}

	int DP[n][4];
	memset(DP,0,sizeof(DP));
	if((n-1)%2==0)
	{
		if(arr[n-1]%2==0)
		{
			DP[n-1][0]=1;
		}
		else
		{
			DP[n-1][1]=1;
		}
	}
	else
	{
		if(arr[n-1]%2==0)
		{
			DP[n-1][2]=1;
		}
		else
		{
			DP[n-1][3]=1;
		}
	}
	
	for(int i=n-2;i>=0;i--)
	{
		if((i)%2==0)
		{
			if(arr[i]%2==0)
			{
				DP[i][0]=1;
			}
			else
			{
				DP[i][1]=1;
			}
		}
		else
		{
			if(arr[i]%2==0)
			{
				DP[i][2]=1;
			}
			else
			{
				DP[i][3]=1;
			}
		}
		for(int j=0;j<4;j++)
		{
			DP[i][j]+=DP[i+1][j];
		}
	}
	long long odd=0;
	long long even=0;
	
	for(int i=0;i<n;i++)
	{
		if((i)%2==0)
		{
			if(arr[i]%2==0)
			{
				odd+=DP[i][0];
				even+=DP[i][2];
			}
			else
			{
				odd+=DP[i][1];
				even+=DP[i][3];
			}
		}
		else
		{
			if(arr[i]%2==0)
			{
				even+=DP[i][0];
				odd+=DP[i][2];
			}
			else
			{
				even+=DP[i][1];
				odd+=DP[i][3];
			}
		}
	}
	cout<<even<<' '<<odd<<endl;
	return 0;
}
