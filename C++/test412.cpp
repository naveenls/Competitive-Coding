#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,c;
	cin>>r>>c;
	
	if(r==1 && c==1)
	{
		cout<<0<<endl;
		return 0;
	}
	else if(r==1)
	{
		int cnt=2;
		
		for(int i=0;i<c;i++)
		{
			cout<<cnt<<' ';
			cnt++;
		}
		return 0;
	}
	else if(c==1)
	{
		int cnt=2;
		
		for(int i=0;i<r;i++)
		{
			cout<<cnt<<endl;
			cnt++;
		}
		return 0;
	}
	int a[r];
	int b[c];
	
	int cnt=1;
	for(int i=0;i<c;i++)
	{
		b[i]=cnt;
		cnt++;
	}
	
	for(int i=0;i<r;i++)
	{
		a[i]=cnt;
		cnt++;
	}
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<a[i]*b[j]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}
