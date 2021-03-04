#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int arr[2*n+1];
	for(int i=1;i<=n;i++)
	{
		arr[i]=i;
	}
	
	int last=0;
	
	for(int i=2;i<=n;i++)
	{
		int start_pos=i-1;
		for(int j=start_pos;j<start_pos+n;j+=i)
		{
			swap(arr[j],last);
		}
		
		swap(last,arr[start_pos+n]);
	}
	
	for(int i=n;i<2*n;i++)
		cout<<arr[i]<<' ';
	cout<<endl;
	return 0;
}
