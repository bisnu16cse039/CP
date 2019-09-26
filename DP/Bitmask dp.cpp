#include<bits/stdc++.h>

using namespace std;

#define what_is(x)     cerr << #x << " is " << x << endl;

///*....Debugger....*/

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it)
{
    cout << endl ;
}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}


int a[20];

int set_1(int n,int pos)  {return n = n | (1<<pos);}
int reset_0(int n,int pos){return n = n & ~(1<<pos);}
bool check(int n,int pos) {return n = n & (1<<pos);}

bool bitmask(int n){
    for(int mask=1;mask<(1<<n);mask++){
            int r=0;
        for(int j=0;j<n;j++){
            if(check(mask,j)){
              r+=a[j];
            }
            else{
                r-=a[j];
            }
        }
        if(r==0 or r%360==0){
            return true;
        }
    }
    return false;
}
int main()
{
    int n;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(bitmask(n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
