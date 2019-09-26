
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
std::vector<int> adj[N];
int parent[N],level[N],sparse_table[N][22];

void dfs(int par,int u,int dep){
   level[u]=dep;
   parent[u]=par;

   for(auto v : adj[u]){
     if(v!=par){
      dfs(u,v,dep+1);
     }
   }

}
void lca_build(int n){
  memset(sparse_table, -1 ,sizeof(sparse_table));
    for(int i=1;i<=n;i++){
      sparse_table[i][0]=parent[i];
    }
    for(int j=1;1<<j <= n;j++){
       for(int i=1;i<=n;i++){
        if(sparse_table[i][j-1]!=-1){
         sparse_table[i][j]=sparse_table[sparse_table[i][j-1]][j-1];
        }
      }
    }
}

int query(int n,int p,int q){
  if(level[p]<level[q]){
    int t=p;
    p=q;
    q=t;
  }

  int height=1;
  while(1){
    if(1<<(height+1) >level[p]){
      break;
    } 
    ++height;
  }
  for(int i=height;i>=0;i--){
    if(((level[p]- 1)<<i)>=level[q]){
      p=sparse_table[p][i];
    }
  }
  if(p==q){
    return p;
  }
  for(int i=height;i>=0;i--){
    if(sparse_table[p][i]!=-1 and sparse_table[p][i]!=sparse_table[q][i]){
      p=sparse_table[p][i],q=sparse_table[q][i];
    }
  }
  return parent[p];

}
int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	dfs(0,0,0);
	lca_build(n);
    for(int j=1;1<<j < n;j++){
       for(int i=0;i<n;i++){
       	cout<<sparse_table[i][j]<<" ";
       }
       cout<<endl;
    }
    int qq;
    cin>>qq;
    while(qq>0){
    	int p,q;
    	cin>>p>>q;
    	cout<<query(n,p,q)<<endl;
    }

    return 0;
}
