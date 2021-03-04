#include<bits/stdc++.h>
using namespace std;

string s,t;

bool check(int i,int j,int sz)
{
	if(s.substr(i,sz)==t.substr(j,sz))
		return true;
	
	if(sz%2)
		return false;
		
	bool check1=check(i,j,sz/2) && check(i+sz/2,j+sz/2,sz/2);
	
	if(check1)
		return true;
		
	bool check2=check(i+sz/2,j,sz/2) && check(i,j+sz/2,sz/2);
	
	if(check2)
		return true;
		
	return false;
}
int main()
{
	cin>>s>>t;
	
	if(check(0,0,s.size()))
	{
		cout<<"YES"<<endl;	
	}	
	else
		cout<<"NO"<<endl;
}
