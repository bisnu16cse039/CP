#include<bits/stdc++.h>

using namespace std;
#define ll long long

vector<pair<int,int> >adj[100009];

bool vis[10009];
int par[10009],dis[10009];
void dijakstra(int u,int n) {
    priority_queue< pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > >pq;
    pq.push({0ll, u});
    dis[u]=0;
    while(!pq.empty()) {
        u=pq.top().second;
        pq.pop();
        vis[u]=true;

        for(auto x: adj[u]) {
            int v=x.second;
            ll w=x.first;
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                if(!vis[v])pq.push({dis[v],v});
            }

        }
    }
}
void path(int u,int v) {
    if(par[u]) {
        path(u,par[v]);
    }
    u!=v? printf(" %d", v) : printf("%d", v);
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0; i<=n; i++)dis[i]=1e9;
    for(int i=1; i<=m; i++) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    int x,y;
    cin>>x>>y;
    dijakstra(x,y);
    path(x,y);
    cout<<dis[y]<<endl;
    return 0;
}
