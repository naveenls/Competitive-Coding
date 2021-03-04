#include<bits/stdc++.h>
using namespace std;

const int maxN=131072+1;

int cnt[maxN][26];

int find_min(int s,int e,int j)
{
	if(s==e)
	{
		return 1-(cnt[s][j]-cnt[s-1][j]);
	}
	
	int mid=(s+e)/2;
	
	int len=(e-s+1)/2;
	
	int cnt1=cnt[mid][j]-cnt[s-1][j];
	int cnt2=cnt[e][j]-cnt[mid][j];
	
	//cout<<len<<' '<<cnt1<<' '<<cnt2<<endl;
	return min(len-cnt1+find_min(mid+1,e,j+1),len-cnt2+find_min(s,mid,j+1));
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<26;j++)
			{
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cnt[i][s[i-1]-'a']=1;
			for(int j=0;j<26;j++)
			{
				cnt[i][j]+=cnt[i-1][j];
			}
		}
		
		cout<<find_min(1,n,0)<<endl;
	}
	return 0;
}
