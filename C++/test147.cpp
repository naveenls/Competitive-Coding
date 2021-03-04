#include<bits/stdc++.h>
using namespace std;

int DP[100][100][100];
vector<int> dir[100][100][100];

string s1,s2,v;
int n,m,p;

int find_max(int i,int j,int k)
{
	if(i<0 || j<0)
		return 0;
	
	if(DP[i][j][k]!=-1)
		return DP[i][j][k];
		
	DP[i][j][k]=0;
	
	if(s1[i]==s2[j])
	{
		if(s1[i]==v[k] && k==0)
		{
			DP[i][j][k]=max(find_max(i-1,j,k),find_max(i,j-1,k));
			if(DP[i][j][k]==find_max(i-1,j,k))
			{
				dir[i][j][k]={-1,0,0};
			}
			else
			{
				dir[i][j][k]={0,-1,0};;
			}
		}
		else if(s1[i]==v[k] && k!=0)
		{
			DP[i][j][k]=max(find_max(i-1,j-1,k),1+find_max(i-1,j-1,k-1));
			if(DP[i][j][k]==find_max(i-1,j-1,k))
			{
				dir[i][j][k]={-1,-1,0};
			}
			else
			{
				dir[i][j][k]={-1,-1,-1};
			}
		}
		else
		{
			DP[i][j][k]=1+find_max(i-1,j-1,p);
			dir[i][j][k]={-1,-1,101};
		}
	}
	else
	{
		DP[i][j][k]=max(find_max(i-1,j,k),find_max(i,j-1,k));
		if(DP[i][j][k]==find_max(i-1,j,k))
		{
			dir[i][j][k]={-1,0,0};
		}
		else
		{
			dir[i][j][k]={0,-1,0};
		}
	}

	return DP[i][j][k];
}

bool check(vector<int> &v)
{
	if(v[0]==-1 && v[1]==-1 && (v[2]==-1 || v[2]==101) )
		return true;
	else
		return false;
}

int main()
{
	cin>>s1>>s2>>v;
	n=s1.size()-1;
	m=s2.size()-1;
	p=v.size()-1;
	
	memset(DP,-1,sizeof(DP));
	
	find_max(n,m,p);
	
	int p1=n,p2=m,p3=p;
	
	string ans="";
	
	while(p1>=0 && p2>=0)
	{
		if(check(dir[p1][p2][p3]))
		{
			ans.push_back(s1[p1]);
		}
		p1+=dir[p1][p2][p3][0];
		p2+=dir[p1][p2][p3][1];
		p3=min(p,p3+dir[p1][p2][p3][2]);
	}
	reverse(ans.begin(),ans.end());
	if(ans.size()==0)
		cout<<0<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
