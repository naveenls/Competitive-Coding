#include<bits/stdc++.h>
using namespace std;

bool check(string a,string b)
{
	//cout<<a<<' '<<b<<endl;
	for(int i=1;i<a.size()-1;i++)
	{
		if(a[i]!=b[i])
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	
	string s,t;
	cin>>s>>t;
	
	int i=-1,j=n;
	
	while(s[i+1]==t[i+1])
		i++;
		
	while(s[j-1]==t[j-1])
		j--;
		
	string a=s.substr(i+1,j-i-1);
	string b=t.substr(i+1,j-i-1);
	
	int ans=0;
	
	if(check(a+" "," "+b))
	{
		ans++;
	}
	if(check(" "+a,b+" "))
	{
		ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}
