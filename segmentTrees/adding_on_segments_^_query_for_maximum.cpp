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

vector<int> lazy(100000,0);
void push(int t[],int v){    
t[2*v] += lazy[v];
t[2*v+1] += lazy[v];
lazy[2*v] += lazy[v];
lazy[2*v+1] += lazy[v];
lazy[v]=0;
}

void build(int t[],int a[],int v,int tl,int tr){
    if(tl==tr)
        t[v]=a[tl];
    else
    {
        int tm=(tl+tr)/2;
        build(t,a,2*v,tl,tm);
        build(t,a,2*v+1,tm+1,tr);
        t[v]=max(t[2*v],t[2*v+1]);
    }
}

int get_max_value(int t[],int v,int tl,int tr,int l,int r)
{
    if(l>r)
    return -100000;

    if(l<=tl && tr<=r)
    return t[v];

    push(t,v);
    int tm=(tl+tr)/2;
    
    return max(get_max_value(t,2*v,tl,tm,l,min(r,tm)),get_max_value(t,2*v+1,tm+1,tr,max(tm+1,l),r));
}

void update(int t[],int v,int tl,int tr,int l,int r,int add)
{
    if(l>r)
    return;

    if(l==tl && r==tr)
    t[v] += add, lazy[v] += add;
    else
    {
        push(t,v);
        int tm=(tl+tr)/2;
        update(t,2*v,tl,tm,l,min(r,tm),add);
        update(t,2*v+1,tm+1,tr,max(l,tm+1),r,add);
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
  build(segmentTree,v,1,0,n-1);
  
  int q;
  cin>>q;
  while(q--)
  {
      int x,l,r,val;
      cin>>x>>l>>r;
      if(x==1)
      cout<<"Maximum Element value from position "<<l<<" to "<<r<<" is "<<get_max_value(segmentTree,1,0,n-1,l-1,r-1)<<"\n";
      else
      cin>>val,update(segmentTree,1,0,n-1,l-1,r-1,val);
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