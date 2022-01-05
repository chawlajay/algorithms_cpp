#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mk make_pair
#define fp(i,a,b) for (int i = (a); i <(b); i++)
#define fn(i,a,b) for (int i = (a); i >(b); i--)
#define mod 1000000007
#define multiple_testcases_t int t;cin>>t;while(t--){solve();}
#define single_testcase_t solve();
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

vector<int> t[4000];

void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
    t[v] = vector<int>(1,a[tl]);
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);

        merge(t[2*v].begin(),t[2*v].end(),t[2*v+1].begin(),t[2*v+1].end(),back_inserter(t[v]));  // C++ STL inbuilt functions
    }
}

int query(int v,int tl,int tr,int l,int r,int x){
    if(l>r)
        return 1000000;     // "there is no answer in the given interval"
    if(l==tl && r==tr){
        vector<int>::iterator pos=lower_bound(t[v].begin(),t[v].end(),x);
        if(pos!=t[v].end())
        return *pos;

        return 1000000; // "there is no answer in the given interval"
    }
    int tm=(tl+tr)/2;
    return min(query(2*v,tl,tm,l,min(r,tm),x),query(2*v+1,tm+1,tr,max(l,tm+1),r,x));
}

int main(){
    int n;
    cin>>n;
    int a[n];
    fp(i,0,n)cin>>a[i];
    build(a,1,0,n-1);
    return 0;
}