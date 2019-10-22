#include<bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
const int N=200009;

struct p{
    double d;
    int x1,x2,y1,y2;
} ;

int main() {
    int t;
    int x11,y11,x22,y22;
    scanf("%d",&t);
    string line;
//    getline(cin, line);
//   getline(cin, line);
    while(t--) {
        int n;
        scanf("%d",&n);
        p x[n+1];
        for(int i=1; i<=n; i++) {
            scanf("%d %d %d %d",&x11,&y11,&x22,&y22);
            double a=-(x11/(x22-x11));
            x[i].d=a;
            x[i].x1=x11;
            x[i].y1=y11;
            x[i].x2=x22;
            x[i].y2=y22;

        }
        int q;
        scanf("%d",&q);

        while(q--) {
            int a,b;
            scanf("%d %d",&a,&b);
            int res=a;
            while(1) {
                int yy=INT_MIN;
                for(int i=1; i<=n; i++) {
                    if(a>x[i].x1 && a<x[i].x2) {
                        if(x[i].d>yy){
                            yy=x[i].d;
                            if(x[i].y1<=x[i].y2){
                                res=x[i].y1;
                            }
                            else{
                                res=x[i].y2;
                            }
                            a=x[i].x1;
                            b=x[i].y1;
                        }
                    }
                }
                cout<<res<<endl;
                if(yy==INT_MIN)break;

            }
            printf("%d\n",res);

        }


    }
    return 0;
}

