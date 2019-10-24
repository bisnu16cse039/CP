#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int a[10];

vector<int>factors[N];
int former_track[N];

int primefactorize(int n) {
    int c=0,j=1;
    if(n%2==0) {
        c++;
        a[j++]=2;
    }

    while(n%2==0) {
        n/=2;
    }
    for(int i=3; i*i<=n; i+=2) {
        if(n%i==0) {
                a[j++]=i;
            c++;
            while(n%i==0) {
                n/=i;
            }

        }
    }
    if(n>2) {
        c++;
       a[j++]=n;
    }
    return c;
}
int res[N];
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=9; j++)a[j]=0;
        int x;
        cin>>x;
        int c=primefactorize(x);
        for(int j=1;j<=c;j++){
            factors[i].push_back(a[j]);
        }
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){
            int m=INT_MIN;
        for(int j=0;j<factors[i].size();j++){
                int k=factors[i][j];
              int  r=res[former_track[k]]+1;
               former_track[k]=i;
               m=max(r,m);
        }
        res[i]=m;
        ans=max(ans,m);
    }
    if(ans==INT_MIN)ans=1;
    cout<<ans<<endl;
    return 0;
}

