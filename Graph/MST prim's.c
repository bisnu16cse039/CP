#include<bits/stdc++.h>

using namespace std;
#define N=1e5+5;
int dist[N], parent[N];
bool vis[N];
vector<pair<int, int> > g[N], tree[N];

int primsMST(int source) { //Finds the cost and makes the MST
    for(int i=1; i<=n; i++)
        dist[i]=1e18;
    set<pair<int, int> > s;
    s.insert({0, source});
    int cost=0;
    dist[source]=0;
    while(!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        vis[x.second]=1;
        cost+=x.first;
        int u=x.second;
        int v=parent[x.second];
        int w=x.first;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
        for(auto it:g[x.second]) {
            if(vis[it.first])
                continue;
            if(dist[it.first] > it.second) {
                s.erase({dist[it.first], it.first});
                dist[it.first]=it.second;
                s.insert({dist[it.first], it.first});
                parent[it.first]=x.second;
            }
        }
    }
    return cost;
}

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(w,v);
    }
    cout<<cost<<endl;
    return 0;
}
