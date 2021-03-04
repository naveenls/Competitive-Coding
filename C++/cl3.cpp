#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		
		int q;
		cin>>q;
		
		int n=s.size();
		
		int arr[n+1];
		int next[n+1];
		int nex[n+1];
		
		int nn[2*n+1];
		
		memset(nn,-1,sizeof(nn));
		
		arr[0]=0;
		if(s[n-1]=='(')
		{
			next[n]=n;
		}
		else
		{
			next[n]=-1;
		}
		
		for(int i=n-1;i>=1;i--)
		{
			if(s[i-1]=='(')
			{
				next[i]=i;
			}
			else
			{
				next[i]=next[i+1];
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='(')
			{
				arr[i]=1+arr[i-1];
			}
			else
			{
				arr[i]=-1+arr[i-1];
			}
		}
		
		for(int i=n;i>=0;i--)
		{
			nex[i]=nn[arr[i]+n];
			nn[arr[i]+n]=i;
		}
		
		int t;
		for(int i=0;i<q;i++)
		{
			cin>>t;
			
			int tt=next[t];
			if(tt==-1)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<nex[tt-1]<<endl;
			}
		}
	}
	return 0;
}
