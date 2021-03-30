#include<bits/stdc++.h>
using namespace std;

/* Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements
and then swapping their positions if they exist in the wrong order. */

void bubble_sort(int a[],int n)
{
    for(int k=0;k<n-1;k++)
    {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations
        for(int i=0;i<n-k-1;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
            }
        }
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

    bubble_sort(a,n);
    
    for(int i=0;i<n;i++)
    {
     cout<<a[i]<<" ";
    }
    return 0;
}