#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int DP[n][4];
    for(int j=0;j<4;j++)
    {
        DP[0][j]=0;
    }
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            for(int j=0;j<4;j++)
            {
                DP[i][j]=1e9;
                
                for(int k=0;k<j;k++)
                {
                    DP[i][j]=min(DP[i][j],DP[i-1][k]);
                }
                for(int k=j;k<4;k++)
                {
                    DP[i][j]=min(DP[i][j],DP[i-1][k]+1);
                }
            }
        }
        else if(arr[i]<arr[i-1])
        {
            for(int j=0;j<4;j++)
            {
                DP[i][j]=1e9;
                
                for(int k=0;k<=j;k++)
                {
                    DP[i][j]=min(DP[i][j],DP[i-1][k]+1);
                }
                for(int k=j;k<4;k++)
                {
                    DP[i][j]=min(DP[i][j],DP[i-1][k]);
                }
            }
        }
        else
        {
            for(int j=0;j<4;j++)
            {
                DP[i][j]=1e9;
                
                for(int k=0;k<j;k++)
                {
                    DP[i][j]=min(DP[i][j],DP[i-1][k]+1);
                }
                
                DP[i][j]=min(DP[i][j],DP[i-1][j]);
                
                for(int k=j+1;k<4;k++)
                {
                    DP[i][j]=min(DP[i][j],DP[i-1][k]+1);
                }
            }
        }
    }
    
    int mi=1e9;
    for(int j=0;j<4;j++)
        mi=min(mi,DP[n-1][j]);
        
    cout<<mi<<endl;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve(); 
	}
	return 0;
}
