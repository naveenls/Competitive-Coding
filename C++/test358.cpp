#include<bits/stdc++.h>
using namespace std;

#define MAXN   1000001 

int spf[MAXN]; 

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 

    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

int last_occ[MAXN];
vector<int> factor[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	sieve();
	int a;
	for(int i=1;i<=MAXN;i++)
	{
		a=i;
		while(a>1)
		{
			int sp=spf[a];
			factor[i].push_back(sp);
			
			while(a%sp==0)
				a/=sp;
		}
	}
		
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		set<int> s;
		
		int ma=0;
		int prev=0;
		
		for(int i=0;i<n;i++)
		{
			int max_i=-1;
			
			for(auto ele:factor[arr[i]])
			{
				if(s.find(ele)==s.end())
				{
					s.insert(ele);
				}
				else
				{
					max_i=max(max_i,last_occ[ele]);
				}
				last_occ[ele]=i;
			}
			int aa=min(prev+1,i-max_i);
			
			ma=max(ma,aa);
			prev=aa;
		}
		
		if(ma==1)
			ma=-1;
			
		cout<<ma<<endl;
	}
}
