#include<bits/stdc++.h>
using namespace std;

/* Quick sort is based on the divide-and-conquer approach based on the idea of choosing one element as a pivot
 element and partitioning the array around it such that: Left side of pivot contains all the elements that are
 less than the pivot element Right side contains all elements greater than the pivot */

int partition(int a[],int start,int end)
{
    int k=start+1,pivot=start;
    for(int i=start+1;i<=end;i++){
        if(a[i]<a[pivot])
        {
            swap(a[k],a[i]);
            k++;
        }
    }
    swap(a[k-1],a[pivot]);
    return k-1;
}

void quick_sort(int a[],int start,int end)
{
    if(start<end)
    {
        int pivot_element = partition(a,start,end);
        quick_sort(a,start,pivot_element-1);
        quick_sort(a,pivot_element+1,end);
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

    quick_sort(a,0,n-1);
    
    for(int i=0;i<n;i++)
    {
     cout<<a[i]<<" ";
    }
    return 0;
}