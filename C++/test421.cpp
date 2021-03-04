#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	long long ans=0;
	
	long long temp;
	
	vector<int> prev;
	
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		ans+=temp/2;
		
		if(temp%2)
		{
			if(prev.size()==0)
			{
				prev.push_back(i);
			}
			else
			{
				int end=prev.size()-1;
				
				if((i-prev[end])%2)
				{
					ans++;
					prev.pop_back();
				}
				else
				{
					prev.push_back(i);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
