#include<bits/stdc++.h>
using namespace std;

int main()
{
	long double a,b,m;
	cin>>a>>b>>m;
	
	long double vx,vy,vz;
	cin>>vx>>vy>>vz;
	
	vy=abs(vy);
	
	long double ans_x,ans_z;
	
	long double time=m/vy;
		
	if(vz==0.0)
	{
		ans_z=0;
	}
	
	else{
		long double time2=b/vz;
	
		long long n_z=floor(time/time2);
		
		long double t_r=(time-time2*(long double) n_z);
		
		if(n_z%2)
		{
			ans_z=b-vz*t_r;
		}
		else
			ans_z=vz*t_r;
	}
	
	if(vx==0.0)
	{
		ans_x=a/2;

	}
	else
	{
		long double time1=a/(2*abs(vx));
		if(time1>=time)
		{
				ans_x=a/2+time*vx;

		}
		else
		{
			time-=time1;
			time1*=2;
			
			long long n_x=time/time1;
			
			long double t_rem=(time-time1*(long double) n_x);
			
			if(n_x%2)
			{
				if(vx>0)
				{
					ans_x=t_rem*vx;
				}
				else
				{
					ans_x=a-t_rem*abs(vx);
				}
			}
			else
			{
				if(vx>0)
				{
					ans_x=a-t_rem*vx;
				}
				else
				{
					ans_x=t_rem*abs(vx);
				}
			}
		}
	}
	cout<<fixed<<setprecision(10)<<abs(ans_x)<<' '<<abs(ans_z)<<endl;
	return 0;
}
