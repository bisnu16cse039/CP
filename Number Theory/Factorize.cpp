#include<bits/stdc++.h>

using namespace std;
int prime[1000007],p,mark[1000007];

int main() {
    int n;
    cin>>n;
    int i,j,l=sqrt(n+2),c;
    prime[p++]=2;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    for(i=3; i<=n; i+=2) {
        if(!mark[i]) {
            prime[p++]=i;
            for(j=i*i; j<=l; j+=i) {
                mark[j]=1;
            }
        }
    }
    int sqrtn=sqrt(n);
    for(i=0; prime[i]<=sqrtn; i++) {
        c=0;
        while(n%prime[i]==0) {
            c++;
            n/=prime[i];
        }
        if(c>=1)
            printf("%d^%d *",prime[i],c);
    }
    if(n>1)
        printf("%d\n",n);
    return 0;
}
