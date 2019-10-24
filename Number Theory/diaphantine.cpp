#include<bits/stdc++.h>

using namespace std;
int r[100000];
int main()
{
    int a,b,i=1;
    cin>>a>>b;
    while(a!=1){
        int t=b;
        r[i++]=a/b;
        if(b>a){
            b=a%b;
        }
        else
           b=a-r[i-1]*b;
        a=t;
    }
    if(r[i-1]!=1){
        r[i]=1;
    r[i-1]-=1;
    }

    int k=i;
    int p0=1,q0=0,p1=r[1],q1=1,p,q;
    for(i=2;i<k;i++){
        p=r[i]*p1 + p0;
        q=r[i]*q1  +q0;
        p0=p1;
        q0=q1;
        p1=p;
        q1=q;
    }
    cout<<p<<" "<<q<<endl;
    return 0;
}
