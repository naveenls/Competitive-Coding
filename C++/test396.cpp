#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	char arr[n][m];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	int mi_val=min(n,m);
	
	for(int i=0;i<n;i++)
	{
		int len=0;
		
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='.')
			{
				if(len)
				{
					mi_val=min(mi_val,len);
				}
				len=0;
			}
			else
			{
				len++;
			}	
		}
		
		if(len)
			mi_val=min(mi_val,len);
	}
	
	for(int j=0;j<m;j++)
	{
		int len=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i][j]=='.')
			{
				if(len)
				{
					mi_val=min(mi_val,len);
				}
				len=0;
			}
			else
			{
				len++;
			}
		}
		if(len)
			mi_val=min(len,mi_val);
	}
	
	if(mi_val%2==0)
		mi_val--;
		
	int t=mi_val/2;
	
	int DP[n][m];
	
	for(int i=0;i<n;i++)
	{
		if(arr[i][0]=='X')
			DP[i][0]=1;
		else
			DP[i][0]=0;
			
		if(i)
			DP[i][0]+=DP[i-1][0];
	}
	
	for(int i=0;i<m;i++)
	{
		if(arr[0][i]=='X')
			DP[0][i]=1;
		else
			DP[0][i]=0;
			
		if(i)
			DP[0][i]+=DP[0][i-1];
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(arr[i][j]=='X')
				DP[i][j]=1;
			else
				DP[i][j]=0;
			
			DP[i][j]+=(DP[i-1][j]+DP[i][j-1]-DP[i-1][j-1]);
		}
	}

	string* ans[n];
	for(int i=0;i<n;i++)
	{
		ans[i]=new string(m,'.');
	}
	for(int i=0;i<=n-mi_val;i++)
	{
		for(int j=0;j<=m-mi_val;j++)
		{
			int e_x=i+mi_val-1;
			int e_y=j+mi_val-1;
			
			int val=DP[e_x][e_y];
			
			if(j)
			{
				val-=DP[e_x][j-1];
			}
			if(i)
			{
				val-=DP[i-1][e_y];
			}	
			if(i&&j)
				val+=DP[i-1][j-1];
				
			if(val==mi_val*mi_val)
			{
				(*ans[i+t])[j+t]='X';
			}
		}
	}
	
	cout<<t<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<(*ans[i])[j];
		}
		cout<<endl;
	}
	return 0;
}
