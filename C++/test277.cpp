#include<bits/stdc++.h>
using namespace std;

long long find_min(long long arr[],int n)
{
	long long mi=1e9;
	for(int i=0;i<n;i++)
		mi=min(mi,abs(arr[i]));
		
	return mi;
}
int main()
{
	int n;
	cin>>n;
	
	long long arr[n];
	
	int cnt_neg=0;
	int cnt_pos=0;
	
	long long sum_neg=0,sum_pos=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
		if(arr[i]<0)
			sum_neg+=-arr[i],cnt_neg++;
		else
			sum_pos+=arr[i],cnt_pos++;
	}
	
	if(n==1)
	{
		cout<<arr[0]<<endl;
	}
	else if(cnt_neg==n)
	{
		cout<<sum_neg-2*find_min(arr,n);
	}
	else if(cnt_pos==n)
	{
	//	cout<<sum_pos<<' '<<find_min(arr,n)<<endl;
		cout<<sum_pos-2*find_min(arr,n);
	}
	else
	{
		cout<<sum_neg+sum_pos<<endl;
	}
	return 0;
}
