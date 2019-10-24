#include<bits/stdc++.h>

using namespace std;

int prime[9000000],p;
bool mark[100000005];

void seive(int n) {
    int i,j,limit=sqrt(n+1);

    mark[1]=true;
    prime[p++]=2;
    for(i=4; i<=n; i+=2)
        mark[i]=true;

    for(i=3; i<=n; i+=2) {
        if(!mark[i]) {
            prime[p++]=i;
            if(i<=limit) {
                for(j=i*i; j<=n; j+=i*2) {
                    mark[j]=true;
                }
            }
        }
    }

}

int main() {
    seive(10000000);
    cout<<prime[p-1]<<" "<<prime[p-2]<<endl;
    cout<<p<<endl;
    int n;
    cin >> n;
    int i,j,limit=sqrt(n);

    mark[1]=1;
    for(i=4; i<=n; i+=2)
        prime[0]=2;

    for(i=3; i<=n; i+=2) {
        if(!mark[i]) {
            prime[++p]=i;
            if(i<=limit) {
                for(j=i*i; j<=n; j+=i*2) {
                    mark[j]=1;
                }
            }
        }
    }

    int c=0;
    for(i=0; i<p; i++) {
        printf("%d\n",prime[i]);
        c++;
    }
    cout << c<<endl;
    return 0;
}
