#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;
map<int,string> mp_inv;
const int maxN=62*62+10;

multiset<int> adj[maxN];

vector<int> find_cycle(int src)
{
    vector<int> temp; 
    temp.push_back(src);
    vector<int> result;
    
    while (temp.size()) 
	{
        int u = temp.back();
        if (adj[u].size())
		{
            int v = *adj[u].begin();
            temp.push_back(v); 
            adj[u].erase(adj[u].begin()); 
        }            
        else 
		{
            temp.pop_back();             
            result.push_back(u); 
        }
    }
    return result; 
}

void find_ans(int n) {
	
	int val1=-1;
	int val2=-1;
	
	int valid;
	
	int inD[maxN]={0};
	int outD[maxN]={0};
	
    for (int i = 0; i < maxN; ++i)
	{
		for(auto ch:adj[i])
		{
			inD[ch]++;
		}
		
		if(adj[i].size())
			valid=i;

		outD[i]=adj[i].size();
    }
	
	int cnt=0;
	
	for(int i=0;i<maxN;i++)
	{
		if(inD[i]!=outD[i])
		{
			cnt++;
			if(outD[i]==inD[i]+1)
			{
				val1=i;
			}
			else if(inD[i]==outD[i]+1)
			{
				val2=i;
			}
			else
			{
				cout<<"NO"<<endl;
				return ;
			}
		}
	}
	
    if(val1!=-1 && val2==-1 || cnt>2)
    {
    	cout<<"NO"<<endl;
		return ;
	}
	vector<int> cycle;
	if(val1!=-1)
	{
		cycle=find_cycle(val1);
	}
	else
	{
		cycle=find_cycle(valid);
	}  
	/*
	for(int i=0;i<cycle.size();i++)
	{
		cout<<mp_inv[cycle[i]]<<' '<<cycle[i]<<endl;
	}
	*/
	if (cycle.size() == n+1)
	{
		reverse(cycle.begin(),cycle.end());
		cout<<"YES"<<endl;
		string ans=mp_inv[cycle[0]];
		for(int i=1;i<cycle.size();i++)
		{
			ans.push_back(mp_inv[cycle[i]][1]);
		}
		cout<<ans<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}    
}

int main()
{
	int n;
	cin>>n;
	
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];	
	}
	
	vector<char> v;
	
	for(int i=0;i<26;i++)
		v.push_back(i+'a');
	
	for(int i=0;i<26;i++)
		v.push_back(i+'A');
		
	for(int i=0;i<10;i++)
		v.push_back(i+'0');
		
	int cnt=0;
	for(auto ele:v)
	{
		for(auto ele1:v)
		{
			string temp="";
			temp.push_back(ele);
			temp.push_back(ele1);
			//cout<<temp<<' '<<cnt<<endl;
			mp[temp]=cnt;
			mp_inv[cnt]=temp;
			cnt++;	
		}
	}
	for(int i=0;i<n;i++)
	{
		int a=mp[s[i].substr(0,2)];
		int b=mp[s[i].substr(1,2)];
		
		//cout<<a<<' '<<b<<endl;
		adj[a].insert(b);
	}
	
	find_ans(n);
	return 0;
}
