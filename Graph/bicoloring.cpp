
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
int colour[N];
std::vector<int> adj[N];
bool bicoloring(int u){
	queue<int>q;
	q.push(u);
    colour[u]=1;
    while(!q.empty()){
    	int u=q.front();
    	q.pop();

    	for(int i=0;i<adj[u].size();i++){
    		int v=adj[u][i];

    		if(!colour[v]){
    			if(colour[u]==1){
    				colour[v]=2;
    			}
    			else{
    				colour[v]=1;
    			}
    			q.push(v);
    		}
    		if(colour[u]==colour[v]){
    			return false;
    		}
    	}
    }
    return true;

}
int main()
{
	int n=ini(),m=ini();

	for(int i=1;i<=m;i++){
		int u=ini(),v=ini();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool f=bicoloring(1);

	if(f){
		for(int i=1;i<=n;i++){
			cout<<colour[i]<<endl;
		}
	}


    return 0;
}
