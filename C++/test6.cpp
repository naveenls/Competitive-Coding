#include<bits/stdc++.h>

using namespace std;

void divide(int &a,int arr[])
{
	while(a%2==0)
	{
		a/=2;
		arr[0]++;
	}
	while(a%3==0)
	{
		a/=3;
		arr[1]++;
	}
	while(a%5==0)
	{
		a/=5;
		arr[2]++;
	}
	
}
int main()
{
	int a,b;
	cin>>a>>b;

	int arr1[3]={0};
	int arr2[3]={0};
	
	divide(a,arr1),divide(b,arr2);
	if(a!=b)
	{
		cout<<-1;
		return 0;
	}
	
	cout<<abs(arr1[0]-arr2[0])+abs(arr1[1]-arr2[1])+abs(arr1[2]-arr2[2]);
	return 0;
}
