#include<bits/stdc++.h>

using namespace std;
/**
********************************************************************
******************* Author:Bisnu sarkar ****************************
********************************************************************
**/

#define ull            unsigned long long
#define ll             long long
#define vi             vector<int>
#define pb             push_back
#define mp             make_pair
#define pii            pair<int,int>
#define vit            vector<int> :: iterator
#define sit            set<int> :: iterator
#define vrit           vector<int> :: reverse iterator
#define ff             first
#define ss             second

#define what_is(x)     cerr << #x << " is " << x << endl;

///*....Debugger....*/

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it)
{
    cout << endl ;
}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}

int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
int ini()
{
    int x;
    scanf("%d",&x);
    return x;
}
long long inl()
{
    long long x;
    scanf("%lld",&x);
    return x;
}

const int N = (int) 2e5 + 5;
const int NN = (int) sqrt(N);
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);

ll a[N],lazy[NN+5];
ll b[NN+5][1009];
int sz,n,q;
ll k;

void propagate(int id){
  for(int i=id*sz;i<min((id+1)*sz,n);i++){
     b[id][a[i]]--;
     a[i]=(a[i]+lazy[id])%k;
     b[id][a[i]]++;
  }
}

int query(int l,int r){
    int s=l/sz,e=l/sz;
    int res=0;
    if(s==e){
      if(lazy[s])propagate(s);
      
      for(int i=l;i<=r;i++){
         res+=!(a[i]%k);
      }
    }
    else{
      if(lazy[s])propagate(s);
      for(int i=l;i<(s+1)*sz;i++){
        res+=!(a[i]%k);
      }
      for(int i=s+1;i<e;i++){
        res+=b[i][k-lazy[i]];
      }
      if(lazy[e]){
        propagate(e);
      }
      for(int i=e*sz;i<=r;i++){
        res+=!(a[i]%k);
      }

    }
    return res;
}

void update(int l,int r,ll v){
     int s=l/sz,e=l/sz;
     int res=0;
     if(s==e){
       if(lazy[s])propagate(s);
       
       for(int i=l;i<=r;i++){
          b[s][a[i]]--;
          a[i]=(a[i]+v)%k;
          b[s][a[i]]++;
       }
     }
     else{
       if(lazy[s])propagate(s);
       for(int i=l;i<(s+1)*sz;i++){
         b[s][a[i]]--;
         a[i]=(a[i]+v)%k;
         b[s][a[i]]++;
       }
       for(int i=s+1;i<e;i++){
         lazy[i]+=v;
         lazy[i]%=k;
       }
       if(lazy[e]){
         propagate(e);
       }
       for(int i=e*sz;i<=r;i++){
         b[e][a[i]]--;
         a[i]=(a[i]+v)%k;
         b[e][a[i]]++;
       }

     }
}
 

int main()
{
    n=ini();
    q=ini();
    k=inl();
    sz=sqrt(n);
    for(int i=0;i<n;i++){
        a[i]=inl();
        a[i]=(a[i]%k);
        b[i/sz][a[i]]++;
    }
    

    while(q--){
       // for(int i=0;i<n;i++)error(a[i]);
        int op;
        op=ini();
        if(op==1){
           int l,r;
           l=ini(),r=ini();
           int res=query(l,r);
           cout<<res<<endl;
        }
        else{
           int l,r;
           ll v;
           l=ini(),r=ini();
           v=inl();
           update(l,r,v);
        }
       
    }

    return 0;
}
