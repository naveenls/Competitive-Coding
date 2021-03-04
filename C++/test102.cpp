#include <bits/stdc++.h>
#include <string>
using namespace std;

const int maxN=200;
int n;
vector<int> adj[maxN];
int col[maxN];
int inD[maxN]={0};
queue<int> v[3];

bool check()
{
	return v[0].size() || v[1].size() || v[2].size();	
}
int findMIN(int start)
{
	int ans=0;
	int t[n];
	
	for(int i=0;i<n;i++)
	{
		t[i]=inD[i];
		if(inD[i]==0)
		{
			v[col[i]].push(i);	
		}	
	}
	while(check())
	{
		if(!v[start].size())
		{
			start=(start+1)%3;
			ans++;
			continue;
		}
		
		ans+=v[start].size();
		int temp=v[start].size();
		
		while(temp)
		{
			int ele=v[start].front();
			v[start].pop();
			for(auto ch:adj[ele])
			{
				inD[ch]--;
				
				if(!inD[ch])
				{
					v[col[ch]].push(ch);	
				}
			}
			temp--;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		inD[i]=t[i];
	}
	return ans;
}
int main() {
	cin>>n;
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		col[i]=--a;	
	}
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		while(k)
		{
			cin>>a;
			a--;
			adj[a].push_back(i);
			inD[i]++;
		}
	}
	int ans=min(findMIN(0),findMIN(1));
	cout<<min(ans,findMIN(2))-1<<endl;
	return 0;
}
