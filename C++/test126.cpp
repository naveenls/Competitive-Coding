#include<bits/stdc++.h>
using namespace std;
const int maxV=1e4;

long long mod=1e9+7;

int val;

int main()
{
	int r,g;
	cin>>r>>g;
	
	val=(-1+sqrt(r+g))/2;
	
	if(r>g)
		swapr(r,g);
		
	long long DP[r+10];
	
	return 0;
}
