
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
#define endl           '\n';
#define what_is(x)     cerr << #x << " is " << x << endl;
///*....Debugger....*/
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it){   cout << endl ;}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}
int ini(){int x; scanf("%d",&x);return x;}
long long inl(){ long long x;scanf("%lld",&x); return x;}
double ind(){double x; scanf("%lf",&x);return x;}
#define Iin ini();
#define Lin inl();
#define Din ind();

int set_1(int n,int pos){return n = (n | (1<<pos));}
int reset_0(int n,int pos){return n= n & ~(1<<pos);}
bool check_bit(int n,int pos){return n = n & (1<<pos);}

int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);
std::vector<int> adj[N];

bool vis[N];
int ti=1,dis[N],low[N],par[N],arti[N];
void articulation_point(int u,int p){
	dis[u]=low[u]=ti++;
	vis[u]=true;
	int children=0;
	for(auto v: adj[u]){
		if(v==p)continue;
		if(vis[v]){
			low[u]=min(low[u],low[v]);
		}
		else{
			articulation_point(v,u);
			low[u]=min(low[u],low[v]);
			if(dis[u]<=low[v] and u!=1){
				arti[u]=true;
			}
			else{
				children++;
			}
		}
	}
	if(children>1 and u==1){
		arti[u]=true;
	}
}

int main()
{
    int n,m;

    cin>>n>>m;

    for(int i=1;i<=m;i++){
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    articulation_point(1,-1);

    for(int i=1;i<=n;i++){
    	error(i,dis[i],low[i],arti[i]);
    }

    return 0;
}
