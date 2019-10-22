#include<bits/stdc++.h>

using namespace std;
#define MAX 100000
vector<int>edges[MAX];
vector<int>cost[MAX];
int main() {
    int v,e,x,y,i,j;
    cin>>v>>e;
    for(i=1; i<=e; i++) {
        cin>>x>>y;
        edges[x].push_back(y);
        //edges[y].push_back(x);
       // cost[x].push_back(1);
       // cost[y].push_back(1);
    }
    for(i=0; i<v; i++) {
            printf("%d: ",i);
        for(j=0; j<edges[i].size(); j++) {
            printf("%d ",edges[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
