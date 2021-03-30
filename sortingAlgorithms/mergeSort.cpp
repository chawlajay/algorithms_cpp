#include<bits/stdc++.h>
using namespace std;
/* Merge sort is a divide-and-conquer algorithm based on the idea of breaking down a list into several sub-lists 
until each sublist consists of a single element and merging those sublists in a manner that results into a sorted list. */

void merge(int a[],int left,int mid,int right)
{
    int p=left,q=mid+1,r=right;
    int temp[right-left+1],k=0;

    for(int i=0;i<(right-left+1);i++)
    {
        if(p>mid)
        {
            temp[k++]=a[q++];
        }
        else if(q>right)
        {
            temp[k++]=a[p++];
        }
        else if(a[p]>a[q])
        {
            temp[k++]=a[q++];  
        }
        else
        temp[k++]=a[p++];
    }
    k=0;
    for(int i=left;i<=right;i++)
    {
        a[i]=temp[k++];
    }
}

void merge_sort(int a[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
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

    merge_sort(a,0,n-1);
    
    for(int i=0;i<n;i++)
    {
     cout<<a[i]<<" ";
    }
    return 0;
}