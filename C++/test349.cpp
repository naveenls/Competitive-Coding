#include<bits/stdc++.h>
using namespace std;

string s;
int arr[700];

long long mod=1e9+7;

long long DP[700][700][2][2];

long long find_ans(int l,int r,int l_col,int r_col)
{
	if(r<=l)
		return 1;
	
	if(DP[l][r][l_col][r_col]!=-1)
		return DP[l][r][l_col][r_col];
		
	long long ans=0;
	
	if(arr[l]==r)
	{
		if(!l_col && !r_col)
		{
			ans+=2*find_ans(l+1,r-1,0,1)%mod;
			ans%=mod;
			
			ans+=2*find_ans(l+1,r-1,1,0)%mod;
			ans%=mod;
			
		}
		else if(l_col)
		{
			ans+=find_ans(l+1,r-1,1,0)%mod;
			ans%=mod;
			
			ans+=2*find_ans(l+1,r-1,0,1)%mod;
			ans%=mod;
		}
		else
		{
			ans+=find_ans(l+1,r-1,0,1)%mod;
			ans%=mod;
			
			ans+=2*find_ans(l+1,r-1,1,0)%mod;
			ans%=mod;
		}
	}
	else
	{
		int r1=arr[l];
		
		if(!l_col && !r_col)
		{
			ans+=2*find_ans(l+1,r1-1,1,0)*find_ans(r1+1,r,0,0)%mod;
			ans%=mod;
			
			ans+=2*find_ans(l+1,r1-1,0,1)*find_ans(r1+1,r,1,0)%mod;
			ans%=mod;
		}
		else if(l_col)
		{
			ans+=find_ans(l+1,r1-1,1,0)*find_ans(r1+1,r,0,0)%mod;
			ans%=mod;
			
			ans+=2*find_ans(l+1,r1-1,0,1)*find_ans(r1+1,r,1,0)%mod;
			ans%=mod;
		}
		else
		{
			int r2=arr[r];

			ans+=find_ans(l,r2-1,0,0)*find_ans(r2+1,r-1,0,1)%mod;
			ans%=mod;
			
			ans+=2*find_ans(l,r2-1,0,1)*find_ans(r2+1,r-1,1,0)%mod;
			ans%=mod;
		}
	}
	DP[l][r][l_col][r_col]=ans;
	
	return ans;
		
}

int main()
{
	cin>>s;
	
	stack<int> ss;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			ss.push(i);
		}
		else
		{
			arr[ss.top()]=i;
			arr[i]=ss.top();
			
			ss.pop();
		}
	}
	
	memset(DP,-1,sizeof(DP));
	
	cout<<find_ans(0,s.size()-1,0,0);
	
	return 0;
}
