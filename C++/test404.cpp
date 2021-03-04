#include<bits/stdc++.h>
using namespace std;

const int maxN=203;

int DP[maxN][maxN][maxN];
int n,m;

string s,t;

string f_ans="";

int find_min(int i,int j,int prev_sum)
{
	if(prev_sum<0 || prev_sum>200)
		return 1e9;
	
	if(i==n && j==m)
	{
		return prev_sum;
	}
	
	if(DP[i][j][prev_sum]!=-1)
	{
		return DP[i][j][prev_sum];
	}

	int ans=1e9;
			
	bool f1= (i<n && s[i]=='(' );
	bool f2= (j<m && t[j]=='(');
	
	if(i==n)
	{
		if(f2)
		{
			ans=min(ans,1+find_min(i,j+1,prev_sum+1));
			ans=min(ans,1+find_min(i,j,prev_sum-1));	
		}
		else
		{
			ans=min(ans,1+find_min(i,j,prev_sum+1));
			ans=min(ans,1+find_min(i,j+1,prev_sum-1));	
		}
	}
	else if(j==m)
	{
		if(f1)
		{
			ans=min(ans,1+find_min(i+1,j,prev_sum+1));
			ans=min(ans,1+find_min(i,j,prev_sum-1));	
		}
		else
		{
			ans=min(ans,1+find_min(i,j,prev_sum+1));
			ans=min(ans,1+find_min(i+1,j,prev_sum-1));	
		}
	}
	else if(f1 && f2)
	{
		ans=min(ans,1+find_min(i+1,j+1,prev_sum+1));
		ans=min(ans,1+find_min(i,j,prev_sum-1));
	}
	else if(f1 && !f2)
	{
		ans=min(ans,1+find_min(i+1,j,prev_sum+1));
		ans=min(ans,1+find_min(i,j+1,prev_sum-1));
	}
	else if(!f1 && f2)
	{
		ans=min(ans,1+find_min(i,j+1,prev_sum+1));
		ans=min(ans,1+find_min(i+1,j,prev_sum-1));
	}
	else
	{
		ans=min(ans,1+find_min(i,j,prev_sum+1));
		ans=min(ans,1+find_min(i+1,j+1,prev_sum-1));
	}
	
	DP[i][j][prev_sum]=ans;
	
	return DP[i][j][prev_sum];
}

void reverse(int i,int j,int prev_sum)
{
	if(i==n && j==m)
	{
		while(prev_sum>0)
		{
			f_ans+=")";
			prev_sum--;
		}
		return ;
	}

	int ans=DP[i][j][prev_sum];
			
	bool f1= (i<n && s[i]=='(' );
	bool f2= (j<m && t[j]=='(');
	
	if(i==n)
	{
		if(f2)
		{
			if(ans==1+find_min(i,j+1,prev_sum+1))
			{
				f_ans+="(";
				reverse(i,j+1,prev_sum+1);
			}
			else
			{
				f_ans+=")";
				reverse(i,j,prev_sum-1);
			}
		}
		else
		{
			if(ans==1+find_min(i,j,prev_sum+1))
			{
				f_ans+="(";
				reverse(i,j,prev_sum+1);
			}
			else
			{
				f_ans+=")";
				reverse(i,j+1,prev_sum-1);
			}
		}
	}
	else if(j==m)
	{
		if(f1)
		{
			if(ans==1+find_min(i+1,j,prev_sum+1))
			{
				f_ans+="(";
				reverse(i+1,j,prev_sum+1);
			}
			else
			{
				f_ans+=")";
				reverse(i,j,prev_sum-1);
			}
		}
		else
		{
			if(ans==1+find_min(i,j,prev_sum+1))
			{
				f_ans+="(";
				reverse(i,j,prev_sum+1);
			}
			else
			{
				f_ans+=")";
				reverse(i+1,j,prev_sum-1);
			}
		}
	}
	else if(f1 && f2)
	{
		if(ans==1+find_min(i+1,j+1,prev_sum+1))
		{
			f_ans+="(";
			reverse(i+1,j+1,prev_sum+1);
		}
		else
		{
			f_ans+=")";
			reverse(i,j,prev_sum-1);
		}
	}
	else if(f1 && !f2)
	{
		if(ans==1+find_min(i+1,j,prev_sum+1))
		{
			f_ans+="(";
			reverse(i+1,j,prev_sum+1);
		}
		else
		{
			f_ans+=")";
			reverse(i,j+1,prev_sum-1);
		}
	}
	else if(!f1 && f2)
	{
		if(ans==1+find_min(i,j+1,prev_sum+1))
		{
			f_ans+="(";
			reverse(i,j+1,prev_sum+1);
		}
		else
		{
			f_ans+=")";
			reverse(i+1,j,prev_sum-1);
		}
	}
	else
	{
		if(ans==1+find_min(i,j,prev_sum+1))
		{
			f_ans+="(";
			reverse(i,j,prev_sum+1);
		}
		else
		{
			f_ans+=")";
			reverse(i+1,j+1,prev_sum-1);
		}
	}	
}
int main()
{
	cin>>s>>t;
	n=s.size();
	m=t.size();	
	
	memset(DP,-1,sizeof(DP));
	
	find_min(0,0,0);
	reverse(0,0,0);
	
	cout<<f_ans<<endl;
	return 0;
}
