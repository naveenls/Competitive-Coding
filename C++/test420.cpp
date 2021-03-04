#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	string s;
	cin>>s;
	
	string b(n,'a');
	
	for(int i=0;i<k;i++)
	{
		b[i]=s[i];
	}
	for(int i=0;i<n-k;i++)
	{
		int j=i+k;
		b[j]=b[i];
	}
	cout<<s.size()<<endl;
	
	if(b>=s)
	{
		cout<<b<<endl;
	}
	else
	{
		for(int i=k-1;i>=0;i--)
		{
			if(b[i]<'9')
			{
				b[i]++;
				break;
			}
			else
			{
				b[i]='0';
			}
		}
		for(int i=0;i<n-k;i++)
		{
			int j=i+k;
			b[j]=b[i];
		}
		cout<<b<<endl;
	}
	return 0;
}
