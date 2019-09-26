#include<bits/stdc++.h>

using namespace std;
int coin[]={1,5,10,25,50};
int make;
int dp[6][7495];

int call(int i,int amount){
    if(i>=5){
        if(amount==make)return 1;
        else
            return 0;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];

    int ret1=0,ret2=0;
    if(amount+coin[i]<=make){
        ret1=call(i,amount+coin[i]);
    }
    else{
        ret1=0;
    }
    ret2=call(i+1,amount);
   // cout<<ret1<<" "<<ret2<<endl;
  //  cout<<amount<<endl;
    return dp[i][amount]=ret1+ret2;
}

int main()
{
    while(scanf("%d",&make)==1){
        memset(dp,-1,sizeof(dp));
        printf("%d\n",call(0,0));
    }

    return 0;
}
