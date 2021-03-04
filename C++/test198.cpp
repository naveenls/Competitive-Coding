#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	cin>>k;
	
	string s,t;
	cin>>s>>t;
	
	vector<int> a(k+1),b(k+1);
	
	a[0]=0,b[0]=0;
	for(int i=0;i<k;i++)
	{
		a[i+1]=s[i]-'a';
		b[i+1]=t[i]-'a';
	}
	
	for(int i=k;i>0;i--)
	{
		a[i]+=b[i];
		a[i-1]+=a[i]/26;
		a[i]%=26;
	}
	
	for(int i=0;i<k;i++)
	{
		int rem=a[i]%2;
		a[i]/=2;
		
		a[i+1]+=rem*26;
	}
	a[k]/=2;
	
	string ans="";
	for(int i=1;i<=k;i++)
	{
		ans.push_back(a[i]+'a');
	}
	cout<<ans<<endl;
	return 0;
}
