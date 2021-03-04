#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	long long cnt=0;
	for(int z=c;z<=d;z++)
	{
		int min_A=max(a,z-c+1);
		if(min_A>b)
		{
			continue;
		}
		int num_time=b-min_A+1;
		
		if(num_time>c-b+1)
		{
			int temp=c-b+1;
			cnt+=(long long)temp*(temp+1)/2;
			num_time-=temp;
			cnt+=(long long)temp*num_time;
		}
		else
		{
			cnt+=(long long)num_time*(num_time+1)/2;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
