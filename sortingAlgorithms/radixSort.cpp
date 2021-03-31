#include<bits/stdc++.h>
using namespace std;

/* For each digit  where  varies from the least significant digit to the most significant 
digit of a number. Sort input array using countsort algorithm according to ith digit. */

void count_sort(int a[],int n,int place){
int i,freq[10]={0};
int output[n];

for(int i=0;i<n;i++){
    freq[(a[i]/place)%10]++;
}

for(int i=1;i<10;i++)
freq[i]+=freq[i-1];

for(int i=n-1;i>=0;i--)
{
    output[ freq[ (a[i]/place)%10 ] - 1] = a[i];
    freq[ (a[i]/place)%10 ]--;
}

for(int i=0;i<n;i++)
a[i]=output[i];

}

void radix_sort(int a[],int n,int mx)
{
    int mult=1;
    while(mx)
    {
        count_sort(a,n,mult);
        mult*=10;
        mx/=10;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maximum_number = *max_element(a,a+n);
    radix_sort(a,n,maximum_number);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}