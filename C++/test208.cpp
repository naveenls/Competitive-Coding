#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,b,a;
	cin>>n>>b>>a;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int temp1=b,temp2=a;
	int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1)
		{
			if(temp1 && temp2<a)
			{
				temp1--;	
				temp2=min(a,temp2+1);
			}
			else if(temp1 && temp2==a)
			{
				temp2--;
			}
			else if(temp2)
			{
				temp2--;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(temp2)
			{
				temp2--;
			}
			else if(temp1)
			{
				temp1--;
			}
			else
			{
				break;
			}
		}
		cnt++;
	}
	cout<<cnt<<endl;
}
