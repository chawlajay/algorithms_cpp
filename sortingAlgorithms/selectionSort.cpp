#include<bits/stdc++.h>
using namespace std;

/* The Selection sort algorithm is based on the idea of finding the minimum or maximum element
 in an unsorted array and then putting it in its correct position in a sorted array. */

void selection_sort(int a[],int n)
{
    int minimum;
    for(int k=0;k<n-1;k++)
    {
        // assuming the first element to be the minimum of the unsorted array .
        minimum=k;
        for(int i=k+1;i<n;i++)
        {
            if(a[i]<a[minimum])
            {
                minimum=i;
            }
        }
        // putting minimum element on its proper position.
        swap(a[k],a[minimum]);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    selection_sort(a,n);
    
    for(int i=0;i<n;i++)
    {
     cout<<a[i]<<" ";
    }
    return 0;
}