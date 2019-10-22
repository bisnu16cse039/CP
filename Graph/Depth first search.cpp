#include<bits/stdc++.h>

using namespace std;
#define M 100000
vector<int>ve[M];
vector<bool>vis;

void dfs(int n){
    vis[n]=true;
    for(int i=0;i<ve[n].size();i++){
        int e=ve[n][i];
        if(!vis[e])
            dfs(e);
    }
}
int main()
{
    int n,e,i,j,x,y;
    cin>>n>>e;

    for(i=0;i<e;i++){
        cin>>x>>y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    int c=0;
    for(int i=1;i<=e;i++){
        if(!vis[i]){
            c++;
            dfs(i);
        }
    }
    cout<<c<<endl;
    return 0;
}
