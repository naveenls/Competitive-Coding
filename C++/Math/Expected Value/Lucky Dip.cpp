#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	
	vector<long double> arr(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
		
	sort(arr.begin(),arr.end());
	
	long double pref_sum[n];
	pref_sum[0]=arr[0];
	
	for(int i=1;i<n;i++)
		pref_sum[i]=pref_sum[i-1]+arr[i];
	
	long double N=n;
	
	long double DP[k];
	
	DP[k]=(pref_sum[n-1])/N;
	
	
	for(int i=k-1;i>=0;i--)
	{
		
		int ind=lower_bound(arr.begin(),arr.end(),DP[i+1])-arr.begin();
				
		DP[i]=DP[i+1]*ind/N;
		
		if(ind)
		{
			DP[i]+=(pref_sum[n-1]-pref_sum[ind-1])/N;
		}
		else
		{
			DP[i]+=pref_sum[n-1]/N;
		}
	}
	
	cout<<fixed<<setprecision(10)<<DP[0]<<endl;
}
int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
	    cout<<"Case #"<<i<<": ";
	    solve();
	}
	return 0;
}
