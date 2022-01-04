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

void construct_segment_tree(int t[],int a[],int v,int tl,int tr){
    if(tl==tr)
    {
        int k = ((a[tl]==0) ? 1 : 0);
        t[v]=k;
    }
    else
    {
        int tm=(tl+tr)/2;
        construct_segment_tree(t,a,2*v,tl,tm);
        construct_segment_tree(t,a,2*v+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
    }
}

int count_zero(int t[],int v,int tl,int tr,int l,int r)
{
    if(l>r)
    return 0;
    if(l==tl && r==tr)
    return t[v];

    int tm=(tl+tr)/2;
    return count_zero(t,2*v,tl,tm,l,min(r,tm)) + count_zero(t,2*v+1,tm+1,tr,max(l,tm+1),r);
}

void update(int t[],int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr)
    {
    t[v]= ((new_val>0) ? 0 : 1);
    }
    else
    {
        int tm=(tl+tr)/2;
        if(pos<=tm)
        update(t,2*v,tl,tm,pos,new_val);
        else
        update(t,2*v+1,tm+1,tr,pos,new_val);

        t[v]=t[2*v]+t[2*v+1];
    }
}

int find_kth_zero(int t[],int v,int tl,int tr,int k){

if(k > t[v])
    return -1;

if(tl==tr)
    return tl;

int tm=(tl+tr)/2;
if(t[2*v] >= k)
    return find_kth_zero(t,2*v,tl,tm,k);
else
    return find_kth_zero(t,2*v+1,tm+1,tr,k-t[2*v]);
}

void solve()
{
  int n;
  cin>>n;
  int v[n];
  fp(i,0,n)cin>>v[i];

  int segmentTree[4*n];
  construct_segment_tree(segmentTree,v,1,0,n-1);
  
  int q;
  cin>>q;
  while(q--)
  {
      int x,l,r;
      cin>>x>>l;
      if(x==1)
      cin>>r,cout<<"number of zeros from position "<<l<<" to "<<r<<" is "<<count_zero(segmentTree,1,0,n-1,l-1,r-1)<<"\n";
      else if(x==2)
      cout<<"the kth zero is at position: "<<find_kth_zero(segmentTree,1,0,n-1,l)+1<<"\n";
      else
      cin>>r,update(segmentTree,1,0,n-1,l-1,r);
  }
}

int main()
{
    fast_io
 // freopen("input.txt", "r", stdin);
 // freopen("output.txt", "w", stdout);
 
  single_testcase_t
  //multiple_testcases_t
return 0;
}