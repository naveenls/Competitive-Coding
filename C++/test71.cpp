#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a<b)
    	swap(a,b);
    for(int i=1;i<b;i++)
    {
    	int j=sqrt(b*b-i*i);
    	if(i*i+j*j==b*b)
    	{
    		int x=-j;
    		int y=i;
    		if((a*x)%b==0 && (a*y)%b==0)
    		{
    			x=(a*x/b);
    			y=(a*y/b);
    			if((x!=i) && (y!=j))
    			{
	    			cout<<"YES"<<endl;
	    			cout<<0<<' '<<0<<endl;
	    			cout<<i<<' '<<j<<endl;
	    			cout<<x<<' '<<y<<endl;
	    			return 0;
    			}
			}
		}
	}
	cout<<"NO"<<endl;
    return 0;
}

