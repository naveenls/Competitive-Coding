#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int i=1;
	int j=n;
	
	bool flag=0;
	while(i<=j)
	{
		if(flag==0)
		{
			cout<<i<<' ';
			i++;
			flag=1;
		}
		else
		{
			cout<<j<<' ';
			j--;
			flag=0;
		}
	}
	return 0;
}
