#include<bits/stdc++.h>
using namespace std;

int n,m;
const int maxN=5000;

long long mod=1e9+7;

long long DP[maxN][maxN];

string s,t;

long long find_val(int i,int j)
{
	
	if(j==m || i==n)
		return 1;

		
	if(DP[i][j]!=-1)
		return DP[i][j];
		
	long long ans=0;
	
	if(s[i]==t[j])
	{
		ans=(ans+find_val(i+1,j+1))%mod;
	}
	ans=(ans+find_val(i,j+1))%mod;
		
	DP[i][j]=ans;
	return ans;
}
int main()
{

	cin>>s>>t;
	
	n=s.size();
	m=t.size();
	
	memset(DP,-1,sizeof(DP));
	
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(find_val(i,0));
		ans%=mod;
	}
	
	cout<<(ans-n+mod)%mod;
	return 0;
}
