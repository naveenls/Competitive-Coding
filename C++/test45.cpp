#include<bits/stdc++.h>
using namespace std;

//long long mod=1e9+7;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	sort(arr,arr+n);
	set<int> d_val;
	for(int i=1;i<n;i++)
	{
		d_val.insert(arr[i]-arr[i-1]);
	}
	if(n==2)
	{
		int d=(arr[1]-arr[0]);
		if(d==0)
		{
			cout<<1<<endl;
			cout<<arr[0]<<endl;
		}
		else if(d%2==0)
		{
			cout<<3<<endl;
			cout<<arr[0]-d<<' '<<arr[0]+d/2<<' '<<arr[1]+d<<endl;
		}
		else
		{
			cout<<2<<endl;
			cout<<arr[0]-d<<' '<<arr[1]+d<<endl;
		}
		return 0;
	}
	if(n==3)
	{
		int d1=(arr[1]-arr[0]);
		int d2=(arr[2]-arr[1]);
		
		if(d1==d2)
		{
			if(d1==0)
			{
				cout<<1<<endl;
				cout<<arr[0]<<endl;
			}
			else
			{
				cout<<2<<endl;
				cout<<arr[0]-d1<<' '<<arr[2]+d1<<endl;
			}
		}
		else
		{
			if(d1%2==0 && d1/2==d2)
			{
				cout<<1<<endl;
				cout<<arr[0]+d1/2<<endl;
			}
			else if(d2%2==0 && d2/2==d1)
			{
				cout<<1<<endl;
				cout<<arr[1]+d2/2<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		return 0;
	}
	if(d_val.size()==0)
	{
		cout<<-1;
	}
	else if(d_val.size()==1)
	{
		//cout<<2<<endl;
		int d=arr[1]-arr[0];
		if(d==0)
		{
			cout<<1<<endl;
			cout<<arr[0]<<endl;
		}
		else
		{
			cout<<2<<endl;
			cout<<arr[0]-d<<' '<<arr[n-1]+d<<endl;
		}
	}
	else if(d_val.size()==2)
	{
		int d1=arr[1]-arr[0];
		int x1=1;
		int x2;
		int d2=-1;
		int c=0;
		for(int i=1;i<n;i++)
		{
			if(arr[i]-arr[i-1]!=d1)
			{
				d2=arr[i]-arr[i-1];
				c++;
				x2=i;
			}
		}
		if(c==1)
		{
			if(d2%2==0 && d2/2==d1)
			{
				cout<<1<<endl;
				cout<<arr[x2-1]+d2/2<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		else if(c==n-2)
		{
			if(d1%2==0 && d1/2==d2)
			{
				cout<<1<<endl;
				cout<<arr[x1-1]+d1/2<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		else
		{
			cout<<0<<endl;
		}
		
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
