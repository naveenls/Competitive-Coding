#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
		
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		int cnt[m] = {0};
		int a;
		
		for(int i=0;i<n;i++)
		{
			cin>>a;
			cnt[a%m]++;
		}
		
		int ans = 0;
		
		for(int i=1;i<m;i++)
		{
			if(cnt[i]>cnt[m-i])
			{
				cnt[i] -= (cnt[m-i]+1);
				ans += (1+cnt[i]);
			}
			else if(cnt[m-i]>cnt[i])
			{
				cnt[m-i] -= (cnt[i]+1);
				ans += (1+cnt[m-i]);
			}
			else if(cnt[i]){
				ans++;
			}
			cnt[i] = 0;
			cnt[m-i] = 0;
		}
		
		if(cnt[0])
			ans++;
		
		cout<<ans<<endl;
	}
	return 0;
}
