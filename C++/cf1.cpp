#include<bits/stdc++.h>
using namespace std;

long long a[30];

long long DP[30][31];
bool flag[30];

long long find_max(int i,int k)
{
	if(k==0)
		return 0LL;
	
	if(i==30)
		return -1e18;
	
	if(DP[i][k]!=-1)
		return DP[i][k];
		
	long long ans1=a[i]*(1LL<<i) + find_max(i+1,k-1);
	long long ans2=find_max(i+1,k);
	
	DP[i][k]=max(ans1,ans2);
	
	return DP[i][k];
}

void rev(int k)
{
	int i=0;
	while(i<30 && k)
	{
		if(DP[i][k]==(a[i]*(1LL<<i) + find_max(i+1,k-1)))
		{
			flag[i]=1;
			k--;
		}
		else
		{
			flag[i]=0;
		}
		i++;
	}
}
int main()
{
	int T;
	cin>>T;
	
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		
		memset(a,0,sizeof(a));
		memset(flag,0,sizeof(flag));
		
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			
			for(int j=0;j<30;j++)
			{
				a[j]+=temp%2;
				temp/=2;
			}
		}
		
		memset(DP,-1,sizeof(DP));
		find_max(0,k);
		rev(k);
		
		int cnt=0;
		for(int i=0;i<30;i++)
			cnt+=flag[i];
		
		int rem=k-cnt;
		for(int i=0;i<30;i++)
		{
			if(rem && flag[i]==0)
			{
				flag[i]=1;
				rem--;
			}
		}
		
		long long p=1;
		
		long long ans=0;
		for(int i=0;i<30;i++)
		{
			if(flag[i])
			{
				ans+=p;
			}
			p*=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
