#include<bits/stdc++.h>
using namespace std;


struct Line {
	mutable int k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(int x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const int inf = LLONG_MAX;
	int div(int a, int b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(int k, int m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	int query(int x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	
	long long arr[n+1];
	arr[1]=0;
	for(int i=2;i<=n;i++)
	{
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	
	int h[m];
	long long t[m];
	
	for(int i=0;i<m;i++)
	{
		cin>>h[i]>>t[i];
	}
	
	long long arr[m+1];
	for(int i=0;i<m;i++)
	{
		long long start=t[i]-arr[h[i]];
		arr[i+1]=start;
	}
	
	sort(arr+1,arr+m+1);

	long long sum[m+1];
	sum[0]=0;
	for(int i=1;i<=m;i++)
	{
		sum[i]=arr[i]+sum[i-1];
	}
	
	long long DP[p+1][m+1];
	
	for(int i=0;i<=p;i++)
		DP[i][0]=0;
		
	for(int i=1;i<=m;i++)
	{
		DP[1][i]=arr[i]*i-s[i];
	}
	
	for(int i=2;i<=p;i++)
	{
		LineContainer L;
		for(int j=1;j<=m;i++)
		{
			L.add(DP[i-1][j-1]+sum[j-1],-(j-1));
			DP[i][j]=L.query(arr[j]) +arr[j]*j -s[j];
		}
	}
	cout<<DP[p][m]<<endl;
	return 0;
}
