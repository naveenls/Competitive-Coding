#include<bits/stdc++.h>
using namespace std;

vector<int> basis;
int sz=0;

void insertVector(int mask,int k) 
{
	for (int i = 0; i < k; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			
			return;
		}

		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		sz=0;
		
		int k,m;
		cin>>k>>m;
		
		basis.resize(k);
		
		int x;
		for(int i=0;i<m;i++)
		{
			cin>>x;
			insertVector(x,k);	
		}
		
		int val1=(1<<k);
		int val2=(1<<sz);
		
		cout<<val1/val2<<endl;
	}
	return 0;
}
