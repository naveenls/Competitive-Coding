#include<bits/stdc++.h>
using namespace std;

int n,m,k;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m>>k;
	
	string arr[n];
	int DP[n][m][k+1];
	int pos[n][m][k+1];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int t=0;t<=k;t++)
			{
				DP[i][j][t]=-1e9;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>arr[n-i-1];
	}
	
	for(int i=0;i<m;i++)
	{
		int a=(arr[0][i]-'0')%(k+1);
		
		DP[0][i][a]=arr[0][i]-'0';
	}
	/*
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<=k;j++)
		{
			cout<<DP[0][i][j]<<' ';
		}
		cout<<endl;
	}
	/**/
	for(int i=1;i<n;i++)
	{
		for(int t=0;t<=k;t++)
		{
			int a=(arr[i][0]-'0')%(k+1);
				
			a=(t-a+ (k+1) )%(k+1);
			DP[i][0][t]=DP[i-1][1][a]+arr[i][0]-'0';
			pos[i][0][t]=1;
		}
		
		
		for(int j=1;j<m-1;j++)
		{
			for(int t=0;t<=k;t++)
			{
				int a=(arr[i][j]-'0')%(k+1);
				
				a=(t-a+ (k+1) )%(k+1);
				DP[i][j][t]=max(DP[i-1][j-1][a],DP[i-1][j+1][a])+arr[i][j]-'0';
				
				if(DP[i][j][t]==DP[i-1][j+1][a]+arr[i][j]-'0')
					pos[i][j][t]=1;
				else
					pos[i][j][t]=-1;
			}
		}
		
		for(int t=0;t<=k;t++)
		{
			int a=(arr[i][m-1]-'0')%(k+1);
			
			a=(t-a+(k+1))%(k+1);
			DP[i][m-1][t]=DP[i-1][m-2][a]+arr[i][m-1]-'0';
			pos[i][m-1][t]=-1;
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	int ma=-1;
	for(int i=0;i<m;i++)
	{
		ma=max(DP[n-1][i][0],ma);
	}
	
	if(ma==-1)
	{
		cout<<-1<<endl;
	}
	else
	{
		int ind;
		for(int i=0;i<m;i++)
		{
			if(ma==DP[n-1][i][0])
			{
				ind=i;
				break;
			}
		}
		
		int X=n-1,Y=ind;
		int z=0;
		
		string ans="";
		while(X>0)
		{
			int x_n=X-1;
			int z_n=(z-(arr[X][Y]-'0')%(k+1) + (k+1) )%(k+1);
		
			int y_n=Y+pos[X][Y][z];
			
			if(pos[X][Y][z]==-1)
			{
				ans.push_back('R');
			}
			else
			{
				ans.push_back('L');
			}
			
			X=x_n,Y=y_n,z=z_n;
		}
		cout<<ma<<endl;
		cout<<Y+1<<endl;
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
		
	}
	return 0;
}
