#include<bits/stdc++.h>

using namespace std;
/**
********************************************************************
******************* Author:Bisnu sarkar ****************************
********************************************************************
**/

#define fRead(x)       freopen(x,"r",stdin)
#define fWrite(x)      freopen (x,"w",stdout)

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
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}

int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
int ini(){
    int x;
    scanf("%d",&x);
    return x;
}
long long inl(){
    long long x;
    scanf("%lld",&x);
    return x;
}

const int N = (int) 2e5 + 5;
const int inf = (int) 1e9 + 7;
const double pi=2* acos(0.0);

vector<int>adj[N];
int ti=0;
int st[N],en[N];
map<int,int>m;
bool vis[N];

void dfs(int u){
    ++ti;
    st[u]=ti;
    m[ti]=u;
    for(int i=0;i<adj[u].size();i++){
        dfs(adj[u][i]);
    }
    en[u]=ti;
}

int main()
{

    int n,i,j,q;
    n=ini(),q=ini();

    for(int i=2;i<=n;i++){
        int x;
        x=ini();
        adj[x].push_back(i);
    }
    dfs(1);

    while(q--){
        int u,k;
        u=ini(),k=ini();

        if(st[u]+k-1 >en[u]){
            printf("-1\n");
        }
        else{
            printf("%d\n",m[st[u]+k-1]);
        }
    }
    return 0;
}



