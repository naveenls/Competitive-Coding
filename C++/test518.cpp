#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<string> ans(n+1);
		
		ans[0]=string(50,'a');
		
		int x;
		
		for(int i=0;i<n;i++)
		{
			cin>>x;
			
			ans[i+1]=ans[i];
			
			if(x<50)
				ans[i+1][x]='a'+(ans[i+1][x]-'a'+1)%26;	
		}
		
		for(int i=0;i<=n;i++)
		{
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}
