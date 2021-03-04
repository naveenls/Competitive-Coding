#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int i,int j)
{
	int temp;
	
	cout<<"? "<<i<<' '<<j<<endl;
	cout.flush();
	cin>>temp;
		
	return temp;
}

bool all_fill(int z[])
{
	for(int i=0;i<11;i++)
	{
		if(z[i]==-1)
		{
			//cout<<"hi"<<endl;
			return true;
		}
	}
	return false;
}

int get_val(int z[],int i)
{
	int result=(1<<11)-1;
	
	for(int k=0;k<11;k++)
	{
		if(z[k]!=i)
		{
			result=result&query(z[k],i);
		}
		else if(result&(1<<k))
		{
			result=result^(1<<k);
		}
	}
	return result;
}
int main()
{
	int n;
	cin>>n;
	
	int z[11];
	memset(z,-1,sizeof(z));
	
	while(all_fill(z))
	{
		int i=uniform_int_distribution<int>(1,n)(rng);
		int j=uniform_int_distribution<int>(1,n)(rng);
		if(i!=j)
		{
			int temp=query(i,j);
			
			for(int k=0;k<11;k++)
			{
				
				if(!(temp&(1<<k)))
				{
					z[k]=i;
				}
			}
		}
	}
	
	int index=1;
	int val=get_val(z,index);
	
	for(int i=2;i<=n;i++)
	{
		if(query(index,i)==val)
		{
			index=i;
			val=get_val(z,i);
		}
	}
	
	int ans[n+1];
	
	for(int i=1;i<=n;i++)
	{
		if(i==index)
		{
			ans[i]=0;
		}
		else
		{
			ans[i]=query(i,index);
		}
	}
	
	cout<<'!'<<' ';
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout.flush();
	return 0;
}
