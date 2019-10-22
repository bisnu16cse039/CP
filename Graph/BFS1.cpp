#include<bits/stdc++.h>

using namespace std;
int cost[10][10],qu[10],visit[10],visited[10],r,front;
int main() {
    int nov,noe,i,j,x,y,v;
    cin>>nov>>noe;
    for(i=1; i<=noe; i++) {
        cin>>x>>y;
        cost[x][y]=1;
    }
    cin>>v;
    visited[v]=1;
    i=1;
    while(i<nov) {
        for(j=1; j<nov; j++) {
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1) {
                visit[j]=1;
                qu[r++]=j;
            }

            v=qu[r-1];
            cout<<v<<" ";


        i++;

        visit[v]=0;
        visited[v]=1;
    }}
    return 0;

}
