#include<bits/stdc++.h>
using namespace std;

int find_parent(int i,int par[])
{
	if(par[i]==i)
		return par[i];
		
	par[i]=find_parent(par[i],par);
	
	return par[i];
}
int main()
{
	int n,q;
	cin>>n>>q;
	
	int par[n];
	for(int i=0;i<n;i++)
	{
		par[i]=i;
	}
	
	int num_groups=n;
	
	int l,r;
	for(int i=0;i<q;i++)
	{
		cin>>l>>r;
		
		l--,r--;
		
		for(int j=l;j<l+(r-l+1)/2;j++)
		{
			int k=j-l;
			
			int a=find_parent(j,par);
			int b=find_parent(r-k,par);
			
			if(a!=b)
			{
				num_groups--;
				par[b]=a;
			}
		}
		cout<<num_groups<<endl;
	}
	return 0;
}
