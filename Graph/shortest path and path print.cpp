#include<bits/stdc++.h>

using namespace std;
vector<int>adj[1000];
queue<int>q;
int vis[1000];
int dis[105];
int path[105];
void bfs(int s,int e){
   for(int i=0;i<e;i++)vis[i]=0;
   q.push(s);
   dis[s]=0;
   path[s]=s;
   vis[s]=1;
   while(!q.empty()){
      int u=q.front();
      q.pop();
      for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]]){
            int v=adj[u][i];
            vis[v]=1;
            dis[v]=dis[u]+1;
            path[v]=u;
            q.push(v);
        }
      }
   }
   if(!vis[e])
    return;
   vector<int>p;
   p.push_back(e);
   int now=e;
   while(now!=s){
    now=path[now];
    p.push_back(now);
   }
   for(int k=p.size()-1;k>=0;k--)
    cout<<p[k]<<"->";
}
int main()
{
    int v,e,x,y,s;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int st,en;
    cin>>st>>en;

    bfs(st,en);

    int c=0;
  /*  for(int i=0;i<v;i++){
        if(!vis[i]){
            c++;
            bfs(i,v);
        }
    }*/
 //   cout<<c<<endl;
    return 0;
}


