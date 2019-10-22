#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;

vector<int> adj[N];
int color[N],p[N];
int cycle_start=-1,cycle_end;

bool dfs(int u){
    color[u]=1;
    for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
        if(color[v]==0){
            p[v]=u;
            if(dfs(v)){
                return true;
            }
        }
        else if(color[v]==1){
            cycle_end=u;
            cycle_start=v;
            return true;
        }
    }
    color[u]=2;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
       // adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(dfs(i)){
            break;
        }
    }
    if(cycle_start == -1){
        cout<<"acyclic"<<endl;
    }
    else{
        cout<<"cyclic"<<endl;
        vector<int>cycle;

        for(int i=cycle_end;i!=cycle_start;i=p[i]){
              //  cout<<i<<endl;
            cycle.push_back(i);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(),cycle.end());
        for(int i=0;i<cycle.size();i++){
            cout<<cycle[i]<<" ";
        }
    }
    return 0;
}
