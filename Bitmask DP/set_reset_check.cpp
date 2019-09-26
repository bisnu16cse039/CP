
#include<bits/stdc++.h>

using namespace std;
/**
********************************************************************
******************* Author:Bisnu sarkar ****************************
********************************************************************
**/

#define ull            unsigned long long
#define ll             long long
#define vi             vector<int>
#define pb             push_back
#define mp             make_pair
#define pii            pair<int,int>
#define vit            vector<int> :: iterator
#define sit            set<int> :: iterator
#define vrit           vector<int> :: reverse iterator
#define ff             first
#define ss             second

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

int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
int ini()
{
    int x;
    scanf("%d",&x);
    return x;
}
long long inl()
{
    long long x;
    scanf("%lld",&x);
    return x;
}

int set_1(int n,int pos){return n = (n | (1<<pos));}
int reset_0(int n,int pos){return n= n & ~(1<<pos);}
bool check_bit(int n,int pos){return n = n & (1<<pos);}

const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);

int main()
{
	ll n;
	cin>>n;
    int k=0;
    ll p=n;

    while(p>0){
    	p/=10;
    	k++;
    }
    if(k%2)k+=1;
    vector<ll>res;
    for(int i=k;i<=k+2;i+=2){
    	for(int mask=(1<<i); mask<(1<<(i+1));++mask){
    		ll num=0;
    		int c1=0,c2=0;
          for(int j=0;j<i;j++){
          	if(!check_bit(mask,j)){
               num=num*10 + 4;
               c1++;
          	} 
          	else{
               num=num*10 + 7;
               c2++;
          	}
          }
          if(c1==c2 and num>=n){
            res.push_back(num);
          }
    	}
    }
    sort(res.begin(),res.end());

    cout<<res[0]<<endl;
    return 0;
}
