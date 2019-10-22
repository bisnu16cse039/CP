/**
 *    author:  skmonir
 *    created: 29-Nov-2017 23:51:51
**/
#include <bits/stdc++.h>

using namespace std;

#define endl                '\n'
#define TN                  typename
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define mem(x, y)           memset(x, y, sizeof x)
#define FOR(x, l, r)        for (int x = l; x <= r; ++x)
#define ROF(x, l, r)        for (int x = l; x >= r; --x)

template <TN T> inline void Int(T &n) {
    n = 0; int f = 1; register int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}
template <TN T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <TN T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <TN T> inline void umax(T &a, T b) {a = a > b ? a : b;}
template <TN T, TN W> inline void Int(T &x, W &y) {Int(x), Int(y);}
template <TN T, TN W, TN Q> inline void Int(T &x, W &y, Q &z) {Int(x, y), Int(z);}

const int N = (int) 1e5 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;


int main() {
    int g1, g2, p1, p2;
    Int(g1, p1); Int(g2, p2);

    int winFirst, winSecond;

    ROF (i, g1, 0) {
        int percent = (i * 100) / g1;
        if (percent == p1) winFirst = i;
    }

    FOR (i, 0, g2) {
        int percent = (i * 100) / g2;
        if (percent == p2) winSecond = i;
    }
    cout<<winSecond<<endl;
    printf("%d\n", min(winSecond - winFirst, g2 - g1));

    return 0;
}
