#include<bits/stdc++.h>
using namespace std;

void generate(int i,vector<int> &poss,int val[10])
{
	if(i==10)
	{
		int ans=0;
		for(int i=0;i<10;i++)
		{
			ans=ans*10+val[i];
		}
		if(ans)
			poss.push_back(ans);
	}
	else
	{
		val[i]=0;
		generate(i+1,poss,val);
		val[i]=1;
		generate(i+1,poss,val);
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> pos;
	int val[10];
	generate(0,pos,val);
	int ind=upper_bound(pos.begin(),pos.end(),n)-pos.begin();
	cout<<ind<<endl;
	return 0;
}
