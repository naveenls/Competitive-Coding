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
		
		int arr[2*n];
		for(int i=0;i<2*n;i++)
		{
			cin>>arr[i];
		}
		
		int right[2*n];
		memset(right,-1,sizeof(right));
		
		stack<int> s;
		
		for(int i=0;i<2*n;i++)
		{
			while(!s.empty() && arr[s.top()]<arr[i])
			{
				right[s.top()]=i;
				s.pop();
			}
			
			s.push(i);
		}
		
		for(int i=0;i<2*n;i++)
		{
			if(right[i]==-1)
				right[i]=2*n;
		}
		
		bool DP[2*n+1][n+1];
		memset(DP,0,sizeof(DP));
		
		DP[2*n][0]=1;
		
		for(int i=2*n-1;i>=0;i--)
		{			
			for(int j=0;j<=n;j++)
			{
				int num_ele=right[i]-i;
				
				if(num_ele<=j)
				{
					DP[i][j]=DP[right[i]][j] | DP[right[i]][j-num_ele];
				}
				else
				{
					DP[i][j]=DP[right[i]][j];
				}
			}
		}
		
		if(DP[0][n])
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
