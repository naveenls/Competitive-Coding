#include<bits/stdc++.h>
using namespace std;
const int maxSum=9*4000+1;

int main()
{
	int a;
	string s;
	
	cin>>a;
	cin>>s;
	
	long long arr[maxSum]={0};
	for(int i=0;i<s.size();i++)
	{
		int sum=0;
		for(int j=i;j<s.size();j++)
		{
			sum+=(s[j]-'0');
			//cout<<sum<<endl;
			arr[sum]++;
		}
	}
	
	long long ans=0;
	
    for (int i = 1; i * i <= a; i++) 
	    if (a % i == 0) 
	    {
	    	int t1=i;
	    	int t2=a/i;
	    	if(t1>maxSum || t2> maxSum)
	    		continue;
	    	if(t1!=t2)
	    		ans+=arr[t1]*arr[t2]*2;
	    	else
	    		ans+=arr[t1]*arr[t2];
		}
	
	if(a==0)
	{
		for(int i=1;i<maxSum;i++)
		{
			ans+=arr[0]*arr[i]*2;
		}
		ans+=arr[0]*arr[0];
	}
	cout<<ans<<endl;
	return 0;
}
