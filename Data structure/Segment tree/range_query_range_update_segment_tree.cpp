
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

const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);

int a[N];
ll tree[N*4],pro[N*4];

void build(int in,int l,int r){
	if(l==r){
		tree[in]=(ll)a[l];
		return;
	}
	int mid=(l+r)>>1;
	int pos=in<<1;
	build(pos,l,mid);
	build(pos+1,mid+1,r);
	tree[in]=tree[pos]+tree[pos+1];
}

void update(int in,int b,int e,int l,int r,ll v){
   if(b>r or e<l)return;

   if(b>=l and e<=r){
   	tree[in]+=(ll)(e-b+1)*v;
   	pro[in]+=v;
   }
   int mid=(b+e)>>1;
   int pos=in<<1;
   update(pos,b,mid,l,r,v);
   update(pos+1,mid+1,e,l,r,v);
   tree[in]=tree[pos]+tree[pos+1]+ (ll)(e-b+1)*v;
}
long long query(int in,int b, int e,int l, int r,int carry){
	if(b>r and e<l)return 0;
	if(b>=l and e<=r){
		return tree[in]+(e-b+1)*carry;
	}
    int mid=(b+e)>>1;
    int pos=in<<1;
    ll p=query(pos,b,mid,l,r,carry+pro[in]);	
    ll q=query(pos+1,mid+1,e,l,r,carry+pro[in]);	
    return p+q;
}

int main()
{
	int n=ini(),q=ini();

	for(int i=1;i<=n;i++)a[i]=ini();
    build(1,1,n);

    while(q--){
    	int op=ini();

    	if(op==1){
    		int l=ini(),r=ini();
    		ll v=inl();
    		update(1,1,n,l,r,v);
    	}
    	else{
    		int l=ini(),r=ini();
    		ll res=query(1,1,n,l,r,0);
    		printf("%lld\n", res);
    	}
    }

    return 0;
}
