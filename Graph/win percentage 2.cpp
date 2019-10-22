

#include<bits/stdc++.h>

using namespace std;

int main() {
    int g1,g2,p1,p2;
    cin>>g1>>p1>>g2>>p2;
    int i,r1,r2;

    for(i=g1; i>=0; i--) {
        int p=(i*100)/g1;


        if(p==p1) {
            r1=i;

        }
    }
    for(i=0; i<=g2; i++) {
        int p=(i*100)/g2;

        if(p==p2) {
            r2=i;
        }
    }



    if(r2>=r1){
          int   r=r2-r1;
        cout<<r<<endl;
    }
    else{
        cout<<0<<endl;
    }



    return 0;
}
