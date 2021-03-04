#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,p;
	cin>>n>>k>>p;
	
	vector<int> odd,even;
	
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a%2)
			odd.push_back(a);
		else
			even.push_back(a);
	}
	
	if(k-p>odd.size())
	{
		cout<<"NO"<<endl;
	}
	else
	{
		int rem=odd.size()-(k-p);
		
		if(rem%2)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			if(even.size() + rem/2>=p)
			{
				cout<<"YES"<<endl;
				
				vector<int> ans[k];
				for(int i=0;i<k-p;i++)
				{
					ans[i].push_back(odd[i]);
				}
				
				if(p==0)
				{
					vector<int> ans[k];
					for(int i=0;i<k-p;i++)
					{
						ans[i].push_back(odd[i]);
					}
				
					int start=0;
				
					for(int i=0;i<even.size();i++,start++)
					{
						if(start==k)
							start=0;
						
						ans[start].push_back(even[i]);
					}
						
					start=0;
					
					for(int i=k-p;i<odd.size();i+=2)
					{
						if(start==k)
							start=0;
						
						ans[start].push_back(odd[i]);
						ans[start].push_back(odd[i+1]);
						
						start++;
					}
					
					for(int i=0;i<k;i++)
					{
						cout<<ans[i].size()<<' ';
						for(auto ele:ans[i])
							cout<<ele<<' ';
						
						cout<<endl;
					}
					return 0;
				}
				
				int start=k-p;
				
				for(int i=0;i<even.size();i++,start++)
				{
					if(start==k)
						start=k-p;
					
					ans[start].push_back(even[i]);
				}
						
				for(int i=k-p;i<odd.size();i+=2)
				{
					if(start==k)
						start=k-p;
					
					ans[start].push_back(odd[i]);
					ans[start].push_back(odd[i+1]);
					
					start++;
				}
				
				for(int i=0;i<k;i++)
				{
					cout<<ans[i].size()<<' ';
					for(auto ele:ans[i])
						cout<<ele<<' ';
						
					cout<<endl;
				}
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
