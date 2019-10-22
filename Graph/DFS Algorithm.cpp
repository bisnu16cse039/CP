#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b)    a*(b/gcd(a,b))
#define pii         pair<int, int>
#define pll         pair<ll, ll>
#define pli         pair<ll, int>
#define pil         pair<int, ll>
#define vi          vector<int>
#define vl          vector<ll>
#define vii         vector<pii>
#define vll         vector<pll>
#define vil         vector<pil>
#define vli         vector<pli>
#define mii         map<int, int>
#define mll         map<ll, ll>
#define pb          push_back
#define ppb         pop_back
#define mp          make_pair
#define lb          lower_bound
#define ub          upper_bound
#define ff          first
#define ss          second
#define all(v)      v.begin(),v.end()
#define fill(a,b)   memset(a,b,sizeof a)
#define endl        '\n'

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

const ll inf = 1e17;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

vi g[N];
bool vis[N];

void dfs(int u) {
    vis[u]=true;
    for(int i=0; i<g[u].size(); i++) {
        int v=g[u][i];
        if(!vis[v])
            dfs(v);
    }
}

int main() {
    int test=in(), tc=0;
    while(test--) {
        int node=in(), edge=in();
        for(int i=0; i<edge; i++) {
            int u=in(), v=in();
            g[u].pb(v);
            g[v].pb(u);
        }
        int comp=0;
        for(int i=1; i<=node; i++) {
            if(!vis[i]) {
                comp++;
                dfs(i);
            }
        }
        printf("Case %d: %d\n", ++tc, comp);
        for(int i=1; i<=node; i++) {
            g[i].clear(), vis[i]=false;
        }
    }
    return 0;
}
