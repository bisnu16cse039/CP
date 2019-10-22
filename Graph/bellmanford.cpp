#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int> >adj[109];
int dis[109];
#define inf 1e9
void bellmanford(int u,int n)
{
    for(int i=0;i<n;i++)dis[i]=inf;
    dis[u]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(auto x: adj[j]){
                int m=x.first;
                int w=x.second;

                if(dis[j]+w<dis[m]){
                    dis[m]=dis[j]+w;
                }
            }
        }
    }
    for(int i=0;i<)

}
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int root;
    cin>>root;
    bellmanford(root,n);

    for(int i=0;i<n;i++){
        cout<<"Node: "<<i<<" Dis: "<<dis[i]<<endl;
    }
    return 0;
}
