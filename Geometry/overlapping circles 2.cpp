#include<bits/stdc++.h>

using namespace std;
#define pi acos(-1)

int main() {

    int t,te=1;
    scanf("%d",&t);

    while(t--) {

        double x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1;
        cin>>x2>>y2>>r2;

        double dis=sqrt(((x1-x2)*(x1-x2))+ (y1-y2)*(y1-y2));
        double res=0.0;
        if(dis>=r1+r2) {
            res=0.0;
        } else if(dis+min(r1,r2)<=max(r1,r2)) {
            double r=min(r1,r2);
            res=pi*r*r;
        } else {
            double p1=max(r1,r2);
            double p2=min(r1,r2);

            double angle1=acos((p1*p1 + dis*dis - p2*p2)/(2*p1*dis));
            double angle2=acos((p2*p2 + dis*dis - p1*p1)/(2*p2*dis));
            angle1*=2;
            angle2*=2;

            double res1=0.5*p1*p1*(angle1);
            double res2=0.5*p2*p2*(angle2);
            res=res1+res2-(0.5*p1*p1*sin(angle1))-(0.5*p2*p2*sin(angle2));

        }
        printf("Case %d: %.10f\n",te++,res);
    }
    return 0;
}

