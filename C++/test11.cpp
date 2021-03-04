#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+4;
bool prm[maxN]={0};

void precompute()
{
	for(int i=2;i<maxN;i++)
	{
		int j=2*i;
		while(j<maxN)
		{
			prm[j]=1;
			j+=i;
		}
	}
}
int main()
{
	precompute();
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	//cout<<"hi"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	vector<int> primes;
	for(int i=2;i<maxN;i++)
	{
		//cout<<i<<' '<<arr[i]<<endl;
		if(!prm[i])
		{
			//cout<<i<<endl;
			primes.push_back(i);
		}
	}
	//cout<<"hi"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int ind=lower_bound(primes.begin(),primes.end(),arr[i][j])-primes.begin();
			arr[i][j]=primes[ind]-arr[i][j];
			
		}
	}
	long long mi=LONG_MAX;
	for(int i=0;i<n;i++)
	{
		long long sum=0;
		for(int j=0;j<m;j++)
		{
		    //cout<<arr[i][j]<<' ';
			sum+=(long long)arr[i][j];
		}
		//cout<<endl;
		mi=min(mi,sum);
	}
	
	for(int j=0;j<m;j++)
	{
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=(long long)arr[i][j];
		}
		mi=min(mi,sum);
	}
	cout<<mi<<endl;
	return 0;
	
}
