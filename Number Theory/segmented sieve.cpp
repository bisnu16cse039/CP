#include<bits/stdc++.h>
using namespace std;

int p[100000];
bool b[1000000]= {false};
void pr(int N)
{
    int n=sqrt(N),j=0;
    for(int i=2; i<=n; i++)
    {
        if(!b[i])
        {
            p[j]=i;
            cout<<p[j]<<" ";
            j++;
            for(int k=i*i; k<=N; k+=i) b[k]=true;
        }
    }
    for(int i=n; i<=N; i++)
    if(!b[i])
        {
            p[j]=i;
            cout<<p[j]<<" ";
            j++;
        }
}
int main()
{
    int x=sqrt(2147483647);
    pr(x);
    return 0;
}
