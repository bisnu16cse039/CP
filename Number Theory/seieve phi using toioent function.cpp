#include<bits/stdc++.h>

using namespace std;
int phi[10000006],mark[10000006];
void seievephi(int n){
    int i,j;
    for(int i=1;i<=n;i++)phi[i]=i;
    phi[1]=1;
    mark[1]=1;
    for(int i=2;i<=n;i++){
        if(!mark[i]){
            for(int j=i;j<=n;j+=i){
                mark[j]=1;
                phi[j]=(phi[j]/i)*(i-1);
            }

        }
    }

}

int main()
{
    int n;
    cin>>n;
    seievephi(n);
    for(int i=1;i<=n;i++)cout<<phi[i]<<endl;
    return 0;
}
