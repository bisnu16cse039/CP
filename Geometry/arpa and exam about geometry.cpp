#include<bits/stdc++.h>

using namespace std;
#define ll long long

double epsilon=1e-9;
int main()
{
    ll ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    ll a=(ax-bx)*(ax-bx) + (ay-by)*(ay-by);
    ll b=(cx-bx)*(cx-bx) + (cy-by)*(cy-by);

    ll area = (ax-bx)*(by-cy) - (ay-by)*(bx-cx);


    if(a==b && area!=0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
