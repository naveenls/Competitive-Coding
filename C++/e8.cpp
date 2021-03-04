#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v1;
void heapPermutation(int a[], int size, int n) 
{ 

    if (size == 1) 
    { 
    	vector<int> temp;
        for(int i=0;i<n;i++)
        {
        	temp.push_back(a[i]);
		}
		v1.push_back(temp);
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 
  
        if (size%2==1) 
            swap(a[0], a[size-1]); 

        else
            swap(a[i], a[size-1]); 
    } 
} 

void solve()
{
	int n;
	cin>>n;
	
	long double x[n],y[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	long double dir[n][n];
	
	map<long double,vector<pair<int,int> > > mp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(x[j]!=x[i])
					dir[i][j]=(y[j]-y[i])/(x[j]-x[i]);
				else
				 	dir[i][j]=90.03244985;
				 	
				if(mp.find(dir[i][j])!=mp.end())
				{
					mp[dir[i][j]].push_back({i,j});
				}
				else
				{
					vector<pair<int,int> > v;
					v.push_back({i,j});
					mp[dir[i][j]]=v;
				}
			}
		}
	}
	if(n==1)
	{
		cout<<1<<endl;
	}
	else if(n==2)
	{
		cout<<2<<endl;
	}
	else if(n==3)
	{
		cout<<3<<endl;
	}
	else if(n==4)
	{
		cout<<4<<endl;
	}
	else
	{
		int mx=0;
		
		int val[n];
		heapPermutation(val,n,n);
		
		for(auto vec:v1)
		{
			bool flag=0;
			int cnt=1;
			
			long double dd=-1;
			for(int i=1;i<vec.size();i++)
			{
				if(flag==0)
				{
					cnt++;
					flag=1;
				}
				else
				{
					if(dd==-1)
					{
						cnt++;
						dd=dir[vec[i]][vec[i-1]];
					}
					else
					{
						if(dir[vec[i]][vec[i-1]]==dd)
						{
							cnt++;
						}
						else
						{
							break;
						}
					}
					flag=0;
				}
			}
			mx=max(mx,cnt);
		}
		cout<<mx<<endl;
	}

}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
