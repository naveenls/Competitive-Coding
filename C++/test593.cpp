#include<bits/stdc++.h>
using namespace std;

int find_k(int x)
{
	int k=0;
	
	while((1<<k)<=x)
		k++;
	
	return k-1;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	int n = s1.size();
	int k = 22;
	
	int c[n][22];
	
	for(int i=0;i<n;i++){
		c[i][0] = s1[i] - 'a';	
	}
	
	for(int j=1;j<k;j++)
	{
		vector<pair<pair<int,int>, int> > v;
		 
		for(int i=0;(i+(1<<j))<=n; i++){
			v.push_back({{c[i][j-1], c[i+(1<<(j-1))][j-1]},i});
		}
		
		if(v.size())
		{
			int cla = 0;
			sort(v.begin(), v.end());
			
			c[v[0].second][j] = cla;
			
			for(int i=1;i<v.size();i++)
			{
				if(v[i].first != v[i-1].first)
					cla++;
					
				c[v[i].second][j] = cla;
			}
		}
	}
	
	int a=0;
	int b=0;
	
	for(int i=0;i<s2.size();i++)
	{
		a += (s2[i]=='0');
		b += (s2[i]=='1');
	}
	
	if(a == 0)
	{
		cout<<"helo"<<endl;
		cout<<s1.substr(0,n/b)<<endl;
		return 0;
	}
	
	if(b == 0)
	{
		cout<<s1.substr(0,n/a)<<endl;
		cout<<"helo"<<endl;	
		return 0;	
	}
		
	for(int x=1;x<=n;x++)
	{
		if(n-a*x > 0 && (n-a*x)%b == 0)
		{
			int y = (n-a*x)/b;
			
			string sa="Null";
			string sb="Null";

			int ind = 0;
			bool flag = 0;
			for(int i=0;i<s2.size();i++)
			{
				if(s2[i] == '1')
				{
					string curr = s1.substr(ind,y);	
									
					if(sa == "Null")
						sa = curr;
					else if(sa != curr)
					{
						flag = 1;
						break;
					}
					
					ind += y;
				}
				else
				{
					string curr = s1.substr(ind,x);		
					
					if(sb == "Null")
						sb = curr;
					else if(sb != curr)
					{
						flag = 1;
						break;
					}
					
					ind += x;
				}
			}
			
			if(!flag)
			{
				cout<<sb<<endl;
				cout<<sa<<endl;
				return 0;
			}
		}
	}
	
	return 0;
}
