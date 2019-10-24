#include<bits/stdc++.h>

using namespace std;

#define ll             long long
#define vi             vector<int>
#define FOR(x, l, r)   for (int x = l; x <= r; ++x)
#define RFOR(x, l, r)   for (int x = l; x >= r; --x)

const int N = (int) 2e5 + 5;
const int INF = (int) 1e9 + 7;
int ini(){
    int x;
    scanf("%d",&x);
    return x;
}
long long inl(){
    long long x;
    scanf("%d",&x);
    return x;
}
int used[20],number[20];
void permutation(int a,int n)
{
    if(a == n+1){
        for(int i=1;i<=n;i++)
            printf("%d ",number[i]);
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            number[a]=i;
            permutation(a+1,n);
            used[i]=0;
        }
    }
}
int main()
{
    int n;
    n=ini();
    permutation(1,n);
    return 0;
}

