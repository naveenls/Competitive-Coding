#include <algorithm> 
#include <iostream> 
using namespace std; 
  
long long mod=1e9+7;

long long maxProductSubarrayOfSizeK(long long A[], int n, int k) 
{ 
    sort(A, A + n); 

    long long product = 1; 

    if (A[n - 1] == 0 && (k & 1)) 
        return 0; 
  
    if (A[n - 1] <= 0 && (k & 1)) { 
        for (int i = n - 1; i >= n - k; i--) 
            product = (product*A[i])%mod; 
        return product; 
    } 
  
    int i = 0; 
  
    int j = n - 1; 

    if (k & 1) { 
        product = (product*A[j])%mod; 
        j--; 
        k--; 
    } 

    k >>= 1; 
    for (int itr = 0; itr < k; itr++) { 
  
        // product from left pointers 
        long long left_product = A[i] * A[i + 1]; 
  
        // product from right pointers 
        long long right_product = A[j] * A[j - 1]; 
  
        // Taking the max product from two choices 
        // Correspondingly changing the pointer's position 
        if (left_product > right_product) { 
            product = (product*A[i])%mod; 
            product = (product*A[i+1])%mod; 
            i += 2; 
        } 
        else { 
            product = (product*A[j])%mod; 
            product = (product*A[j-1])%mod; 
            j -= 2; 
        } 
    } 
  
    return product%mod; 
} 
  
// Driver Code to test above function 
int main() 
{ 
	int n,k;
	cin>>n>>k;
	
    long long A[n];
	for(int i=0;i<n;i++)
		cin>>A[i]; 
  	
    cout << (maxProductSubarrayOfSizeK(A, n, k)%mod +mod)%mod;
  
    return 0; 
} 
