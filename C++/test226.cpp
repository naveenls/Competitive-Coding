#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;
	
	int cnt1=0,cnt2=0;
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(temp==1)
			cnt1++;
		else
			cnt2++;
	}
	
	if(cnt1==0)
	{
		for(int i=0;i<n;i++)
		{
			cout<<2<<' ';
		}
		return 0;
	}
	
	if(cnt2)
	{
		cnt2--;
		cout<<2<<' ';
		cout<<1<<' ';
		cnt1--;
		
		while(cnt2--)
		{
			cout<<2<<' ';
		}
		while(cnt1--)
		{
			cout<<1<<' ';
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<<1<<' ';
		}
	}
	return 0;
}
