#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    
    set<ll>st;
    set<ll>ans;
    for(int i=0;i<n;i++)
    {
        set<ll>st2;
        for(auto x:st)
        {
            ll y=x|a[i];
            ans.insert(y);
            st2.insert(y);
        }
        ans.insert(a[i]);
        st2.insert(a[i]);
        st=st2;
    }
    cout<<ans.size()<<endl;
   
 
    return 0;
}
