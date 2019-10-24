#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod=1e9+7;

long long bigmod(long long b,long long p,long long m) {
    if(p==0)return 1%m;
    long long x=bigmod(b,p/2,m);
    x=(x*x)%m;
    if(p%2==1)x=(x*b)%m;
    return x;

}

ll fac[100005]={1LL};

int main() {
    ll n, r;
    scanf("%lld %lld", &n, &r);
    for(int i=1; i<=1e5; i++) {
        fac[i]=(fac[i-1]*i)%mod;
    }
    ll ans=(fac[n]*bigmod(fac[n-r], mod-2, mod))%mod;
    cout<<ans<<endl;
    return 0;
}



