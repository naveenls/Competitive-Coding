#include<bits/stdc++.h>
using namespace std;

int main()
{
	int v;
	cin>>v;
	int arr[9];
	for(int i=0;i<9;i++)
	{
		cin>>arr[i];
	}
	int value[9];
	for(int i=0;i<9;i++)
	{
		value[i]=v/arr[i];
	}
	int mx=0;
	string ans="";
	for(int i=0;i<9;i++)
	{
	    mx=max(mx,value[i]);
	}
	if(mx==0)
		cout<<-1;
	else
    {
        for(int i=0;i<9;i++)
    	{
            if(value[i]==mx)
    		{
    			string te="";
    			for(int cnt=0;cnt<value[i];cnt++)
    			{
    				te+=to_string(i+1);
    			}
    			int rem=v%arr[i];
    			int k=0;
    			for(int j=8;j>=i+1;j--)
    			{
    				int temp=arr[j]-arr[i];
    				while(rem>=temp && temp>0)
    				{
    					rem-=temp;
    					te[k]=(char)('1'+j);
    					k++;
    				}
    			}
    			ans=max(te,ans);
    		}
    	}
    	cout<<ans;
    }
	
	return 0;
	
}
