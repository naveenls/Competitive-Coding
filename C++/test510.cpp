#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+1;
int cnt[maxN]={0};

int mod4=0;
int mod2=0;

void add(int x)
{
	cnt[x]++;
	
	if(cnt[x]%4==0)
	{
		mod4++;
	}
	if(cnt[x]%2==0)
	{
		mod2++;
	}
}

void remove(int x)
{
	cnt[x]--;
	
	if((cnt[x]+1)%4==0)
	{
		mod4--;
	}
	if((cnt[x]+1)%2==0)
	{
		mod2--;
	}
}

bool check()
{
	int temp=mod2-2*mod4;
	
	if(mod4>1)
	{
		return true;
	}
	
	if(mod4==1)
	{
		if(temp>=2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	return false;
}
	
int main()
{
	int n;
	cin>>n;
	
	int x;
	char c;
	
	for(int i=0;i<n;i++)
	{
		cin>>x;
		add(x);
	}
	
	int q;
	cin>>q;
	
	while(q--)
	{
		cin>>c>>x;
		
		if(c=='+')
		{
			add(x);	
		}
		else
		{
			remove(x);
		}
		
		if(check())
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
}
