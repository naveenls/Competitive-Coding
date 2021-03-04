#include<bits/stdc++.h>
using namespace std;

int main()
{
	int p[5];
	int sum = 0;
	
	for(int i=0;i<5;i++)
		cin>>p[i], sum += p[i];
	
	for(int i=0;i<5;i++)
	{
		if(p[i] >= sum-p[i])
		{
			cout<<"SPD Emergency"<<endl;
			return 0;
		}
	}
	cout<<"Stable"<<endl;
	
	return 0;
}
