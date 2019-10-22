#include<bits/stdc++.h>

using namespace std;
#define inf 1e9
vector<pair<int,int> >adj[109];
bool vis[109];
int dis[109];
void dijakstra(int u){
    set< pair<int,int> > s;
    s.insert({0,u});
    dis[u]=0;

    while(!s.empty()){
        set<pair<int,int> >::iterator it;
        it=s.begin();
        u= it->second;
        s.erase(it);

        vis[u]=true;

        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            int w=adj[u][i].second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    s.insert({dis[v],v});
                }
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<=n; i++) {
        dis[i]=inf;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijakstra(1);
    int x;
    while(cin>>x)cout<<dis[x]<<endl;


    return 0;
}
