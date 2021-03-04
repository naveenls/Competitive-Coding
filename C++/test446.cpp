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
		
		int l[n],r[n],k[n];
		
		map<int,vector<int> > mp,mp1;
		
		long long ans=0;
		
		for(int i=0;i<n;i++)
		{
			cin>>k[i]>>l[i]>>r[i];	
			ans+=min(r[i],l[i]);

			if(l[i]>=r[i])
				mp[k[i]].push_back(i);
			else
				mp1[n-k[i]].push_back(i);
		}

		multiset<int> inserted;
		
		for(int j=1;j<=n;j++)
		{
			for(auto ele:mp[j])
			{
				inserted.insert(l[ele]-r[ele]);
				ans+=l[ele]-r[ele];
			}
			
			while(inserted.size()>j)
			{
				ans-=*inserted.begin();
				inserted.erase(inserted.begin());
			}
		}
		
		inserted.clear();
		
		for(int j=1;j<=n;j++)
		{
			for(auto ele:mp1[j])
			{
				inserted.insert(r[ele]-l[ele]);
				ans+=r[ele]-l[ele];
			}
			
			while(inserted.size()>j)
			{
				ans-=*inserted.begin();
				inserted.erase(inserted.begin());
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
