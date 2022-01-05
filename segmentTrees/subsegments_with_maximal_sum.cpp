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

// we will store four values for each vertex: the sum of the segment, 
// the maximum prefix sum, the maximum suffix sum, and the sum of the maximal subsegment in it.
struct data{
    int sum,pref,suff,ans;
};

data combine(data l,data r){      //receives only data from the left and right child, and returns the data of the current vertex.
data res;
res.sum = l.sum + r.sum;
res.pref = max(l.pref,l.sum+r.pref);
res.suff = max(r.suff,r.sum+l.suff);
res.ans = max(l.suff+r.pref,max(l.ans,r.ans));

return res;
}

data make_data(int val){
    data res;
    res.sum = val;
    res.pref=res.suff=res.ans=max(0,val);

    return res;
}

void build(data t[],int a[],int v,int tl,int tr){
    if(tl==tr)
    t[v]=make_data(a[tl]);
    else
    {
        int tm=(tl+tr)/2;
        build(t,a,2*v,tl,tm);
        build(t,a,2*v+1,tm+1,tr);
        t[v]=combine(t[2*v],t[2*v+1]);
    }
}

void update(data t[],int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr)
    t[v]=make_data(new_val);
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
        update(t,2*v,tl,tm,pos,new_val);
        else
        update(t,2*v+1,tm+1,tr,pos,new_val);

        t[v]=combine(t[2*v],t[2*v+1]);
    }
}

data query(data t[],int v,int tl,int tr,int l,int r){
    if(l>r)
    return make_data(0);

    if(l==tl && r==tr)
    return t[v];

    int tm=(tl+tr)/2;
    return combine(query(t,2*v,tl,tm,l,min(r,tm)),query(t,2*v+1,tm+1,tr,max(tm+1,l),r));
}

int main(){
    int n;
    cin>>n;
    int a[n],neg[n]={0};
    fp(i,0,n)cin>>a[i];
    
    if(a[0]<0)
    neg[0]=1;
    fp(i,1,n){
        neg[i]=neg[i-1];
        if(a[i]<0)
        neg[i]+=1;
    }
    data t[4*n];
    build(t,a,1,0,n-1);

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if((l>0 && neg[r]-neg[l-1]==(r-l+1)) || (l==0 && neg[r]==r+1))
        cout<<*max_element(a+l,a+r+1);
        else{
        data answer = query(t,1,0,n-1,l,r);
        cout<<answer.ans;
        }
        cout<<"\n";
    }
    return 0;
}