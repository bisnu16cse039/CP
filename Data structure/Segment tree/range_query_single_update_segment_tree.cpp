
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
ll tree[N*4];

void build(int in,int b,int e){
	if(b==e){
		tree[in]=(ll)a[b];
		return;
	}
	int mid=(b+e)>>1;
	int p=in<<1;
	build(p,b,mid);
	build(p + 1,mid+1,e);
    tree[in]=tree[p]+tree[p+1];
}
void update(int in,int b,int e,int x,ll v){
	if(b>x or e<x)return;
     
    if(b>=x and e<=x){
    	tree[in]=tree[in] + v;
    	//error(tree[in]);
    	return;
    }
	int mid=(b+e)>>1;
	int p=in<<1;
	update(p,b,mid,x,v);
	update(p+1,mid+1,e,x,v);
    tree[in]=tree[p]+tree[p+1];
}
ll query(int in,int b,int e,int l, int r){
	if(b>r or e<l)return 0ll;
	if(b>=l and e<=r){
		//error(tree[in]);
		return tree[in];
	}
	int mid=(b+e)>>1;
	int p=in<<1;
	ll x=query(p,b,mid,l,r);
	ll y=query(p+1,mid+1,e,l,r);
    return x+y;
}

int main()
{
   int t=ini(),te=0;

   while(t--){
   	memset(tree,0,sizeof(tree));
   	int n=ini(),q=ini();
   	for(int i=1;i<=n;i++){
   		a[i]=ini();
   	}
   	build(1,1,n);
   	printf("Case %d:\n", ++te);
    while(q--){
    	int op=ini();
    	if(op==1){
    		int x=ini();
    		ll res=query(1,1,n,x+1,x+1);
    		printf("%lld\n", res);
    		update(1,1,n,x+1,-res);
    	}
    	else if(op==2){
    		int in;
    		ll v;
    		in=ini(),v=inl();
    		update(1,1,n,in+1,v);
    	}
    	else{
    		int l=ini(),r=ini();
    		ll res=query(1,1,n,l+1,r+1);
    		printf("%lld\n", res);
    	}
    }
   }

    return 0;
}
