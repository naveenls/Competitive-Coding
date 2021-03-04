#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
int T;
cin>>T;
while(T--)
{
    int N,l=0,r=0;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++)
    {

        cin>>A[i];
        if(A[i]>0)
            l++;
        else
            r++;
    }
    if(l==N||r==N)
        cout<<N<<' '<<N<<endl;
    else if(r>l)
        cout<<r<<' '<<l<<endl;
    else
        cout<<r<<' '<<l<<endl;

}
return 0;
}
