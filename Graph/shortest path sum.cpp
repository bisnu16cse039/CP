#include<bits/stdc++.h>

using namespace std;
#define inf 1e9
vector<pair<int,int> >adj[109];

bool vis[109];
int dis[109];

int s[109];
void dijakstra(int u){
    priority_queue< pair<int,int>, vector< pair<int,int> >,greater<pair<int,int> > >pq;
    pq.push({u,0});
    dis[u]=0;
    vis[u]=true;
    while(!pq.empty()){
        u=pq.top().first;
        pq.pop();

        vis[u]=true;

        for(auto x : adj[u]){
            int v=x.first;
            int w=x.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    pq.push({v,dis[v]});
                }
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){dis[j]=inf;vis[i]=false;adj[i].clear();}

        dijakstra(i);
        for(int j=0;j<n;j++){
           s[i]+=dis[j];
        }
    }
    double res=INT_MIN;
    int in;
    for(int i=0;i<n;i++){
        double p=(1.0/(double)s[i]);
        if(p>res){
            res=p;
            in=i;
        }

    }
    cout<<in<<endl;
    return 0;
}
