
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

std::vector<pii> adj[N];
int dis[N];

void bfs(int u){
	deque<int>q;
	dis[u]=0;
	q.push_front(u);

	while(!q.empty()){
		u=q.front();
		q.pop_front();

		for(auto x:adj[u]){
          if(dis[x.first]>dis[u]+x.ss){
          	dis[x.first]=dis[u]+x.second;
          }

          if(x.second==1){
          	q.push_back(x.ff);
          }
          else{
          	q.push_front(x.ff);
          }
		}

	}
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n,m;

	cin>>n>>m;

	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
	}
	memset(dis,M,sizeof(dis));
	bfs(1);


    return 0;
}
