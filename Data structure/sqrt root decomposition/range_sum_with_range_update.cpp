
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

const int N = (int) 1e5 + 5;
const int NN = (int) 320;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);

int a[N],b[N];
int sz;
void process(int n)
{
 
    int idx=-1;
    for(int i=0;i<n;i++){
         if(i%sz==0){
           ++idx;
         }  
         b[idx]+=a[i];
       //  error(b[idx]);
    }
}

int query(int l,int r){
    int sum=0;
  while(l<r and l%sz!=0){
    sum+=a[l];
    ++l;
  }
 // error(sum);
  while(l+sz <=r){
    sum+=b[l/sz];
    l+=sz;
  }
  //error(sum);
  while(l<=r){
    sum+=a[l];
    ++l;
  }
  //error(sum);

  return sum;
}
void rangeupdate(int l,int r,int v){
     while(l<r and l%sz!=0){
       a[l]+=v;
       ++l;
     }
    // error(sum);
     while(l+sz <=r){
       b[l/sz]+=v*sz;
       l+=sz;
     }
     //error(sum);
     while(l<=r){
       a[l]+=v;
       ++l;
     }
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sz=sqrt(n);
    process(n); 
    int q;
    cin>>q;

    while(q--){
        int op;
        cin>>op;
        if(op==1){
           int l,r;
           cin>>l>>r;
           int res=query(l,r);
           cout<<res<<endl;
        }
        else{
           int l,r,v;
           cin>>l>>r>>v;
           rangeupdate(l,r,v);
        }
       
    }
    return 0;
}