#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll a[200009];

ll total_segments(int low,int high,ll t) {
    if(low >= high) {
        if(low==high && a[low]<t)
            return 1;
        else
            return 0;
    }
    int mid=(low+high)/2;
    vector<ll>v;
    ll ans=0;
    ll s=0;
    for(int i=mid; i>=low; i--) {
        s+=a[i];
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    ll p=0;
    for(int i=mid+1; i<=high; i++) {
        p+=a[i];
        ll to_find=t-p-1;
        int pos = upper_bound(v.begin(), v.end(), to_find) - v.begin();
        //    cout<<"position: "<<pos<<"  To_find "<<to_find<<endl;
        ans+=pos;
    }
    //  cout<<ans<<endl;
    return total_segments(low,mid,t)+total_segments(mid+1,high,t)+ans;
}

int main() {
    int n;
    ll t;

    scanf("%d %lld",&n,&t);

    for(int i=1; i<=n; i++) {
        scanf("%lld",&a[i]);
    }
    ll res=total_segments(1,n,t);
    cout<<res<<endl;
    return 0;
}
