#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int n,k,d;
const int maxN=1000;
int ans[maxN][maxN];
bool flag=0;
void generate(int i,int value[])
{
	if(i==d)
	{
		for(int j=0;j<d;j++)
		{
			ans[cnt][j]=value[j];
		}
		cnt++;
		if(cnt==n)
			flag=1;
		return ;
	}
	for(int j=1;j<=k;j++)
	{
		if(!flag)
		{
			value[i]=j;
			generate(i+1,value);
		}
	}
}
int main()
{
	cin>>n>>k>>d;
	int value[d];
	generate(0,value);
	if(flag)
	{
		for(int i=0;i<d;i++)
		{
			string s="";
			for(int j=0;j<n;j++)
			{
				s+=(to_string(ans[j][i])+" ");
			}
			cout<<s<<endl;
		}
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}
