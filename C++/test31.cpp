#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+10;
int main()
{
	int n;
	cin>>n;
	int arr[maxN];
	int c[5001]={0};
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		c[arr[i]]++;
	}
	int i=1;
	int j=5000;
	int sum=0;
	while(i<j)
	{
		while(!c[i])
		{
			i++;
		}
		while(!c[j])
		{
			j--;
		}
		if(j>2*i)
		{
			if(c[i]>c[j])
			{
				sum+=c[j];
				j--;
			}
			else
			{
				sum+=c[i];
				i++;
			}
		}
		else
			break;
	}
	cout<<sum<<endl;
}
