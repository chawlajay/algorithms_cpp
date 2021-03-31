#include<bits/stdc++.h>
using namespace std;

/* Heaps can be used in sorting an array. In max-heaps, maximum element will always be at the
root. Heap Sort uses this property of heap to sort the array. */

void heapify(int a[],int n,int index)
{
    int largest = index;
    int l=2*index+1;
    int r=2*index+2;

    if(l<n && a[l]>a[largest])
    largest=l;

    if(r<n && a[r]>a[largest])
    largest=r;

    if(largest!=index)
    {
        swap(a[index],a[largest]);
        heapify(a,n,largest);
    }
}

void heap_sort(int a[],int n){
    // to build heap
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }

    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heap_sort(a,n);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}