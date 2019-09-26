#include<bits/stdc++.h>

using namespace std;
int row[109],col[109];
int dp[109][109];
bool vis[109][109];


int f(int b,int e){
    if(b>=e)return 0;
    if(vis[b][e])return dp[b][e];
    int ans=INT_MAX;

    for(int i=b;i<e;i++){
        int opr_left=f(b,i);
        int opr_right=f(i+1,e);

        int multiply_to_left_and_right= row[b]*col[i]*col[e];

        int t=opr_left+opr_right+multiply_to_left_and_right;

        ans=min(t,ans);
    }
    vis[b][e]=true;
    dp[b][e]=ans;
    return dp[b][e];
}
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>row[i];
        cin>>col[i];
    }
    cout<<f(0,n-1)<<endl;
    return 0;
}
