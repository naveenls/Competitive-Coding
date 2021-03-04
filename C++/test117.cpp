#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+1;

int arr[maxN];
int n;

int DP[maxN]={0};
void factorize(int a)
{
	int temp=a;
	vector<int> fact;
	if(a%2==0)
	{
		while(a%2==0)
			a/=2;
		fact.push_back(2);
	}
	for(int i=3;i*i<=a;i++)
	{
		if(a%i==0)
		{
			fact.push_back(i);
			while(a%i==0)
				a/=i;
		}
	}
	if(a>1)
		fact.push_back(a);
		
	DP[temp]=1;
	for(auto ele:fact)
	{
		if(arr[ele]==-1)
		{
			arr[ele]=temp;
		}
		else
		{
			DP[temp]=max(DP[temp],DP[arr[ele]]+1);
			arr[ele]=temp;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(arr,-1,sizeof(arr));
	
	for(int i=n-1;i>=0;i--)
		factorize(a[i]);
	
	int ma=0;
	for(int i=0;i<maxN;i++)
	{
		ma=max(DP[i],ma);	
	}	
	cout<<ma<<endl;
	return 0;
}
