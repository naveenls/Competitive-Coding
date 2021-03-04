#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector<long long> a,b;
	
	long long sum=0;
	
	int w;
	long long c;
	for(int i=0;i<n;i++)
	{
		cin>>w>>c;
		
		if(w==2)
		{
			a.push_back(c);
		}
		else
		{
			b.push_back(c);
		}
		sum+=w;
	}
	
	sort(a.begin(),a.end(),greater<long long> ());
	sort(b.begin(),b.end(),greater<long long> ());
	
	long long DP[sum+1];
	int count[sum+1][2];
	
	DP[0]=0;
	count[0][0]=0;
	count[0][1]=0;
	
	for(int i=1;i<=sum;i++)
	{
		DP[i]=0;
		
		long long val1=0,val2=0;
		
		if(i>1)
		{
			if(count[i-2][1]<a.size())
			{
				val1=DP[i-2]+a[count[i-2][1]];
			}
		}
		
		if(count[i-1][0]<b.size())
		{
			val2=DP[i-1]+b[count[i-1][0]];
		}
		
		if(val1==0 && val2 ==0)
		{
			DP[i]=DP[i-1];
			count[i][0]=count[i-1][0];
			count[i][1]=count[i-1][1];
		}
		
		if(val2>val1)
		{
			DP[i]=val2;
			count[i][0]=count[i-1][0]+1;
			count[i][1]=count[i-1][1];
		}
		else
		{
			DP[i]=val1;
			count[i][0]=count[i-2][0];
			count[i][1]=count[i-2][1]+1;
		}
	}
	for(int i=1;i<=sum;i++)
	{
		cout<<DP[i]<<' ';
	}
	return 0;
}
