#include<bits/stdc++.h>

using namespace std;

int vis[5000004];
void seive()
{
    for(int i=2;i<=5000003;i++){
        if(!vis[i]){
            vis[i]=i;
            for(int j=i+i;j<=5000003;j+=i){
                vis[j]=i;
            }
        }
    }

}
int sum[5000004];
void factor(int n)
{
    int x=n;
    while(n>1){
        int p=vis[n];

        while(n%p==0){
            n/=p;
            sum[x]++;
        }
    }

}

int main()
{
    seive();

    for(int i=2;i<=5000000;i++){
        factor(i);
        sum[i]+=sum[i-1];
    }
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        cout<<sum[x]-sum[y]<<endl;
    }
    return 0;
}
