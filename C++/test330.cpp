#include<bits/stdc++.h>
using namespace std;

const int maxW=1000+1;

long double DP[maxW][maxW][2];
bool flag[maxW][maxW][2];

long double find_val(long double w,long double b,bool f)
{
	if(w+b==0)
	{
		return 0.0;
	}
	
	if(flag[(int)w][(int)b][f])
		return DP[(int)w][(int)b][f];
		
	long double ans=0;
	
	if(f==0)
	{
		if(w)
		{
			ans+=(w/(w+b));
			//cout<<ans<<endl;	
		}
		if(b)
		{
			ans+=(b/(b+w))*find_val(w,b-1,1);
		}
	}
	else
	{
		if(b)
		{
			if(b-1)
			{
				ans+=(b/(b+w))*((b-1)/(b+w-1))*find_val(w,b-2,0);
			}
			if(w)
			{
				ans+=(b/(b+w))*(w/(b+w-1))*find_val(w-1,b-1,0);
			}
		}
	}
	//cout<<w<<' '<<b<<' '<<f<<' '<<ans<<endl;
	DP[(int)w][(int)b][f]=ans;
	flag[(int)w][(int)b][f]=1;
	
	return ans;
}
int main()
{
	int w,b;
	cin>>w>>b;
	
	memset(flag,0,sizeof(flag));
	
	cout<<fixed<<setprecision(12)<<find_val(w,b,0);
}



