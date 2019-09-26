#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll ta[55][55];
ll ncr(ll n,ll r) {
    if(r==1)return n;
    if(n==r)return 1;
    if(ta[n][r]!=-1) {
        return ta[n][r];
    }
    ta[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
    return ta[n][r];
}

int main() {

    for(int i=1; i<=55; i++) {
        for(int j=1; j<=55; j++) {
            ta[i][j]=-1;
        }
    }
    ll n,r;
    scanf("%lld %lld",&n,&r);
    printf("%lld\n",ncr(n,r));

    return 0;
}
