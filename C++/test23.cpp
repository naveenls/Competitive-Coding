#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	long long arr[(1<<n)][18];
	bool op[18];
	int flag=1;
	for(int i=n-1;i>=0;i--)
	{
		op[i]=flag;
		flag=1-flag;
	}
	
	for(int i=0;i<(1<<n);i++)
	{
		cin>>arr[i][n];
	}
	
	for(int j=n-1;j>=0;j--)
	{
		for(int i=0;i<(1<<j);i++)
		{
			if(op[j])
				arr[i][j]=arr[2*i][j+1] | arr[2*i+1][j+1];
			else
				arr[i][j]=arr[2*i][j+1] ^ arr[2*i+1][j+1];
		}
	}
	
	int p;
	long long b;
	
	while(m--)
	{
		cin>>p>>b,p--;
		arr[p][n]=b;
		int i=p/2;
		int j=n-1;
		while(j>=0)
		{
			if(op[j])
				arr[i][j]=arr[2*i][j+1] | arr[2*i+1][j+1];
			else
				arr[i][j]=arr[2*i][j+1] ^ arr[2*i+1][j+1];
				
			j--;
			i/=2;
		}
		cout<<arr[0][0]<<endl;
	}
	return 0;
}
