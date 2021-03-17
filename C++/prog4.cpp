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
		
		int t[n];
		long long s[n];
		
		for(int i=0;i<n;i++)
			cin>>t[i];
		
		for(int i=0;i<n;i++)
			cin>>s[i];
		
		long long max_end[n] = {0};
		
		for(int i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
				if(t[i] != t[j])
				{
					long long m1 = max_end[i];
					long long m2 = max_end[j];
					
					max_end[i] = max(m1, m2 + abs(s[i]-s[j]));
					max_end[j] = max(m2, m1 + abs(s[i]-s[j]));	
				}
		}
				
		cout<<*max_element(max_end,max_end+n)<<endl;
	}
	return 0;
}
