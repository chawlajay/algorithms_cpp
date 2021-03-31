#include<bits/stdc++.h>
using namespace std;

// for positive elements
// for n<=10,00,000
/* In Counting sort, the frequencies of distinct elements of the array to be sorted is counted 
and stored in an auxiliary array, by mapping its value as an index of the auxiliary array.*/
void counting_sort(int a[],int n)
{
    int maximum=*max_element(a,a+n);
    vector<int> v(maximum+1,0);

    for(int i=0;i<n;i++)
    v[a[i]]++;

    for(int i=0;i<=maximum;i++)
    {
        while(v[i]--)
        {
            cout<<i<<" ";
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

    counting_sort(a,n);
    return 0;
}