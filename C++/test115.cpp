#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long l,r;
	cin>>l>>r;
	
	int a[60]={0};
	int b[60]={0};
	int i=0;
	while(l)
	{
		a[i]=l%2;
		l/=2;
		i++;
	}
	i=0;
	while(r)
	{
		b[i]=r%2;
		r/=2;
		i++;
	}
	
	bool flag=0;
	int ans[60];
	long long ind=-1;
	for(int i=59;i>=0;i--)
	{
		if(a[i]!=b[i])
		{
			ind=i;
			break;
		}
	}
	if(ind==-1)
		cout<<0<<endl;
	else
	{
		cout<<(1<<(ind+1))-1<<endl;
	}
	return 0;
}
