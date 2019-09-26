
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

ll ncr[22][22],dearrangement[22];

ll find_ncr(ll n,ll r) {
    if(r==1)return n;
    if(n==r or r==0)return 1;
    
    if(ncr[n][r]!=-1) {
        return ncr[n][r];
    }
    ncr[n][r]=find_ncr(n-1,r)+find_ncr(n-1,r-1);
    return ncr[n][r];
}
ll find_dearrangement(ll n){
	if(n==0)return 1;
	if(n==1)return 0;
	if(n==2)return 1;
    if(dearrangement[n]!=-1)return dearrangement[n];
	return dearrangement[n]=(n-1)*(find_dearrangement(n-1)+find_dearrangement(n-2));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(ncr,-1,sizeof(ncr));
    memset(dearrangement,-1,sizeof(dearrangement));
   
    ll n,m;

    while(scanf("%lld %lld",&n,&m)==2){
    	ll res=0ll;
    	for(ll i=0;i<=m;i++){ 	
           res+=find_ncr(n,i)*find_dearrangement(n-i);
           
    	}
    	printf("%lld\n", res);
    }



    return 0;
}
