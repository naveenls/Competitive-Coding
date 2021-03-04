#include<bits/stdc++.h>
using namespace std;

const int maxN=210;

int n,l,k,a[maxN];
long double P[maxN], DP[maxN][maxN][maxN];
 
void solve(){
    cin>>n>>l>>k;
    for(int i=1;i<=n;i++)
	{
    	cin>>P[i];
		P[i] /= 100;	
	}
    for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]++;	
	}
	
    DP[0][0][k] = 1.0;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int m=0;m<=200;m++){
                DP[i][j][m] += DP[i-1][j][m]*(1-P[i]);
                DP[i][j+1][min(200,m+a[i])] += DP[i-1][j][m]*P[i];
            }
        }
    }
    long double ans = 0;
    
    for(int j=l;j<=200;j++){
        for(int m=j;m<=200;m++) ans += DP[n][j][m];
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}
 
int main(){
    solve();
    return 0;
}
