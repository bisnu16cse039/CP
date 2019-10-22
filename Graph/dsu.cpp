#include<bits/stdc++.h>

using namespace std;
const int N=1e5;
int par[N];
int findroot(int u)
{
    if(par[u]==u)
        return u;
    else
        par[u]=findroot(par[u]);
}
void merge_set(int u,int v)
{
    u=findroot(u);
    v=findroot(v);
    if(u!=v)
        par[u]=v;
}

bool check(int u,int v){
    return findroot[u]==findroot[v];
}
int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<n;i++)
        par[i]=i;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        merge_set(u,v);

    }
    return 0;
}
