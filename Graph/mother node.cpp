#include<bits/stdc++.h>

using namespace std;
vector<int>adj[1000];
queue<int>q;
int vis[1000];

void dfs(int u){


}

int main()
{
    int v,e,x,y,s;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        if(i==0)
            s=x;
        adj[x].push_back(y);

    }
    for(int i=0;i<v;i++){
        int k=adj[i].size();
        if(k==v-1){
            printf("Mother Vertex: %d",i);
            break;
        }
    }
    return 0;
}

