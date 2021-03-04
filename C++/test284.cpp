#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	if(n%4==0 || n%4==1)
	{
		int arr[n];
		
		int j=0;
		for(int i=0;i<n/4;i++)
		{
			arr[j]=j+2;
			arr[j+1]=n-j;
			
			arr[n-j-1]=n-j-1;
			arr[n-j-2]=j+1;
			j+=2;
		}
		if(n%4==1)
		{
			arr[j]=j+1;
		}
		for(int i=0;i<n;i++)
			cout<<arr[i]<<' ';
	}
	else
	{
		cout<<-1<<endl;
	}
}
