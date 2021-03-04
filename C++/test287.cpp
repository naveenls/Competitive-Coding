#include<bits/stdc++.h>
using namespace std;

int b_search1(int val)
{
	int l=3,r=100;
	
	int ans;
	
	while(l<=r)
	{
		int mid=(l+r)/2;
		
		if((mid*(mid-1)*(mid-2))/6 <=val)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}

int b_search(int val)
{
	int l=2,r=100;
	
	int ans;
	
	while(l<=r)
	{
		int mid=(l+r)/2;
		
		if((mid*(mid-1))/2 <=val)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
int main()
{
	int k;
	cin>>k;
	
	int temp=b_search1(k);
		
	k-=(temp*(temp-1)*(temp-2))/6;	
	
	vector<int> t;
	
	while(k)
	{
		//cout<<k<<endl;
		int tt=b_search(k);
		//cout<<tt<<endl;
		t.push_back(tt);
		k-=(tt*(tt-1))/2;
	}
	
	int t_size=temp+t.size();
	
	int arr[t_size][t_size];
	memset(arr,0,sizeof(arr));
	
	for(int i=0;i<temp;i++)
	{
		for(int j=0;j<temp;j++)
		{
			if(i!=j)
				arr[i][j]=1;
		}
	}
	
	for(int i=temp;i<t_size;i++)
	{
		for(int j=0;j<t[i-temp];j++)
		{
			arr[i][j]=1;
			arr[j][i]=1;
		}
	}
	cout<<t_size<<endl;
	for(int i=0;i<t_size;i++)
	{
		for(int j=0;j<t_size;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	return 0;
}
