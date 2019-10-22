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
#define ROF(i, l, r)   for(int i=r;i>=l;i--)
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
const ll mod = 1e9 + 9;
const int N = 400 + 5;

ll dis[N][N];
int par[N][N];

void floyd_warshall(int n) {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dis[i][j]>dis[i][k]+dis[k][j]) {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    par[i][j]=par[i][k];
                }
            }
        }
    }
}

void path(int u, int v) {
    printf("%d ", u);
    if(u!=v) {
        u=par[u][v];
        path(u, v);
    }
}

int main() {
    int n=in(), m=in();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dis[i][j]=inf;
            par[i][j]=j;
        }
    }
    for(int i=1; i<=m; i++) {
        int u=in(), v=in();
        dis[u][v]=Lin();
    }
    floyd_warshall(n);
    int q=in();
    while(q--) {
        int u=in(), v=in();
        if(dis[u][v]==inf)
            printf("Infinite\n");
        else {
            printf("%lld\n", dis[u][v]);
            path(u, v);
            printf("\n");
        }
    }
    return 0;
}



