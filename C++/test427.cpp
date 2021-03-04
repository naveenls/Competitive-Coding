#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n+2]={0};
	
	int a;
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr[a]++;
	}
	
	if(n==1)
	{
		cout<<1<<' '<<1<<endl;
		return 0;
	}
	else if(n==2)
	{
		cout<<1<<' '<<2<<endl;
		return 0;
	}
	else if(n<=3)
	{
		int ma;
		if(arr[3]==3)
		{
			ma=2;
		}
		else
		{
			ma=3;
		}
		cout<<1<<' '<<ma<<endl;
		return 0;
	}
	
	int DP[n+2];
	
	DP[0]=0;
	if(arr[1])
	{
		DP[1]=1;
	}
	else
	{
		DP[1]=0;
	}
	
	if(arr[2] || arr[1])
	{
		DP[2]=1;
	}
	else
	{
		DP[2]=0;
	}
	
	int mi;
	
	for(int i=3;i<=n+1;i++)
	{
		DP[i]=1e9;
		
		if(arr[i] || arr[i-1])
		{
			DP[i]=min(DP[i],DP[i-2]+1);
		}
		else
		{
			DP[i]=min(DP[i],DP[i-2]);
		}
		
		if(arr[i] || arr[i-1] || arr[i-2])
		{
			DP[i]=min(DP[i],DP[i-3]+1);
		}
		else
		{
			DP[i]=min(DP[i],DP[i-3]);
		}
		
		if(arr[i])
		{
			DP[i]=min(DP[i],1+DP[i-1]);
		}
		else
		{
			DP[i]=min(DP[i],DP[i-1]);
		}
	}
	
	mi=DP[n+1];
	
	int temp[n+2];
	for(int i=0;i<=n+1;i++)
	{
		temp[i]=arr[i];
	}
	
	bool flag[n+2]={0};

	for(int i=0;i<=n+1;i++)
	{
		if(temp[i]==0)
		{
			if((i+1)<=n+1 && temp[i+1])
			{
				flag[i]=1;
			}
			
			if((i-1)>=0 && temp[i-1])
			{
				flag[i]=1;
			}
		}
	}
	
	for(int i=0;i<=n+1;i++)
	{
		if(flag[i])
		{
			int j=i-1;
			
			while(j>=0 && arr[j])
			{
				if(temp[j]>=2)
				{
					temp[j]--;
					temp[i]=1;
					break;
				}
				j--;
			}
			
			if(!temp[i])
			{
				j=i+1;
				
				while(j<=n+1 && arr[j])
				{
					if(temp[j]>=2)
					{
						temp[j]--;
						temp[i]=1;
						break;
					}
					j++;
				}
			}
		}
	}
	
	int ma=0;
	for(int i=0;i<=n+1;i++)
	{
		if(temp[i])
			ma++;
	}
	cout<<mi<<' '<<ma<<endl;
	return 0;
}
