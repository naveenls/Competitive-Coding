#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) c.begin(),c.end()

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		multiset<int> mset;
		
		int a;
		rep(i,n)
		{
			cin>>a;
			mset.insert(a);
		}
		
		int ma=0;
		
		for(int s=1;s<=2*n;s++)
		{
			multiset<int> temp=mset;
			
			int cnt=0;
			while(temp.size())
			{
				int val=*temp.begin();
				
				temp.erase(temp.begin());
				
				if(temp.count(s-val))
				{
					temp.erase(temp.find(s-val));
					
					//cout<<val<<' '<<s-val<<"hi"<<endl;
					cnt++;		
				}
			}
			
			if(cnt>ma)
			{
				ma=cnt;
				
				//cout<<ma<<' '<<s<<endl;
			}
		}
		cout<<ma<<endl;
	}
}
