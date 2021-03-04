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
		
		string arr[n];
		
		int a=0,b=0,c=0,d=0;
		
		map<string,int> s1,s2,s3,s4;
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			
			int f1=arr[i][0]-'0';
			int f2=arr[i][arr[i].size()-1]-'0';
			
			if(f1 && f2)
			{
				s4[arr[i]]=i;
				d++;
			}
			else if(f1 && !f2)
			{
				s3[arr[i]]=i;
				c++;
			}
			else if(!f1 && f2)
			{
				s2[arr[i]]=i;
				b++;
			}
			else
			{
				a++;
				s1[arr[i]]=i;
			}
		}
		
		if(b==0 && c==0 && a && d)
		{
			cout<<-1<<endl;
		}
		else if(b==c || b==c+1 || c==b+1)
		{
			cout<<0<<endl;
		}
		else
		{
			int diff=abs(b-c);
			diff/=2;
			
			vector<int> ans;
			
			if(b>c)
			{
				auto itr=s2.begin();
				
				while(diff && itr!=s2.end())
				{
					string temp=itr->first;
					
					reverse(temp.begin(),temp.end());
					//cout<<temp<<endl;
					
					if(s3.find(temp)==s3.end())
					{
						diff--;
						ans.push_back(itr->second);	
					}
					itr++;	
				}	
				if(diff)
				{
					cout<<-1<<endl;
				}
				
				else
				{
					cout<<ans.size()<<endl;
					for(auto ele:ans)
					{
						cout<<ele+1<<' ';
					}
					cout<<endl;
				}
			}
			else
			{
				auto itr=s3.begin();
				
				while(diff && itr!=s3.end())
				{
					string temp=itr->first;
					
					reverse(temp.begin(),temp.end());
					
					if(s2.find(temp)==s2.end())
					{
						diff--;
						ans.push_back(itr->second);	
					}
					itr++;	
				}	
				if(diff)
				{
					cout<<-1<<endl;
				}
				else
				{
					cout<<ans.size()<<endl;
					for(auto ele:ans)
					{
						cout<<ele+1<<' ';
					}
					cout<<endl;
				}
			}
		}
	}
	return 0;
}
