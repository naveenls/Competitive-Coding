#include <bits/stdc++.h>
#include <string>
using namespace std;

map<int,int> num;
map<int,int> denom;
 
const int MAXN=1e7+1;  
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

void factorize(int x,map<int,int> &mp) 
{ 
    while (x != 1) 
    { 
        mp[spf[x]]++; 
        x = x / spf[x]; 
    } 
} 
int power(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b%2)
		{
			res=res*a;
		}
		b/=2;
		a=a*a;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	int a;
	sieve();
	for(int i=0;i<n;i++)
	{
		cin>>a;
		factorize(a,num);
	}
	for(int i=0;i<m;i++)
	{
		cin>>a;
		factorize(a,denom);
	}
	auto itr=num.begin();
	auto itr1=denom.begin();
	
	while(itr!=num.end() && itr1!=denom.end())
	{
		if(itr->first<itr1->first)
		{
			++itr;
		}
		else if(itr->first>itr1->first)
		{
			++itr1;
		}
		else
		{
			int mi=min(itr->second,itr1->second);
			itr->second-=mi;
			itr1->second-=mi;
			++itr;
			++itr1;
		}
	}
	vector<long long> num_ans,denom_ans;
	for(auto itr=num.begin();itr!=num.end();++itr)
	{
		while(itr->second)
		{
			double d=log(1e7)/log(itr->first);
			int times=min(itr->second,(int) d);
			itr->second-=times;
			num_ans.push_back(power(itr->first,times));
		}
	} 
	if(!num_ans.size())
		num_ans.push_back(1);
	for(auto itr=denom.begin();itr!=denom.end();++itr)
	{
		while(itr->second)
		{
			double d=log(1e7)/log(itr->first);
			int times=min(itr->second,(int) d);
			itr->second-=times;
			denom_ans.push_back(power(itr->first,times));
		}
	} 
	if(!denom_ans.size())
		denom_ans.push_back(1);
	cout<<num_ans.size()<<' '<<denom_ans.size()<<endl;
	for(auto ele:num_ans)
	{
		cout<<ele<<' ';
	}
	cout<<endl;
	for(auto ele:denom_ans)
	{
		cout<<ele<<' ';
	}
	cout<<endl;
	return 0;
}
