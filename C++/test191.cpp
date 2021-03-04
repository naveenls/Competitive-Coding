#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	string arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int row[n]={0},col[m]={0};
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='w')
			{
				row[i]++;
				col[j]++;
			}
		}
	}
	
	int r_l,r_r;
	for(int i=0;i<n;i++)
	{
		if(row[i])
		{
			r_l=i;
			break;
		}
	}
	
	for(int i=n-1;i>=0;i--)
	{
		if(row[i])
		{
			r_r=i;
			break;
		}
	}
	
	int c_l,c_r;
	for(int i=0;i<m;i++)
	{
		if(col[i])
		{
			c_l=i;
			break;
		}
	}
	
	for(int i=m-1;i>=0;i--)
	{
		if(col[i])
		{
			c_r=i;
			break;
		}
	}
	
	if(r_r-r_l!=c_r-c_l)
	{
		cout<<-1;
		return 0;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='w')
			{
				if(i==r_r || i==r_l)
				{
					if(j<c_l || j>c_r)
					{
						cout<<-1;
						return 0;
					}
				}
				else if(j==c_l || j==c_r)
				{
					if(i<r_l || i>r_r)
					{
						cout<<-1;
						return 0;
					}
				}
				else
				{
					cout<<-1;
					return 0;
				}
			}
		}
		for(int i=r_l;i<=r_r;i++)
		{
			if(arr[i][c_l]=='.')
				arr[i][c_l]='+';
				
			if(arr[i][c_r]=='.')
				arr[i][c_r]='+';
		}
		
		for(int j=c_l;j<=c_r;j++)
		{
			if(arr[r_l][j]=='.')
				arr[r_l][j]='+';
				
			if(arr[r_r][j]=='.')
				arr[r_r][j]='+';
		}
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<endl;
		}
	}
	return 0;
}
