#include<bits/stdc++.h>
using namespace std;

void invert(int l,int r,string &str)
{
	int s=l,e=r;
	while(s<e)
	{
		char temp=str[s];
		str[s]=str[e];
		str[e]=temp;
		
		s++;
		e--;
	}
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		string s;
		cin>>s;
		
		k--;
		
		vector<pair<int,int> > ans;
		
		int i=0;
		while(k--)
		{
			if(s[i]==')')
			{
				for(int j=i+1;j<n;j++)
				{
					if(s[j]=='(')
					{
						ans.push_back({i,j});
						invert(i,j,s);
						break;
					}
				}
			}
			i++;
			if(s[i]=='(')
			{
				for(int j=i+1;j<n;j++)
				{
					if(s[j]==')')
					{
						ans.push_back({i,j});
						invert(i,j,s);
						break;
					}
				}
			}
			//cout<<s<<endl;
			i++;
		}
		
		bool flag=0;
		
		int len=(n-i)/2;
		
		for(int j=i;j<len+i;j++)
		{
			if(s[j]==')')
			{
				for(int k=j+1;k<n;k++)
				{
					if(s[k]=='(')
					{
						ans.push_back({j,k});
						invert(j,k,s);
						break;
					}
				}
			}
		}
		//cout<<s<<endl;
		cout<<ans.size()<<endl;
		for(auto ele:ans)
		{
			cout<<ele.first+1<<' '<<ele.second+1<<endl;
		}
		
	}
	return 0;
}
