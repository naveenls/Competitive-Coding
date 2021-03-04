#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int a[2000];
int cnt=0;
int n;
long long k;


int binarySearch(int a1[],int l, int r, int x)
{
    if (r < l)
        return -1;

    int mid = l + (r - l) / 2;

    if (a1[mid] == x)
        return mid;

    if (a1[mid] > x)
        return binarySearch(a1,l, mid - 1, x);

    return binarySearch(a1,mid + 1, r, x);
}

int countOccurrences(int a2[],int l,int e, int x)
{
    int ind = binarySearch(a,l, e, x);

    // If element is not present
    if (ind == -1)
        return 0;

    int count = 1;
    int left = ind - 1;
    while (left >= l && a2[left] == x)
        count++, left--;

    // Count elements on right side.
    int right = ind + 1;
    while (right <=e && a2[right] == x)
        count++, right++;

    return count;
}
/*
void merge(int a[],int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int l, int r)
{
    /*
    if(l==r)
    {
        //cout<<"HI"<<l<<a[l]<<endl;
        if(a[l]==1)
        {
            cnt++;

        }
    }

    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(l, m);
        //cout<<l<<' '<<m<<"HI1"<<endl;
        if(k%(m-l+1)==0)
        {
            int x=a[m];
            int t=countOccurrences(l,m,x);
            if(binarySearch(l,m,t)!=-1)
            {
                cnt++;

                for(int j=l;j<=m;j++)
                    cout<<a[j]<<' ';
                cout<<endl;

            }
        }
        else
        {
            int p=k/(m-l+1)+1;
            int s=k/p+1;
            int x=a[l+s-1];
            int t=countOccurrences(l,m,x);
            if(binarySearch(l,m,t)!=-1)
            {
                cnt++;

                for(int j=l;j<=m;j++)
                    cout<<a[j]<<' ';
                cout<<endl;

            }
        }
        mergeSort(m+1, r);
        //cout<<m+1<<' '<<r<<"HI2"<<endl;
        if(k%(r-m)==0)
        {
            int x=a[r];
            int t=countOccurrences(m+1,r,x);
            if(binarySearch(m+1,r,t)!=-1)
            {
                cnt++;

                for(int j=m+1;j<=r;j++)
                    cout<<a[j]<<' ';
                cout<<endl;

            }
        }
        else
        {
            int p=k/(r-m)+1;
            int s=k/p+1;
            int x=a[m+s];
            int t=countOccurrences(m+1,r,x);
            if(binarySearch(m+1,r,t)!=-1)
            {
                cnt++;

                for(int j=m+1;j<=r;j++)
                    cout<<a[j]<<' ';
                cout<<endl;

            }
        }
        merge(l, m, r);
        //cout<<l<<' '<<r<<"HI3"<<endl;
        /*
        if(k%(r-l+1)==0)
        {
            int x=a[r];
            int t=countOccurrences(l,r,x);
            if(binarySearch(l,r,t)!=-1)
            {
                cnt++;
                for(int j=l;j<=r;j++)
                    cout<<a[j]<<' ';
                cout<<endl;
            }
        }
        else
        {
            int p=k/(r-l+1)+1;
            int s=k/p+1;
            int x=a[l+s-1];
            int t=countOccurrences(l,r,x);
            if(binarySearch(l,r,t)!=-1)
            {
                cnt++;
                for(int j=l;j<=r;j++)
                    cout<<a[j]<<' ';
                cout<<endl;
            }
        }

    }
}
*/
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int main()
{
int T;
cin>>T;
while(T--)
{
    cnt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //mergeSort(0,n-1);
    /*
    if(k%(n)==0)
        {
            int x=a[n-1];
            int t=countOccurrences(0,n-1,x);
            if(binarySearch(0,n-1,t)!=-1)
            {
                cnt++;

                for(int j=0;j<=n-1;j++)
                    cout<<a[j]<<' ';
                cout<<endl;

            }
        }
    else
    {
            int p=k/(n)+1;
            int s=k/p+1;
            int x=a[s-1];
            int t=countOccurrences(0,n-1,x);
            if(binarySearch(0,n-1,t)!=-1)
            {
                cnt++;

                for(int j=0;j<=n-1;j++)
                    cout<<a[j]<<' ';
                cout<<endl;

            }

    */
    for(int i=0;i<n;i++)
    {
        int ar[n];
        copy(a, a+n, ar);
        /*
        for(int c=0;c<n;c++)
            cout<<ar[c]<<' ';
        cout<<endl;
        */
        for(int j=i;j<n;j++)
        {
            //cout<<i<<' '<<j<<endl;
            merge(ar,i,j-1,j);
            for(int c=i;c<j;c++)
                cout<<ar[c]<<' ';
            cout<<endl;
           if(k%(j-i+1)==0)
        {
            int x=ar[j];
            int t=countOccurrences(ar,i,j,x);
            if(binarySearch(ar,i,j,t)!=-1)
            {
                cnt++;
/*
                for(int r=i;r<=j;r++)
                    cout<<a[r]<<' ';
                cout<<endl;

*/
            }
        }
            else
        {
            int p=k/(j-i+1)+1;
            int z;
            if(k/p!=0)
            	z=k/p+1;
        	else
        		z=k/p;
            int x=ar[s+z-1];
            int t=countOccurrences(ar,s,e,x);
            if(binarySearch(ar,s,e,t)!=-1)
            {
                cnt++;
/*
                for(int r=i;r<=j;r++)
                    cout<<a[r]<<' ';
                cout<<endl;
*/

            }
        }
        }
    }
    cout<<cnt<<endl;
}

return 0;
}
