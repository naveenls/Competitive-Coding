#include <bits/stdc++.h>
using namespace std;

int main() {

	long long n,k;
	cin>>n>>k;
	if (n < k*(k+1)/2) 
	{
		cout << "NO" << endl;
		return 0;
	}
	
	int val = n - k*(k+1)/2;
	
	int arr[k];
	
	for (int i = 0; i < k; ++i) 
	{
		if(i>=k-val%k)
		{
			arr[i]=1;
		}
		else
		{
			arr[i]=0;
		}
		arr[i]+=(i+1 + val/k);
	}
	
	if (val != k - 1) 
	{
		cout << "YES" << endl;
		for (int i = 0; i < k; ++i) 
			cout <<arr[i]<<" ";
		cout << endl;
	} 
	else 
	{
		if (k>3)
		{
			--arr[1];
			++arr[k - 1];
		}
		if (k==2 || k==3)
		{
			cout << "NO" << endl;
		}
		else 
		{
			cout << "YES" << endl;
			for (int i = 0; i < k; ++i) 
				cout << arr[i] << " ";
			cout << endl;
		}
	}
	return 0;
}
