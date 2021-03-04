#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=s[i]-'A';
	}
	if(k>2)
	{
		int cnt=0;
		for(int i=1;i<s.size();i++)
		{
			if(arr[i]==arr[i-1])
			{
				cnt++;
				arr[i]=(arr[i]+1)%k;
				if(i+1<n)
				{
					if(arr[i+1]==arr[i])
					{
						arr[i]=(arr[i]+1)%k;
					}
				}
			}
		}
		cout<<cnt<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<(char)(arr[i]+'A');
		}
	}
	else
	{
		int flag=0;
		int c1=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]!=flag)
				c1++;
			flag=1-flag;
		}
		flag=1;
		int c2=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]!=flag)
				c2++;
			flag=1-flag;
		}
		if(c1<c2)
		{
			cout<<c1<<endl;
			flag=0;
			for(int i=0;i<n;i++)
			{
				cout<<(char)(flag+'A');
				flag=1-flag;
			}
		}
		else
		{
			cout<<c2<<endl;
			flag=1;
			for(int i=0;i<n;i++)
			{
				cout<<(char)(flag+'A');
				flag=1-flag;
			}
		}
	}
	return 0;
}
