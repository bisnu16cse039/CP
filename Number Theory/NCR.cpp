#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll ncr[22][22];
ll find_ncr(ll n,ll r) {
    if(r==1)return n;
    if(n==r or r==0)return 1;
    
    if(ncr[n][r]!=-1) {
        return ncr[n][r];
    }
    ncr[n][r]=find_ncr(n-1,r)+find_ncr(n-1,r-1);
    return ncr[n][r];
}


int main() {

    for(int i=1; i<=22; i++) {
        for(int j=1; j<=22; j++) {
            ncr[i][j]=-1;
        }
    }
    ll n,r;
    scanf("%lld %lld",&n,&r);
    printf("%lld\n",find_ncr(n,r));

    return 0;
}
