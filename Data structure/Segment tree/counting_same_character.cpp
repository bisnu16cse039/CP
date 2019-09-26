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
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);
int a[N],tree[N*4][26];

void build(int node, int b, int e)
{
    if (b == e) {
        tree[node][a[b]]=1;
       // error(a[b]);
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    for(int i=0;i<26;i++){
        tree[node][i] = tree[Left][i] + tree[Right][i];
      //  if(tree[node][i]) error(i,tree[node][i]);
    }
}

void update(int node, int b, int e, int i, int newvalue,int present)
{
    if (i > e || i < b)
        return; 
    if (i>=b && i<=e) { 
        tree[node][newvalue]++;
        tree[node][present]--;
        return;
    }
    int Left = node * 2; 
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue,present);
    update(Right, mid + 1, e, i, newvalue,present);
    for(int i=0;i<26;i++){
      tree[node][i]= tree[Left][i]+tree[Right][i];
    }    
}

int query(int node, int b, int e, int i, int j,int x)
{
    if (i > e || j < b)
        return 0; 
    if (b >= i && e <= j)
        return tree[node][x]; 
    int Left = node * 2; 
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j,x);
    int p2 = query(Right, mid + 1, e, i, j,x);
    return p1 + p2; 
}

int main()
{
    int n,m;

    cin>>n>>m;

    string s;
    cin>>s;

    for(int i=0;s[i];i++){
      a[i+1]=s[i]-'a';
      //error(a[i+1]);
    } 
    build(1,1,n);

    while(m--){
        int op;
        cin>>op;

        if(op==1){
           int x;
           char c;
           cin>>x>>c;
           update(1,1,n,x,c-'a',a[x]);
        }
        else{
           int l,r;
           char c;
           cin>>l>>r>>c;
           int res=query(1,1,n,l,r,c-'a');
           cout<<res<<endl;
        }
    }

    return 0;
}
