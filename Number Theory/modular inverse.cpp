#include<bits/stdc++.h>

using namespace std;

#define ll long long
//when m is prime then, b inverse 1= b^(m-2), else b inverse 1=b^(phi(m)-1) 
long long modinverse(long long b,long long p,long long m) {
    if(p==0)return 1%m;
    long long x=modinverse(b,p/2,m);
    x=(x*x)%m;
    if(p%2==1)x=(x*b)%m;
    return x;

}

int main() {
    long long a, b,m;
    while(scanf("%lld %lld %lld",&a,&b,&m)==3) {
        ll ans=(a*modinverse(b,m-2, m)) % m;
        cout<<ans<<endl;
    }

    return 0;
}


