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
		
		int arr[101] = {0};
		int a;
		for(int i=0;i<n;i++)
			cin>>a, arr[a]++;
		
		for(int i=0;i<=100;i++)
		{
			if(arr[i])
			{
				cout<<i<<' ';
				arr[i]--;
			}
		}
		
		for(int i=0;i<=100;i++)
		{
			while(arr[i]--)
				cout<<i<<' ';
		}
		cout<<endl;
	}
	return 0;
}
