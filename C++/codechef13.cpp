#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<iterator>

using namespace std;

int B[20],dig1=0,d;

void findmin(int A[],int s,int e)
{
    if(s<=e)
    {
        int min=10,ind=s;
        for(int i=s;i<=e;i++)
        {
            if(A[i]<min)
            {
                min=A[i];
                ind=i;
            }
        }
        if(min<d)
        {
            B[dig1]=min;
            dig1++;
            findmin(A,ind+1,e);
        }
        else
            return;
    }
    else
        return;

}

int main()
{
int T;
cin>>T;
while(T--)
{
    dig1=0;
    long long N,n;
    int dig=0;
    cin>>N>>d;
    n=N;
    int A[20];
    for(int i=0;n!=0;i++)
    {
        A[i]=n%10;
        dig++;
        n/=10;
    }
    std::reverse(A,A+dig);

    findmin(A,0,dig-1);
    for(int i=0;i<dig1;i++)
        cout<<B[i];
    for(int i=dig1;i<dig;i++)
        cout<<d;
    cout<<endl;

}
return 0;
}
