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
        t[v]=a[tl];
    else
    {
        int tm=(tl+tr)/2;
        construct_segment_tree(t,a,2*v,tl,tm);
        construct_segment_tree(t,a,2*v+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
    }
}

void update(int t[],int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr)
    t[v]=new_val;
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

int find_array_prefix(int t[],int v,int tl,int tr,int k){
if(k > t[v])
    return -1;

if(tl==tr)
    return tl;

int tm=(tl+tr)/2;
if(t[2*v] >= k)
    return find_array_prefix(t,2*v,tl,tm,k);
else
    return find_array_prefix(t,2*v+1,tm+1,tr,k-t[2*v]);
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
      int x,val,pos;
      cin>>x;
      if(x==1)
      cin>>val,cout<<"sum of the first "<<find_array_prefix(segmentTree,1,0,n-1,val)+1<<" elements of the array a[] is just greater than or equal to "<<val<<"\n";
      else
      cin>>pos>>val, update(segmentTree,1,0,n-1,pos-1,val);
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