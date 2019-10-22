#include<bits/stdc++.h>

using namespace std;
int main() {
    vector<int>adj[100];
    int visited[100];
    int n;
    for(int i=0; i<n; i++)visited[i]=0;

    queue<int>q;
    q.push(s);
    visited(s)=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++) {
            if(visitd[adj[u][i]==0) {
            int v=adj[u][i];
                visited[v]=1;
                q.push(v);
            }
        }
    }

    return 0;
}
