#include<bits/stdc++.h>

using namespace std;
#define Max 100000
vector<int>edges[Max];
vector<int>oedges[Max];

int main() {
    int v,e,x,y,i,j;
    cin>>v>>e;
    for(i=0; i<e; i++) {
        cin>>x>>y;
        edges[x].push_back(y);
        oedges[y].push_back(x);
    }
    int ind[100];
    for(i=1; i<=v; i++) {
        j=edges[i].size();
        ind[i]++;
    }
    int outd[100];
    for(i=1; i<=v; i++) {
        j=oedges[i].size();
        outd[i]++;
    }
    for(i=1;i<=v;i++){
        cout<<ind[i]<<" "<<outd[i]<<endl;
    }
    return 0;
}
