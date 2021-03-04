#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		long double g[n],a[n],b[n];
		
		long double sum1=0;
		long double sum2=0;
		
		for(int i=0;i<n;i++)
		{
			cin>>g[i]>>a[i]>>b[i];
			sum1+=(g[i]*b[i]/(a[i]+b[i]));
			sum2+=(g[i]*a[i]/(a[i]+b[i]));
		}
		cout<<fixed<<setprecision(10)<<sum1<<' '<<sum2<<endl;
	}
	return 0;
}
