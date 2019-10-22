#include<bits/stdc++.h>

using namespace std;
#define pi acos(-1)
#define ll long long

double CalcHalf(ll r1, ll r2, ll dx, ll dy) {
    ll l2 = dx * dx + dy*dy;
    double l = sqrt( static_cast<double>(l2) );
    double x = static_cast<double>(r1*r1 - r2*r2 + l2) / (2.0 * l);
    double angle = 0.0;

    if (sqrt(2.0) * x < static_cast<double>(r1)) {
        angle = acos( x / r1 );
    } else {
        double S = sqrt( static_cast<double>( (r1+r2)*(r1+r2) - l2 ) * static_cast<double>(l2 - (r1-r2)*(r1-r2)) ) / 4.0;
        double y = 2.0 * S / l;
        if (y / r1 < 0.1) {
            // SPECIAL CASE FOR SMALL ANGLES
            // asin(x)= x + 1/6 x^3 + 3/40 x^5 + 5/112 x^7 + 35/1152 x^9 + 63/2816 x^11 + 231/13312 x^13 + 143/10240 x^15 +...
            double c[12] = { 0, 0, 0, 1.0 / 6.0, 0.0, 3.0 / 40.0, 0.0, 5.0 / 112.0, 0.0, 35.0 / 1152.0, 0.0, 63.0 / 2816.0 };
            double v[12] = { 0 };
            double vSin = 1.0;
            double sin2A = 2.0 * (y / r1) * (x/r1);
            for (size_t i = 0; i < 12; ++i) {
                v[i] = vSin * c[i];
                vSin *= sin2A;
            }

            double s = 0.0;
            for (int i = 11; i >= 0; --i)
                s += v[i];

            return static_cast<double>(r1*r1) * s / 2.0;
        }

        angle = asin(y / r1);
    }

    return static_cast<double>(r1*r1) * ( 2 * angle - sin(2*angle) ) / 2.0 ;
}
int main() {

    int t,te=1;
    scanf("%d",&t);

    while(t--) {
        ll a1,b1,c1,a2,b2,c2;
        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;

        double x1,y1,r1,x2,y2,r2;
        x1=a1,x2=a2,y1=b1,y2=b2,r1=c1,r2=c2;


        double res=0.0;
        a2 -= a1;
        b2 -= b1;
        a1 = b1 = 0;
        ll l=a2*a2 + b2*b2;
        double dis=sqrt(l);

        if ((r1 + r2)*(r1 + r2) <= a2*a2 + b2*b2) {
            res=0.0;
        } else if(dis+(double)min(c1,c2)<=(double)max(c1,c2)) {
            double r=min(r1,r2);
            res=pi*r*r;
        } else {
            res=CalcHalf(c1, c2, a2, b2) + CalcHalf(c2, c1, a2, b2);

        }
        printf("Case %d: %.10f\n",te++,res);
    }
    return 0;
}

