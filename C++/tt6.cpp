#include<bits/stdc++.h>
using namespace std;
                                                                                                   
const int maxN = 2e6 + 7;

int n; 
int lef[maxN], righ[maxN];
int lef_n[maxN], righ_n[maxN];  
  
vector<int> find_cycle(vector<multiset<int> > &adj)
{
    vector<int> temp; 
    temp.push_back(lef_n[0]);
    vector<int> result;
    
    while (temp.size()) 
	{
        int u = temp.back();
        if (adj[u].size())
		{
            int v = *adj[u].begin();
            temp.push_back(v); 
            adj[u].erase(adj[u].begin()); 
            adj[v].erase(adj[v].find(u)); 
        }            
        else 
		{
            temp.pop_back();             
            result.push_back(u); 
        }
    }
    return result; 
}

vector<int> cycle;
bool check(vector<multiset<int> > &adj) {
	
    for (int i = 0; i < adj.size(); ++i)
	{
        if (adj[i].size() % 2)
		{
            return false;
        }
    }
    cycle = find_cycle(adj);
    
    if (cycle.size() != n+1) 
		return false;           
    return true;     
}
            
vector<int> last;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>lef[i]>>righ[i];
	}
    
    int l=0;
    int r=21;
    
    int ans;

    while(l<=r)
    {
    	int i=(l+r)/2;
    	int mask=(1<<i)-1;
    	
    	vector<multiset<int> > adj;
    	adj.resize((1<<i));
    	
    	for(int i=0;i<n;i++)
    	{
    		lef_n[i]=(lef[i]&mask);
    		righ_n[i]=(righ[i]&mask);
    		
    		adj[lef_n[i]].insert(righ_n[i]);
    		adj[righ_n[i]].insert(lef_n[i]);
		}
		
		if(check(adj))
		{
			last=cycle;
			ans=i;
			l=i+1;
		}
		else
		{
			r=i-1;
		}
	}
    
    cout<<min(ans,20)<<endl;
			
	multimap<pair<int,int> , pair<int,int> > temp;
	
	int mask=(1<<ans)-1;
	
	for(int i=0;i<n;i++)
	{
		lef_n[i]=(lef[i]&ans);
		righ_n[i]=(righ[i]&ans);
	}
		
	for (int i = 0; i < n; ++i)
	{
        int a = 2*i; 
        int b = 2*i + 1; 
        
        if (lef_n[i] > righ_n[i]) swap(a, b); 
        temp.insert({{min(lef_n[i], righ_n[i]), max(lef_n[i], righ_n[i])}, {a, b}});
	}
	
	for (int i = 1; i < last.size(); ++i) 
	{
        int l = last[i - 1];
        int r = last[i];
        auto p = temp.find(make_pair(min(l, r), max(l, r)));
        int id1 = (*p).second.first;
        int id2 = (*p).second.second; 
        
        if (l > r) swap(id1, id2);
        temp.erase(p);
        cout << id1 + 1 << " " << id2 + 1 << ' '; 
	}
    		
    return 0;
}  
