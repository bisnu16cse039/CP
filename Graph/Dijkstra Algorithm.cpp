#include<bits/stdc++.h>
using namespace std;

#define ll             long long
#define gcd(a,b)       __gcd(a,b)
#define lcm(a,b)       a*(b/gcd(a,b))
#define pii            pair<int, int>
#define pll            pair<ll, ll>
#define pil            pair<int, ll>
#define pli            pair<ll, int>
#define vi             vector<int>
#define vl             vector<ll>
#define vii            vector<pii>
#define vll            vector<pll>
#define vil            vector<pil>
#define vli            vector<pli>
#define mii            map<int, int>
#define mll            map<ll, ll>
#define pb             push_back
#define ppb            pop_back
#define mp             make_pair
#define mt             make_tuple
#define lb             lower_bound
#define ub             upper_bound
#define ff             first
#define ss             second
#define all(v)         v.begin(),v.end()
#define fill(a,b)      memset(a,b,sizeof a)
#define smax(a, b)     a=max(a, b)
#define smin(a, b)     a=min(a, b)
#define sqr(x)         x*x
#define cube(x)        x*x*x
#define asort(a, n)    sort(a+1, a+n+1)
#define FOR(i, l, r)   for(int i=l;i<=r;i++)
#define ROF(i, a, b)   for(int i=r;i>=l;i--)
#define endl           '\n'

int in() {
    int n;
    scanf("%d",&n);
    return n;
}

ll Lin() {
    ll n;
    scanf("%lld",&n);
    return n;
}

double Din() {
    double n;
    scanf("%lf",&n);
    return n;
}

const double gama = 0.57721566490;
const double eps = 0.00000001;
const ll inf = 1e17;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;

vii g[N];
bool vis[N];
ll dis[N];
int par[N];

void dijkstra(int u, int n) {
    for(int i=1; i<=n; i++)
        dis[i]=inf;
    priority_queue<pli, vli, greater<pli> >pq;
    pq.push(mp(0LL, u));
    dis[u]=0LL;
    while(!pq.empty()) {
        u=pq.top().ss;
        pq.pop();
        vis[u]=true;
        for(auto x : g[u]) {
            int v=x.ss;
            ll w=(ll)x.ff;
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                par[v]=u;
                if(!vis[v])
                    pq.push(mp(dis[v], v));
            }
        }
    }
}

void path(int u, int v) {
    if(par[v])
        path(u, par[v]);
    u!=v? printf(" %d", v) : printf("%d", v);
}

int main() {
    int n=in(), m=in();
    for(int i=1; i<=m; i++) {
        int u=in(), v=in(), w=in();
        g[u].pb(mp(w, v));
        g[v].pb(mp(w, u));
    }
    dijkstra(1, n);
    path()
//    int q=in();
//    while(q--) {
//        int v=in();
//        if(vis[v]) {
//            printf("%d\n", dis[v]);
//            path(1, v);
//            printf("\n");
//        } else
//            printf("Infinity\n");
//    }
    return 0;
}









