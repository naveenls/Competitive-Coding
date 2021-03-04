#include<bits/stdc++.h>
using namespace std;

void solve1()
{
	int n,q;
	cin>>n>>q;
	
	int diff[n+1] = {0};	
	int l,r;
	
	while(q--)
	{
		cin>>l>>r;
		l--,r--;
		
		diff[l]++;
		diff[r+1]--;
	}
	
	int t_sum = 0;
	
	for(int i=0;i<n;i++)
	{
		t_sum += diff[i];
		
		if(t_sum>0)
			cout<<i+1<<' ';
		else
			cout<<1<<' ';
	}
	cout<<endl;
}

void solve2()
{
	int n,q;
	cin>>n>>q;
		
	int toAdd[n] = {0};
	vector<int> toDel[n];
	
	int toAdd1[n] = {0};
	vector<int> toDel1[n];
	
	int l,r;
	for(int i=0;i<q;i++)
	{
		cin>>l>>r;
		l--,r--;
		
		toAdd[l]++;
		if(r+1<n)
			toDel[r+1].push_back(l);
		
		if(l)
			toDel1[l-1].push_back(r);
		toAdd1[r]++;
	}
	
	int left[n];
	int right[n];
	
	memset(left,-1,sizeof(left));
	memset(right,-1,sizeof(right));
	
	multiset<int> ms;
	for(int i=0;i<n;i++)
	{
		for(auto l:toDel[i])
			ms.erase(ms.find(l));
		
		while(toAdd[i]--)
			ms.insert(i);
		
		if(ms.size())
			left[i] = *ms.rbegin();
	}
	ms.clear();
	
	for(int i=n-1;i>=0;i--)
	{
		for(auto r:toDel1[i])
			ms.erase(ms.find(r));
		
		while(toAdd1[i]--)
			ms.insert(i);
		
		if(ms.size())
			right[i] = *ms.begin();
	}
	
	map<pair<int,int> ,vector<int> > mp;
	for(int i=0;i<n;i++){
		if(left[i] != -1)
			mp[{left[i],right[i]}].push_back(i+1);
	}
	
	int ans[n];
	for(int i=0;i<n;i++)
	{
		if(left[i]!=-1)
		{
			ans[i] = mp[{left[i],right[i]}].back();
			mp[{left[i],right[i]}].pop_back();
		}
		else
			ans[i] = n;
	}
	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,p;
	cin>>t>>p;
	
	if(p==0){
		while(t--)
			solve1();
	}
	else{
		while(t--)
			solve2();
	}
	return 0;
}
