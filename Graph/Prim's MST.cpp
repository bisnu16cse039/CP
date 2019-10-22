#include<bits/stdc++.h>

using namespace std;
int dis[1009];
bool vis[1009];

vector<pair<int,int> >adj[1009];
vector<int,int>res;

int mst(int source) {
    int cost=0;
    set< pair<int,int> > s;
    s.insert({0,source});
    vis[source]=true;
    while(!s.empty()){
        set<pair<int,int> >::iterator it;
        it=s.begin();
        int u= it->second;
        int w= it->first;

        s.erase(it);
        if(!vis[u]){
            cost+=w;
            vis[u]=true;
        }

        for(int i=0;i<adj[u].size();i++){

            if(!vis[adj[u][i].first]){
                s.insert({adj[u][i].second,adj[u][i].first});
            }
        }
    }
  //  cout<<cost<<endl;
    return cost;
}

int main() {
    int n,m;

    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)dis[i]=1e9;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout<<mst(1)<<endl;
    return 0;
}
