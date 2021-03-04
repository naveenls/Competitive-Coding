#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	long long w[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>w[i][j];
	}
	
	long long a[n],b[m];
	
	a[0]=0;
	for(int i=0;i<m;i++)
	{
		b[i]=w[0][i];
	}
	
	for(int i=1;i<n;i++)
	{
		a[i]=w[i][0]-b[0];
	}
	
	long long e[n][m];
	
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			e[i][j]=a[i]+b[j]-w[i][j];
			if(e[i][j])
			{
				flag=1;
			}
		}
	}
	
	if(!flag)
	{
		cout<<"YES"<<endl;
		long long gc=1e12;
		cout<<gc<<endl;
		for(int i=0;i<n;i++)
		{
			while(a[i]<0)
				a[i]+=gc;
				
			cout<<a[i]<<' ';
		}
		cout<<endl;
		
		for(int i=0;i<m;i++)
		{
			while(b[i]<0)
				b[i]+=gc;
				
			cout<<b[i]<<' ';
		}
		return 0;
	}
	
	long long gcd=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			gcd=__gcd(gcd,abs(e[i][j]));
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(w[i][j]>=gcd)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	
	cout<<"YES"<<endl;
	cout<<gcd<<endl;
	for(int i=0;i<n;i++)
	{
		while(a[i]<0)
			a[i]+=gcd;
			
		cout<<a[i]<<' ';
	}
	cout<<endl;
	
	for(int i=0;i<m;i++)
	{
		while(b[i]<0)
			b[i]+=gcd;
			
		cout<<b[i]<<' ';
	}
	return 0;
}
