#include<bits/stdc++.h>
using namespace std;
long long n;

long long find_sum(long long start,long long end,long long d_start,long long n)
{
	long long cnt1=end-start;
	long long cnt2=end-d_start;
	
	long long val1=start*cnt1 + cnt1*(cnt1-1)/2;
	long long val2=d_start*cnt2 + cnt2*(cnt2-1)/2;
	
	long long temp=end*(n-cnt1-cnt2);
	
	return val1+val2+temp;
}
long long count(long long dist,long long x,long long y)
{
	long long ans=0;
	
	long long x_top=max(1LL,x-dist);
	long long x_down=min(n,x+dist);
	
	long long l_end=min(dist+1,y);
	long long u_start=min(y,max(1LL,2-x+dist));
	long long d_start=min(y,max(1LL,(x+dist)-n+1));
	
	//cout<<dist<<' '<<x_top<<' '<<x_down<<' '<<l_end<<endl;
	//cout<<"HI"<<u_start<<' '<<l_end<<' '<<d_start<<' '<<x_down-x_top+1<<endl;
	ans=find_sum(u_start,l_end,d_start,x_down-x_top+1);
	//cout<<dist<<' '<<ans<<endl;
	x_top=max(1LL,x-dist);
	x_down=min(n,x+dist);
	
	l_end=min(dist,n-y);
	
	u_start=min(n-y,max(0LL,1-(x-dist)));
	d_start=min(n-y,max(0LL,(x+dist)-n));
	
	//cout<<"HI"<<u_start<<' '<<l_end<<' '<<d_start<<' '<<x_down-x_top+1<<endl;
	ans+=find_sum(u_start,l_end,d_start,x_down-x_top+1);
	//cout<<ans<<endl;
	return ans;
}
int main()
{
	cin>>n;
	long long x,y;
	
	cin>>x>>y;
	long long c;
	cin>>c;
	
	long long l=0,r=2*n-2;
	long long ans;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		//cout<<mid<<' '<<count(mid,x,y)<<endl;
		if(count(mid,x,y)<c)
		{
			l=mid+1;
		}
		else
		{
			ans=mid;
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
