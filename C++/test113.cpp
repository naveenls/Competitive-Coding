#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxN=3000;
//set<int> adjIN[maxN];
set<int> adjOUT[maxN];

int main()
{
	cin>>n>>m;
	
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--,b--;
		adjOUT[a].insert(b);
	//	adjIN[b].insert(a);
	}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		map<int,long long> neigh;
		for(auto ele:adjOUT[i])
		{
			for(auto n:adjOUT[ele])
			{
				if(n!=i)
				{
					neigh[n]++;
				}
			}
		}
		for(auto itr=neigh.begin();itr!=neigh.end();++itr)
		{
			ans+=(itr->second)*(itr->second-1)/2;
		}
	}

	cout<<ans<<endl;
	return 0;
}
