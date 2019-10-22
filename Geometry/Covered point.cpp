#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct p {
    int x1,y1,x2,y2;
};
int main() {
    int n;

    scanf("%d",&n);
    p x[n+1];
    ll res=0;
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        x[i].x1=a;
        x[i].y1=b;
        x[i].x2=c;
        x[i].y2=d;
        res+=(ll)(__gcd(abs(a-c),abs(b-d)))+1;
    }
    cout<<res<<endl;
    return 0;
}
