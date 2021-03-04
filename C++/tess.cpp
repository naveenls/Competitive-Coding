#include<bits/stdc++.h>
using namespace std;

int main()
{
	int cnt=2;
	
	int i=0;
	int j=999;
	
	bool flag=0;
	
	while(i<j)
	{
		int mid=(i+j)/2;
		if(flag==0)
		{
			i=mid+1;
			flag=1;
		}
		else
		{
			j=mid;
			flag=0;
		}
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
