#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int a[2000];
int cnt=0;
int n;
long long k;

void bubbleSort(int arr[], int l,int h,int ind)
{
   int i, j;
   if(ind==1)
       for(i=h-1;i>=l;i--)
       {
           if(arr[i+1]<arr[i])
           {
               j=arr[i+1];
               arr[i+1]=arr[i];
               arr[i]=j;
           }
           else
            break;
       }
   else
   {
       for(i=l+1;i<=h;i++)
       {
           if(arr[i]<arr[i-1])
           {
               j=arr[i-1];
               arr[i-1]=arr[i];
               arr[i]=j;
           }
           else
            break;
       }
   }
}

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
    int ind = binarySearch(a2,l, e, x);

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


void func(int ar[],int s,int e)
{

    cout<<s<<' '<<e<<"hi"<<endl;
    for(int i=s;i<=e;i++)
        cout<<ar[i]<<' ';
    cout<<endl;

if(s!=e)
    		{

        		if(k%(e-s+1)==0)
    			 {

            		int x=ar[e];
            		int t=countOccurrences(ar,s,e,x);
            		//cout<<t<<' '<<x<<"hi2"<<endl;
            		if(binarySearch(ar,s,e,t)!=-1)
            		{
                	cnt++;
/*
                for(int r=s;r<=e;r++)
                    cout<<ar[r]<<' ';
                cout<<endl;

*/
            		}
    			}
        	else
        	{

        		 int p=k/(e-s+1)+1;
            	int z;
            	if(k/(e-s+1)!=0)
            		z=k/p+1;
        		else
        			z=k/p;

            	int x=ar[s+z-1];

            	int t=countOccurrences(ar,s,e,x);
            	//cout<<t<<' '<<x<<"hi2"<<endl;
            	if(binarySearch(ar,s,e,t)!=-1)
            	{
                	cnt++;
/*
                for(int r=s;r<=e;r++)
                    cout<<ar[r]<<' ';
                cout<<endl;
*/

            	}
    		}
    		}
}
void maxCrossingSum(int l, int m, int h)
{
    int ar[n],br[n];
    copy(a,a+m+1,ar);
    sort(ar+m,ar+m+1);
    copy(ar,ar+m+1,br);
    for(int i=m;i>=l;i--)
    {
        bubbleSort(br,i,m,-1);
        copy(br,br+m+1,ar);
        copy(a+m+1,a+h+1,ar);
        for(int j=m+1;j<=h;j++)
        {
            bubbleSort(ar,i,j,1);
            func(ar,i,j);
        }
    }



   //maxcross(ar,m,m,l,h,1);
}

// Returns sum of maxium sum subarray in aa[l..h]
void maxSubArraySum(int l, int h)
{

   if (l == h)
    {
    	//cout<<l<<' '<<a[l]<<endl;
        if(a[l]==1)
            cnt++;
    }
  else
  {
   int m = (l + h)/2;
	//cout<<l<<' '<<m<<"hi"<<endl;
   maxSubArraySum(l, m),
   maxSubArraySum(m+1, h),
   maxCrossingSum(l, m, h);
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
	maxSubArraySum(0,n-1);
    cout<<cnt<<endl;
}

return 0;
}
