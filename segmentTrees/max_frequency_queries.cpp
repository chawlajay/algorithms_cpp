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

pii t[4000];

pii combine(pii a,pii b)
{
  if(a.F > b.F)
  return a;
  if(b.F > a.F)
  return b;

  return mk(a.F,a.S+b.S);
}

void build(int a[],int v,int tl,int tr){
  if(tl==tr)
  t[v]=mk(a[tl],1);
  else{
    int tm=(tl+tr)/2;
    build(a,2*v,tl,tm);
    build(a,2*v+1,tm+1,tr);
    t[v] = combine(t[2*v],t[2*v+1]);
  }
}

pii get_max(int v,int tl,int tr,int l,int r){
  if(l>r)
    return mk(-1000000,0);       // the minimum value
  if(l==tl && r==tr)
    return t[v];

  int tm=(tl+tr)/2;
  return combine(get_max(2*v,tl,tm,l,min(tm,r)),get_max(2*v+1,tm+1,tr,max(l,tm+1),r));
}

void update(int v,int tl,int tr,int pos,int new_val){
  if(tl==tr)
    t[v]=mk(new_val,1);
  else{
    int tm=(tl+tr)/2;
    
    if(pos<=tm)
    update(2*v,tl,tm,pos,new_val);
    else
    update(2*v+1,tm+1,tr,pos,new_val);

    t[v]=combine(t[2*v],t[2*v+1]);
  }
}

void solve()
{
  int n;
  cin>>n;
  int v[n];
  fp(i,0,n)cin>>v[i];

  build(v,1,0,n-1);
  int q;
  cin>>q;
  while(q--)
  {
    int x,l,r;
    cin>>x>>l>>r;
    if(x==1){
    pii p=get_max(1,0,n-1,l-1,r-1);
    cout<<p.F<<" "<<p.S;
    }
    else
    update(1,0,n-1,l-1,r);
    cout<<"\n";
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