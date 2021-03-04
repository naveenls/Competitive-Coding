#include<bits/stdc++.h>
using namespace std;

#define N 11 

int forwardElim(int mat[N][N+1]); 
  
int* backSub(int mat[N][N+1]); 
  
int* gaussianElimination(int mat[N][N+1]) 
{ 
    int singular_flag = forwardElim(mat); 
  
    if (singular_flag != -1) 
    { 
        cout<<'!'<<' '<<-1<<endl; 
    } 

    return backSub(mat); 
} 
  
void swap_row(int mat[N][N+1], int i, int j) 
{ 
  
    for (int k=0; k<=N; k++) 
    { 
        int temp = mat[i][k]; 
        mat[i][k] = mat[j][k]; 
        mat[j][k] = temp; 
    } 
} 

int forwardElim(int mat[N][N+1]) 
{ 
    for (int k=0; k<N; k++) 
    { 
        int i_max = k; 
        int v_max = mat[i_max][k]; 
  
        for (int i = k+1; i < N; i++) 
            if (abs(mat[i][k]) > v_max) 
                v_max = mat[i][k], i_max = i; 
  

        if (!mat[k][i_max]) 
            return k; 
  
        if (i_max != k) 
            swap_row(mat, k, i_max); 
  
  
        for (int i=k+1; i<N; i++) 
        { 
    
            int f = mat[i][k]/mat[k][k]; 
  

            for (int j=k+1; j<=N; j++) 
                mat[i][j] -= mat[k][j]*f; 
  
            mat[i][k] = 0; 
        } 

    } 
 
    return -1; 
} 
  
// function to calculate the values of the unknowns 
int* backSub(int mat[N][N+1]) 
{ 
    int* x=new int[N]; 

    for (int i = N-1; i >= 0; i--) 
    { 
        x[i] = mat[i][N]; 
  
        for (int j=i+1; j<N; j++) 
        { 
            
            x[i] -= mat[i][j]*x[j]; 
        } 

        x[i] = x[i]/mat[i][i]; 
    } 
  
    return x;
} 
  
int find_val(int arr[],int x)
{
	int ans=0;
	int mod=1e6+3;
	
	for(int i=N-1;i>=10;i--)
	{
		ans=((ans*x)%mod+arr[i])%mod;
	}
	
	ans=(ans+mod)%mod;
	return ans;
}
int main()
{
	vector<pair<int,int> > v;
	int mod=1e6+3;
	int val;
	
	for(int i=1;i<=11;i++)
	{
		cout<<'?'<<' '<<i<<endl;
		cin>>val;
		
		v.push_back({i,val});
	}
	
	int mat[N][N+1];
	
	for(int i=0;i<11;i++)
	{
		int val=1;
		for(int j=0;j<11;j++)
		{
			mat[i][j]=val;
			val=(val*(i+1))%mod;
		}
		mat[i][N]=v[i].second;
	}
	
	int* vals=gaussianElimination(mat);
	
	for(int i=0;i<1e6+3;i++)
	{
		if(find_val(vals,i)==0)
		{
			cout<<'!'<<' '<<i<<endl;
			return 0;
		}
	}
	cout<<'!'<<' '<<-1<<endl;
	return 0;
}
