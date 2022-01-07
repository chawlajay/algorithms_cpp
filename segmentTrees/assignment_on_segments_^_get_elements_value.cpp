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

vector<bool> marked(100000,false);
void push(int t[],int v){
    if(marked[v]){
        t[2*v]=t[2*v+1]=t[v];
        marked[2*v]=marked[2*v+1]=true;
        marked[v]=false;
    }
}

void build(int t[],int a[],int v,int tl,int tr){
    if(tl==tr)
        t[v]=a[tl];
    else
    {
        int tm=(tl+tr)/2;
        build(t,a,2*v,tl,tm);
        build(t,a,2*v+1,tm+1,tr);
        t[v]=0;
    }
}

int get_element_value(int t[],int v,int tl,int tr,int pos)
{
    if(tl==tr)
    return t[v];

    push(t,v);
    int tm=(tl+tr)/2;
    if(pos<=tm)
    return get_element_value(t,2*v,tl,tm,pos);
    else
    return get_element_value(t,2*v+1,tm+1,tr,pos);
}

void update(int t[],int v,int tl,int tr,int l,int r,int new_val)
{
    if(l>r)
    return;

    if(l==tl && r==tr)
    t[v]=new_val,marked[v]=true;
    else
    {
        push(t,v);
        int tm=(tl+tr)/2;
        update(t,2*v,tl,tm,l,min(r,tm),new_val);
        update(t,2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
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
      int x,l,r,pos;
      cin>>x;
      if(x==1)
      cin>>pos,cout<<"Element value at position "<<pos<<" is "<<get_element_value(segmentTree,1,0,n-1,pos-1)<<"\n";
      else
      cin>>l>>r>>pos,update(segmentTree,1,0,n-1,l-1,r-1,pos);
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