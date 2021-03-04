#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long sum=0;
	long long a,g;
	for(int i=0;i<n;i++)
	{
		cin>>a>>g;
		sum+=a;
	}
	long long k=sum/1000;
	
	if(k>n)
	{
		cout<<-1;
		return 0;
	}
	if(abs(1000*k-sum)>500)
	{
		if(k+1>n)
		{
			cout<<-1;
			return 0;
		}
		else
			k++;
	}
	string s="";
	int j=0;
	while(j<k)
	{
		s+="G";
		j++;
	}
	while(j<n)
	{
		s+="A";
		j++;
	}
	cout<<s;
	
	return 0;
}
