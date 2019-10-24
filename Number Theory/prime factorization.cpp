#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define ll long long
vector<int>prime;
bool mark[N];

void sieve()
{
     int sq = sqrt(N);for(int i =4;i<=N;i+=2)mark[i]=true;
    for(int i=3;i<=sq;i+=2)if(!mark[i])for(ll j=i*i;j<=N;j+=2*i)mark[j]=true;
    for(int i=2;i<=N;i++)if(!mark[i])prime.push_back(i);
}
void primedivisors(int n) {
    for(int i=0; prime[i]*prime[i]<=n; i++) {
        if(n%prime[i]==0) {

            while(n%prime[i]==0) {
                n/=prime[i];
            }
        }
    }
    if(n>1) {

    }
}
int main()
{
    sieve();
    int n=10;
    primedivisors(n);
    return 0;
}
