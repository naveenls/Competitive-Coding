#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	vector<int> a,b;
	a.push_back(-1);
	b.push_back((int)3*1e5);
	
	bool flag[n];
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]>a[a.size()-1] && arr[i]<b[b.size()-1])
		{
			if(i+1<n && arr[i+1]<arr[i])
			{
				b.push_back(arr[i]);
				flag[i]=1;
			}
			else
			{
				a.push_back(arr[i]);
				flag[i]=0;
			}
		}
		else if(arr[i]>a[a.size()-1])
		{
			a.push_back(arr[i]);
			flag[i]=0;
		}
		else if(arr[i]<b[b.size()-1])
		{
			b.push_back(arr[i]);
			flag[i]=1;
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<flag[i]<<' ';
	}
	cout<<endl;
	return 0;
}
