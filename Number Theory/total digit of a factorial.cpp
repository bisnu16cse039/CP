#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,d,b;
    double a=0.0;
    cin>>n;
    for(int i=1;i<=n;i++){
        a+=log10(i);
        cout<<a<<endl;
    }
    b=floor(a);
    d=b+1;
    cout<<d<<endl;
    return 0;
}
