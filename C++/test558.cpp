#include<bits/stdc++.h>
using namespace std;

int find_min(string &s)
{	

	if(s.size()==1)
		return 1e9;
		
	if(s.size()==2)
	{
		int val=(s[0]!='R') + (s[1]!='L');
		return val;
	}
			
	int n=s.size();
	
	int DP[n+1];
	DP[n]=0;
	
	DP[n-1]=0;
	DP[n-2]= (s[n-2]!='R') + (s[n-1]!='L');
	
	for(int i=n-3;i>=0;i--)
	{
		int val1= (s[i]!='R') + (s[i+1]!='L');
		int a=(s[i]!='R') + (s[i+1]!='R') + (s[i+2]!='L');
		int b=(s[i]!='R') + (s[i+1]!='L') + (s[i+2]!='L');
		
		int val2=min(a,b);
		
		DP[i]=min(val1+DP[i+2],val2+DP[i+3]);
	}
	
	return DP[0];
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		string s;
		
		cin>>n>>s;
		
		if(n==3)
		{
			int a=(s[0]!='R') + (s[1]!='R') + (s[2]!='R');
			int b=(s[0]!='L') + (s[1]!='L') + (s[2]!='L');
			
			if(max(a,b)==3)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
						
			continue;
		}
		
		int mi=find_min(s);
		
		string s1=s.substr(1,n-2);
		string s2=s.substr(2,n-3);
		string s3=s.substr(1,n-3);
		
		int val1=(s[0]!='L') + (s[n-1]!='R');
		int val2=(s[0]!='R') + (s[1]!='L') + (s[n-1]!='R');
		int val3=(s[0]!='L') + (s[n-2]!='R') + (s[n-1]!='L');
		
		
		mi=min(mi,find_min(s1)+val1);
		mi=min(mi,find_min(s2)+val2);
		mi=min(mi,find_min(s3)+val3);
		
		cout<<mi<<endl;
	}
	return 0;
}
