#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n,t=0,b;
    double a;
    cin>>n;
    for(int i=5; ;i*=5){
        a=n/i;
        if(a<=0)
            break;

        b=ceil(a);
        t+=b;

    }
    cout<<t<<endl;
    return 0;
}
