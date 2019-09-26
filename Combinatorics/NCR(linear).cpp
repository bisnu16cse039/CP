
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
const ll M = (ll) 1e9 + 7;
const double pi=2* acos(0.0);

long long bigmod(long long b,long long p,long long m){
    if(p==0)return 1%m;
    long long x=bigmod(b,p/2,m);
    x=(x*x)%m;
    if(p%2==1)x=(x*b)%m;
    return x;
}


ll ncr(ll n,ll r){
	r= r>n-r?n-r:r;

	ll ans=1ll;

	for(ll i=1;i<=r;i++){
		ans = (ans*(n-r+i))%M;;
		ans=(ans * bigmod(i,M-2,M))%M;
	}
	return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t=ini(),te=0;

	while(t--){
		ll n=inl(),k=inl();

		printf("Case %d: %lld\n",++te,ncr(n+k-1,k-1));
	}


    return 0;
}
