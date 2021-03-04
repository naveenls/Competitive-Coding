#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long double arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]==1.0)
		{
			cout<<fixed<<setprecision(10)<<arr[i]<<endl;
			return 0;
		}
	}
		
	sort(arr,arr+n,greater<long double> ());

	long double ini_p=(1-arr[0]);
	long double ini_sum=arr[0]/(1-arr[0]);
	
	for(int i=1;i<n;i++)
	{
		long double val=ini_p*(1-arr[i])*(ini_sum+arr[i]/(1-arr[i]));
		//cout<<val<<' '<<ini_p*ini_sum<<endl;
		if(val>= ini_p*ini_sum)
		{
			ini_p*=(1-arr[i]);
			ini_sum+=arr[i]/(1-arr[i]);
		}
		else
		{
			break;
		}
	}
	cout<<fixed<<setprecision(10)<<ini_p*ini_sum<<endl;
	return 0;
}
