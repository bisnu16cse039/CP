#include<bits/stdc++.h>

using namespace std;
long long bigmod(long long b,long long p,long long m){
    if(p==0)return 1%m;
    long long x=bigmod(b,p/2,m);
    x=(x*x)%m;
    if(p%2==1)x=(x*b)%m;
    return x;
}

int main()
{
    long long b,p,m;
    while(scanf("%lld %lld %lld",&b,&p,&m)==3){
        cout<<bigmod(b,p,m)<<endl;
    }

    return 0;
}

