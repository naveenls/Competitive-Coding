#include<bits/stdc++.h>
using namespace std;

int m=7;

int power(int x, int y) 
{ 
    if (y == 0) 
        return 1; 
    int p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
int a,b,c,d;
bool find_perm(int rem,int n)
{
	int arr[24][4]={
	{1,6,8,9},
	{6,1,8,9},
	{8,1,6,9},
	{1,8,6,9},
	{6,8,1,9},
	{8,6,1,9},
	{8,6,9,1},
	{6,8,9,1},
	{9,8,6,1},
	{8,9,6,1},
	{6,9,8,1},
	{9,6,8,1},
	{9,1,8,6},
	{1,9,8,6},
	{8,9,1,6},
	{9,8,1,6},
	{1,8,9,6},
	{8,1,9,6},
	{6,1,9,8},
	{1,6,9,8},
	{9,6,1,8},
	{6,9,1,8},
	{1,9,6,8},
	{9,1,6,8}};
	
	for(int i=0;i<24;i++)
	{
	    int temp=arr[i][0]*1000+arr[i][1]*100+arr[i][2]*10+arr[i][3];
	    //cout<<temp<<endl;
	    int val=(temp*power(10,n))%7;
	    //cout<<val<<' '<<remendl;
	    if((val+rem)%7==0)
	    {
	        a=arr[i][0];
	        b=arr[i][1];
	        c=arr[i][2];
	        d=arr[i][3];
	        return true;
	    }
	}
	return false;
}
int main()
{
    
	string s;
	cin>>s;
	string res="";
	int rem=0;
	int c1=0,c6=0,c8=0,c9=0;
	//cout<<"hi"<<endl;
	for(int i=0;i<s.size();i++)
	{
	    //cout<<"hi";
		if(s[i]=='1' && c1==0)
		{
			c1++;
		}
		else if(s[i]=='6' && c6==0)
		{
			c6++;
		}
		else if(s[i]=='8' && c8==0)
		{
			c8++;
		}
		else if(s[i]=='9' && c9==0)
		{
			c9++;
		}
		else
		{
			rem=(rem*10+s[i]-'0')%7;
			res.push_back(s[i]);
		}
	}
	//cout<<"Hi";
	if(find_perm(rem,s.size()-4))
	{
	    cout<<a<<b<<c<<d;
	    //res=to_string(a)+to_string(b)+to_string(c)+to_string(d)+res;
	    cout<<res;
	}
	else
	{
	    cout<<0;
	}
	return 0;
}
