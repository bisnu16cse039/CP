
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

std::vector<int> adj[N];
int t=0;
int dis[N],fi[N],in[N];

bool vis[N];

void dfs(int u){
	vis[u]=true;
	++t;
	dis[u]=t;

	for(auto x:adj[u]){
		if(!vis[x]){
			dfs(x);
		}
	}

	++t;
    fi[u]=t;
}

pii p[N];
bool vis2[N];

void dfs2(int u){
	vis2[u]=true;

	for(auto x:adj[u]){
		if(!vis2[u]){
			dfs2(x);
		}
	}
}

int main()
{
	int n,m;

	n=ini(),m=ini();

	for(int i=1;i<=m;i++){
		int u=ini(),v=ini();
		adj[u].push_back(v);
	}
	std::vector<int> v;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
      p[i]={fi[i],i};
	}
	sort(p+1,p+n+1);
    int res=0;
	for(int i=n;i>=1;i--){
		if(!vis2[p[i].ss]){
			res++;
			dfs2(p[i].ss);
		}
	}
	printf("%d\n", res);
	

    return 0;
}

