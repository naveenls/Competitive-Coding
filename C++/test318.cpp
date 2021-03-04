#include<bits/stdc++.h>
using namespace std;

long long a,b;
const int maxN=1e6;

long long arr[maxN];
int n;

set<long long> factors;

void factorize(long long a)
{
	for(long long i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			factors.insert(i);
			while(a%i==0)
				a/=i;
		}
	}
	
	if(a>1)
		factors.insert(a);
}

long long find_ans(long long _a)
{
	int type[n];
	for(int i=0;i<n;i++)
	{
		if(arr[i]%_a==0)
		{
			type[i]=0;
		}
		else if((arr[i]+1)%_a==0 || (arr[i]-1)%_a==0)
		{
			type[i]=1;
		}
		else
		{
			type[i]=2;
		}
	}

	long long DP[n][3];
	
	if(type[0]==0)
	{
		DP[0][0]=0;
		DP[0][1]=a;
	}
	else if(type[0]==1)
	{
		DP[0][0]=b;
		DP[0][1]=a;
	}
	else
	{
		DP[0][0]=1e18;
		DP[0][1]=a;
	}
	
	DP[0][2]=1e18;
	
	for(int i=1;i<n;i++)
	{
		if(type[i]==0)
		{
			DP[i][0]=DP[i-1][0];
			DP[i][1]=a+min(DP[i-1][0],DP[i-1][1]);
			DP[i][2]=min(DP[i-1][1],DP[i-1][2]);
		}
		else if(type[i]==1)
		{
			DP[i][0]=DP[i-1][0]+b;
			DP[i][1]=a+min(DP[i-1][0],DP[i-1][1]);
			DP[i][2]=b+min(DP[i-1][1],DP[i-1][2]);
		}
		else
		{
			DP[i][0]=1e18;
			DP[i][1]=a+min(DP[i-1][0],DP[i-1][1]);
			DP[i][2]=1e18;
		}
	}
	long long mi=min(DP[n-1][0],DP[n-1][1]);
	mi=min(mi,DP[n-1][2]);
	
	return mi;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>a>>b;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	factorize(arr[0]-1);
	factorize(arr[0]);
	factorize(arr[0]+1);
	
	factorize(arr[n-1]-1);
	factorize(arr[n-1]);
	factorize(arr[n-1]+1);
	
	long long mi=1e18;
	
	for(auto ele:factors)
	{
		//cout<<ele<<endl;
		mi=min(find_ans(ele),mi);
	}
	cout<<mi<<endl;
	return 0;
}
