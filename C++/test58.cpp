#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n+3];
	arr[1]=0;
	long long sum=0;
	int ind=2;
	int inc[n+3]={0};
	
	int a,b,x;
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a==1)
		{
			cin>>b>>x;
			inc[b]+=x;
			sum+=b*x;
		}
		else if(a==2)
		{
			cin>>b;
			arr[ind]=b;
			ind++;
			sum+=b;
		}
		else
		{
			ind--;
			sum-=(arr[ind]+inc[ind]);
			inc[ind-1]+=inc[ind];
			inc[ind]=0;
		}
		long double ans=(long double)sum/(ind-1);
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}
	return 0;
}
