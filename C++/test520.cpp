#include<bits/stdc++.h>
using namespace std;

int find_par(int i,int par[])
{
	if(i==par[i])
		return i;
		
	par[i]=find_par(par[i],par);
	return par[i];
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		string a,b;
		cin>>a>>b;
		
		bool flag=0;
		
		for(int i=0;i<n;i++)
		{
			if(b[i]<a[i])
			{
				flag=1;
				break;	
			}
		}
		
		if(flag)
		{
			cout<<-1<<endl;
			continue;
		}
		
		int par[20];
		
		for(int i=0;i<20;i++)
		{
			par[i]=i;	
		}
		
		for(int i=0;i<n;i++)
		{
			int a1=find_par(a[i]-'a',par);
			int b1=find_par(b[i]-'a',par);
			
			if(a1!=b1)
				par[a1]=b1;
		}
		
		set<int> s;
		for(int i=0;i<20;i++)
			s.insert(find_par(i,par));
			
		cout<<20-s.size()<<endl;
	}
	return 0;
}
