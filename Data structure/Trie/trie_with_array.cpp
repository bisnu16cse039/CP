#include<bits/stdc++.h>
using namespace std;

#define ll             long long
#define LL             long long
#define gcd(a,b)       __gcd(a, b)
#define lcm(a,b)       a * (b / gcd(a, b))
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
#define pb             push_back
#define ppb            pop_back
#define mp             make_pair
#define ff             first
#define ss             second
#define all(v)         v.begin(), v.end()
#define fill(a, b)     memset(a, b, sizeof a)
#define smax(a, b)     a = max(a, b)
#define smin(a, b)     a = min(a, b)
#define sqr(x)         x * x
#define cube(x)        x * x * x
#define endl           '\n'

int in() {
    int n;
    scanf("%d", &n);
    return n;
}

ll Lin() {
    ll n;
    scanf("%lld", &n);
    return n;
}

double Din() {
    double n;
    scanf("%lf", &n);
    return n;
}

const ll inf = (ll)1e17;
const ll mod = (ll)1e9 + 7;
const int N = 1e5 + 5;

char s[N];
string t;
int trie[N][52];
int cnt[N], state;

void add() {
    int node = 0, sz = strlen(s);
    for(int i = 0; i < sz; i++) {
        int to = (s[i] >= 'a' && s[i] <='z') ? s[i] - 'a' : s[i] - 'A' + 26;
        if(trie[node][to] == -1) trie[node][to] = ++state;
        node = trie[node][to];
    }
    cnt[node]++;
}

int query() {
    int node = 0, sz = strlen(s);
    for(int i = 0; i < sz; i++) {
        int to = (s[i] >= 'a' && s[i] <='z') ? s[i] - 'a' : s[i] - 'A' + 26;
        if(trie[node][to] == -1) return 0;
        node = trie[node][to];
    }
    return cnt[node];
}


int solve() {
    state = 0;
    fill(trie, -1);
    fill(cnt, 0);
    int n = in();
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        int l = strlen(s);
        if(l > 3) sort(s + 1, s + l - 1);
        add();
    }
    int q = in();
    getchar();
    while(q--) {
        ll ans = 1LL;
        getline(cin, t);
        int l = t.size(), j = 0;
        for(int i = 0; i <= l; i++) {
            if(i == l || t[i] == ' ') {
                s[j] = '\0';
                j = 0;
                int sz = strlen(s);
                if(sz > 3) sort(s + 1, s + sz - 1);
                if(sz > 0) ans *= query();
            } else {
                s[j++] = t[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

int main() {
    int test = in(), tc = 0;
    while(test--) {
        printf("Case %d:\n", ++tc);
        solve();
    }
    return 0;
}