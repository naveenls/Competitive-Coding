#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int> a,b;
		
		int arr[n];
		//int brr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(temp)
				b.push_back(arr[i]);
			else
				a.push_back(arr[i]);
		}
		
		if(a.size()==0)
		{
			bool flag=0;
			
			for(int i=1;i<b.size();i++)
			{
				if(b[i]<b[i-1])
				{
					flag=1;
					break;
				}
			}
			if(flag)
			{
				cout<<"No"<<endl;
			}
			else
			{
				cout<<"Yes"<<endl;
			}
		}
		else if(b.size()==0)
		{
			bool flag=0;
			for(int i=1;i<a.size();i++)
			{
				if(a[i]<a[i-1])
				{
					flag=1;
					break;
				}
			}
			
			if(flag)
			{
				cout<<"No"<<endl;
			}
			else
			{
				cout<<"Yes"<<endl;
			}
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;	
}
