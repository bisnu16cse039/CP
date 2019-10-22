#include<bits/stdc++.h>

using namespace std;
vector<int>adj[1000];
queue<int>q;
int vis[1000];
void bfs(int s,int v){
    for(int i=0;i<v;i++)vis[i]=0;
   q.push(s);
   vis[s]=1;

   while(!q.empty()){
      int u=q.front();
      q.pop();
      for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]]){
            int v=adj[u][i];
            cout<<v<<" ";
            vis[v]=1;
            q.push(v);
        }
      }
      cout<<endl;
   }
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
        adj[y].push_back(x);.
    }
    bfs(s,v);
    return 0;
}
