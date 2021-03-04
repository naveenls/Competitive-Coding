#include<bits/stdc++.h>
using namespace std;

bool check(int ts,int js)
{
	while(true)
	{
		if(ts%2==0 && js%2==0)
		{
			ts/=2;
			js/=2;
		}
		else if(ts%2==0 && js%2)
			return false;
		else if(ts%2 && js%2==0)
			return true;
		else
			return false;
	}
}
int main()
{
	int ts=100;
	while(ts--)
	{		
		int cnt=0;
		for(int i=1;i<=ts;i++)
		{
			if(check(ts,i))
				cnt++;
			
		}
		cout<<cnt<<endl;
	}
	return 0;
}
