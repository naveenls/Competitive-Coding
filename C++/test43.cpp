#include<bits/stdc++.h>
using namespace std;

//long long m=99853;

long long power(long long x, long long y,long long m) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2,m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
int main()
{
	string s;
	cin>>s;
	long long a,b;
	cin>>a>>b;
	long long n=s.size();
	
	long long moda[n],modb[n];
	moda[0]=(s[0]-'0')%a;
	for(int i=1;i<n;i++)
	{
		moda[i]=((moda[i-1]*10)%a + s[i]-'0')%a;
	}	
	
	modb[n-1]=(s[n-1]-'0')%b;
	for(int i=n-2;i>=0;i--)
	{
		modb[i]=(modb[i+1] + ((s[i]-'0')*power(10,(n-i-1),b))%b)%b;
	}
	if(s[0]=='0')
	{
		cout<<"NO"<<endl;
		return 0;
	}

	for(int i=0;i<n-1;i++)
	{
		if(moda[i]==0 && modb[i+1]==0 && s[i+1]!='0')
		{
			cout<<"YES"<<endl;
			cout<<s.substr(0,i+1)<<endl<<s.substr(i+1,n-i-1)<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
