
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

int set_1(int n,int pos){return n = (n | (1<<pos));}
int reset_0(int n,int pos){return n= n & ~(1<<pos);}
bool check_bit(int n,int pos){return n = n & (1<<pos);}

const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);

pair<int,pii>p[N];
map<int,int>m;
int res[N];
int tree[N];

void update(int n,int x){
    while(x<=n){
        tree[x]++;
        x+=(x&(-x));
    }
}

int query(int x){
    int sum=0;

    while(x>0){
        sum+=tree[x];
        x-=(x&(-x));
    }
    return sum;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n=ini();
    set<int>s;
    for(int i=1,in=1;i<=n;i++){
        int l=ini(),r=ini();
        s.insert(l);
        s.insert(r);
        p[i]={l,{r,i}};        
    }
    int x=1;
    for(auto it:s){
       m[it]=x;
       ++x;      
    }
    for(int i=1;i<=n;i++){
        p[i]={m[p[i].ff],{m[p[i].ss.ff],p[i].ss.ss}};
        //error(p[i].ff,p[i].ss.ff);
    }
    sort(p+1,p+n+1);
    reverse(p+1,p+n+1);

    for(int i=1;i<=n;i++){
        int r=query(p[i].ss.ff);
      //  error(p[i].ss.ff,p[i].ss.ss);
        res[p[i].ss.ss]=r;
        update(2*n,p[i].ss.ff);
    }

    for(int i=1;i<=n;i++){
        cout<<res[i]<<endl;
    }

    

    return 0;
}
