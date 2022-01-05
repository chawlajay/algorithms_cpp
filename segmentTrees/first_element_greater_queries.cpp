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
        t[v]=max(t[2*v],t[2*v+1]);
    }
}

int get_first_max(int t[],int v,int tl,int tr,int l,int r,int x)
{
    if(tl>r || tr<l)
    return -1;

    if(l<=tl && tr<=r){
        if(t[v]<=x)
        return -1;

        while(tl!=tr){
            int tm=(tl+tr)/2;
            if(t[2*v]>x){
                v=2*v;
                tr=tm;
            } else {
                v=2*v+1;
                tl=tm+1;
            }
        }
        return tl;
    }
    int tm=(tl+tr)/2;
    int rs=get_first_max(t,2*v,tl,tm,l,r,x);
    if(rs!=-1) return rs;
    return get_first_max(t,2*v+1,tm+1,tr,l,r,x);
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

        t[v]=max(t[2*v],t[2*v+1]);
    }
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
      int x,l,r,val;
      cin>>x>>l>>r;
      if(x==1)      // print maximum
      cin>>val,cout<<"First element greater than "<<val<<" present between position "<<l<<" to "<<r<<" is at position "<<1+get_first_max(segmentTree,1,0,n-1,l-1,r-1,val)<<"\n";
      else 
      update(segmentTree,1,0,n-1,l-1,r);
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