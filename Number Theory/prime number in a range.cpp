#include<bits/stdc++.h>

using namespace std;
int main()
{
    int i,j,p=0,l,h,k,m;
    scanf("%d %d",&l,&h);
    for(i=l;i<=h;i++){
        for(j=2;j*j<=i;j++){
            if(i%j==0)
                break;
        }
        if(j*j>i)
            p++;
    }
    if(l==1){
       cout<<p-1<<endl;
    }
    else{
        cout<<p<<endl;
    }

    return 0;
}
