#include<bits/stdc++.h>

using namespace std;
#define ll long long
int a[200009],ps[200009];



int main() {
    int n,m,pos;

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        cin>>a[i];
        if(a[i]==m) {
            pos=i;
        }
    }
    ll res=0;

    int left=0,right=0;
    for(int i=pos+1,j=1; i<=n; i++,j++) {
        if(a[i]<m) {
            left++;
        }
        right=(i-pos)-left;
        ps[j]=left-right;
//       cout<<ps[j]<<" ";
    }


    ps[n-pos+1]=0;
    sort(ps+1,ps+(n-pos)+2);

    int need=0,in1,in2,in3;
    left=0;
    for(int i=pos; i>=1; i--) {
        if(a[i]<m) {
            left++;
        }
        right=(pos-i)-left;
        need=left-right;
        cout<<need<<endl;
        if(need<=0){
            in1=upper_bound(ps+1,ps+(n-pos)+2,need+1)-(ps+1);
            //cout<<in1<<" ";
            //  in2=upper_bound(ps+1,ps+(n-pos)+2,need-1)-(ps+1);
            //  cout<<in2<<" ";

            in3=upper_bound(ps+1,ps+(n-pos)+2,need-1)-(ps+1);
            //cout<<in3<<endl;
        }
        else{
            in1=upper_bound(ps+1,ps+(n-pos)+2,need)-(ps+1);
            if(in1>(n-pos+1)){
                in1=1;
            }
            cout<<in1<<" ";
            //  in2=upper_bound(ps+1,ps+(n-pos)+2,need-1)-(ps+1);
            //  cout<<in2<<" ";

            in3=upper_bound(ps+1,ps+(n-pos)+2,need-2)-(ps+1);
            cout<<in3<<endl;
        }

//        in=upper_bound(ps+1,ps+(n-pos)+2,need-1)-(ps+1);



        res+=(ll)in1-(ll)in3;
    }

    cout<<res<<endl;
    return 0;
}
