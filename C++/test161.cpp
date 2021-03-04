#include<bits/stdc++.h>
using namespace std;

void permute(int q[],int temp[],int n)
{
	int t[n];
	for(int i=0;i<n;i++)
	{
		t[i]=temp[q[i]-1];
	}
	
	for(int i=0;i<n;i++)
		temp[i]=t[i];
}

void inv_permute(int q[],int temp[],int n)
{
	int t[n];
	for(int i=0;i<n;i++)
	{
		t[q[i]-1]=temp[i];
	}
	
	for(int i=0;i<n;i++)
		temp[i]=t[i];
}

bool check(int a[],int b[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
			return false;
	}
	return true;
}
int main()
{
	int n,k;
	cin>>n>>k;
	
	int q[n],p[n];
	int temp[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>q[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		temp[i]=i+1;
	}
	
	int cnt=0;
	
	int tempC=k+2;
	
	while(tempC)
	{
		if(check(temp,p,n))
		{
			break;
		}
		else
		{
			permute(q,temp,n);
		}
		cnt++;
		tempC--;
	}
	
	int cnt1=0;
	tempC=k+2;
	
	for(int i=0;i<n;i++)
	{
		temp[i]=i+1;
	}
	
	while(tempC)
	{
		if(check(temp,p,n))
		{
			break;
		}
		else
		{
			inv_permute(q,temp,n);
		}
		cnt1++;
		tempC--;
	}
	
	//cout<<cnt<<' '<<cnt1<<endl;
	if(cnt==0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	if(cnt>k && cnt1>k)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	if(k==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		if(cnt==k || cnt1==k)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		if(cnt<=k)
		{
			if((k-cnt)%2==0 && (cnt1!=1 || cnt>1))
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
		
		if(cnt1<=k)
		{
			if((k-cnt1)%2==0 && (cnt!=1 || cnt1>1))
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
		
		cout<<"NO"<<endl;
	}
	return 0;
}
