#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		
		int a[n+1][30];
		int b[n+1][30];
		
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));	
		
		int cnt[n+1]={0};
		
		int val;
		for(int i=1;i<=n;i++)
		{
			cin>>val;
		
			if(val==0)
			{
				cnt[i]++;	
				
				for(int j=0;j<30;j++)
				{
					a[i][j]+=a[i-1][j];
					b[i][j]+=b[i-1][j];
				}
			}	
			else
			{	
				bool flag=1;
				
				for(int j=0;j<30;j++)
				{
					if(val%2)
					{
						a[i][j]=1;
					}
					val/=2;
					
					if(val==0 && flag)
						b[i][j]=1,flag=0;
						
					a[i][j]+=a[i-1][j];
					b[i][j]+=b[i-1][j];
				}
			}
			cnt[i]+=cnt[i-1];
		}
		/*
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<30;j++)
			{
				cout<<a[i][j]<<' ';
			}
			cout<<endl;
		}*/
		int l,r;
		for(int i=0;i<q;i++)
		{
			cin>>l>>r;
			
			long long ans=0;
			
			for(int j=0;j<30;j++)
			{
				long long v1=a[r][j]-a[l-1][j];
				long long v2=b[r][j]-b[l-1][j];
				
				//cout<<v1<<' '<<v2<<' '<<j<<endl;
				
				v1-=v2;
				
				ans+=(v1*v2);
			}
			
			long long v1=cnt[r]-cnt[l-1];
			long long v2=(r-l+1)-v1;
			
			ans+=(v1*v2);
			ans+=(v1*(v1+1))/2;
			
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
