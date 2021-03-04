#include<bits/stdc++.h>
using namespace std;

int main()
{
    
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=(s[i]=='1');
		
		int ans=2*1e7;
		for(int t=0;t<k;t++)
		{
			vector<int> vals;
			for(int j=t;j<n;j+=k)
			{
				if(s[j]=='1')
				{
					vals.push_back(1);
				}
				else
				{
					vals.push_back(0);
				}
			}
			int DP[vals.size()];
			DP[0]=(vals[0]==0);
			int num_1=vals[0];
		
			for(int i=1;i<vals.size();i++)
			{
				DP[i]=min(DP[i-1]+(vals[i]==0),num_1+(vals[i]==0));
				//cout<<DP[i]<<' '<<t<<endl;
				num_1+=vals[i];
			}
			int temp=sum-num_1;
			
			int mi=num_1;
			for(int i=0;i<vals.size();i++)
			{
				num_1-=vals[i];
				mi=min(mi,DP[i]+num_1);
				//cout<<DP[i]<<' '<<num_1<<' '<<t<<endl;
			}
			//cout<<mi+temp<<endl;
			ans=min(mi+temp,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
