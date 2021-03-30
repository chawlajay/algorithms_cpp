#include<bits/stdc++.h>
using namespace std;

/* Insertion sort is based on the idea that one element from the input elements is consumed in 
each iteration to find its correct position i.e, the position to which it belongs in a sorted array. */

void insertion_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        /*storing current element whose left side is checked for its correct position .*/
        int temp=a[i];
        int j=i;

        while(j>0 && temp<a[j-1])
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
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

    insertion_sort(a,n);
    
    for(int i=0;i<n;i++)
    {
     cout<<a[i]<<" ";
    }
    return 0;
}