#include<bits/stdc++.h>
using namespace std;

const int N=600;
int n;

int break_point[2*N+1][N+1];
char ans[2*N];

void reverse(int start,int i,int l)
{
	if(l==0)
	{
		return;
	}
	
	
	int k=break_point[l][i];
	
	cout<<start<<' '<<i<<' '<<l	<<' '<<k<<endl;
	
	ans[start]='(';
	ans[start+k]=')';
	
	reverse(start+1,i+1,k-1);
	reverse(start+k+1,i+k/2,l-k+1);
}
int main()
{
	int n;
	cin>>n;
	
	int L[n],R[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>L[i]>>R[i];
	}
	
	bool DP[2*n+1][n+1];
	
	memset(DP,0,sizeof(DP));
	
	for(int i=0;i<n;i++)
	{
		DP[0][i]=true;
		
		int j=i;
		
		if(L[i]==1)
		{
			DP[2][i]=true;
			break_point[2][i]=1;
		}
	}
	DP[0][n]=true;
	
	for(int l=4;l<=2*n;l+=2)
	{
		for(int i=0;i<n;i++)
		{
			int j=i+l/2-1;
			if(j>=n)
				break;
				
			for(int k=L[i];k<=R[i];k++)
			{
				if(k%2)
				{
					int l1=k-1;
					
					if(l1==0)
					{
						DP[l][i] |= DP[l-2][i+1];
					}
					else
					{
						DP[l][i] |= (DP[l1][i+1] &&  DP[l-l1][i+k/2]);
					}
					
					if(DP[l][i])
					{
						break_point[l][i]=k;
						break;
					}
				}
			}
		}
	}
	
	if(!DP[2*n][0])
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else
	{
		reverse(0,0,2*n);
		
		for(int i=0;i<2*n;i++)
		{
			cout<<ans[i];
		}
	}
	return 0;
}
