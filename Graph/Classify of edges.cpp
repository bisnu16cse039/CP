#include<bits/stdc++.h>

using namespace std;
vector<int>adj[1009];
vector< pair<int,int> >tree_edge,back_edge,forward_edge,cross_edge;

int ti[1009],t;
bool vis[1009];
void dfs(int u) {
    vis[u]=1;
    ti[u]= ++t;

    for(auto v: adj[u]) {

        if(!vis[v]) {
            tree_edge.push_back({u,v});
            dfs(v);
        } else if(vis[v]==1) {
            back_edge.push_back({u,v});
        } else {

            if(ti[u]<ti[v]) {
                forward_edge.push_back({u,v});
            } else {
                cross_edge.push_back({u,v});
            }
        }
    }
    vis[u]=2;
}

int main() {
    int n,m;

    cin>>n>>m;

    for(int i=1; i<=m; i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);

    }
    for(int i=1; i<=n; i++) {
        if(!vis[i])dfs(i);
    }
    //cout<<tree_edge.size()<<endl;
    cout<<"Tree edge:"<<endl;
    for(int i=0; i<tree_edge.size(); i++) {
        cout<<tree_edge[i].first<<" "<<tree_edge[i].second<<endl;
    }
    cout<<"Back_edge:"<<endl;
    for(int i=0; i<back_edge.size(); i++) {
        cout<<back_edge[i].first<<" "<<back_edge[i].second<<endl;
    }
    cout<<"Forward_edge:"<<endl;
    for(int i=0; i<forward_edge.size(); i++) {
        cout<<forward_edge[i].first<<" "<<forward_edge[i].second<<endl;
    }
    cout<<"Cross_edge:"<<endl;
    for(int i=0; i<cross_edge.size(); i++) {
        cout<<cross_edge[i].first<<" "<<cross_edge[i].second<<endl;
    }

    return 0;
}
