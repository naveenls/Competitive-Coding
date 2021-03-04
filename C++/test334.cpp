#include<bits/stdc++.h>
using namespace std;

long long maxEvenLenSum(long long arr[], int n) 
{
    if (n < 2) 
        return 0; 

    long long dp[n] = { 0 }; 

    dp[n - 1] = 0; 
    dp[n - 2] = arr[n - 2] + arr[n - 1]; 
  
    for (int i = n - 3; i >= 0; i--) { 

        dp[i] = arr[i] + arr[i + 1]; 

        if (dp[i + 2] > 0) 
            dp[i] += dp[i + 2]; 
    } 

    long long maxSum = *max_element(dp, dp + n); 
    return maxSum; 
} 

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		long long arr[n];
		
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(i%2==0)
			{
				sum+=arr[i];
				arr[i]*=-1;
			}
		}
		
		long long temp=maxEvenLenSum(arr,n);
		cout<<sum+max(0LL,temp)<<endl;
		
	}
	return 0;
}
