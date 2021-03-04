#include<bits/stdc++.h>
using namespace std;

long long mod=1e15;

void solve()
{
	int l;
	cin>>l;
	
	string s[l];
	for(int i=0;i<l;i++)
	{
		cin>>s[i];
	}
	
	int x1,x2;
	
	char c;
	
	cin>>c;
	x1=c;
	
	cin>>c;
	x2=c;
	
	int n;
	cin>>n;
	
	vector<map<int,int> > vec(n+1);
	
	for(int i=0;i<l;i++)
	{
		if(s[i].size()<=n)
		{
			int len=s[i].size();
			
			sort(s[i].begin()+1,s[i].end()-1);
			
			long long val=0;
			
			for(int j=0;j<len;j++)
			{
				val=(val*26 + s[i][j]-'a')%mod;
			}
			
			vec[len][val].push_back(i);
		}
	}
	
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	
	vector<long long> v(n);
	v[0]=x1;
	v[1]=x2;
	 
	for(int i=2;i<N;i++)
	{
		long long val=(a*v[i-1]+b*v[i-2]+c)%d;
		v[i]=val;
	}
	
	string s(n,'a');
	s[0]=v[0];
	s[1]=v[1];
	
	for(int i=2;i<n;i++)
	{
		s[i]='a'+v[i]%26;
	}
	
	
}
int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
	    cout<<"Case #"<<i<<": ";
	    solve();
	}
	return 0;
}
