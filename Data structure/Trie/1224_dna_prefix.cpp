
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
map<char,int>m;

struct Trie
{
    int cnt;
    Trie *path[4];
 
    Trie()
    {
        cnt=0;
        for(int i=0; i<4; i++)path[i]=NULL;
    }
};
 
 
void insert(string s,Trie *root)
{
    Trie *node =root;
 
    for(int i=0; s[i]; i++)
    {
        int in=m[s[i]];
        if(node->path[in]==NULL)
        {
            node->path[in]=new Trie();
        }
        node=node->path[in];
        node->cnt++;
    }
}
int res=0;
void find_max(Trie *node,int level)
{
    for(int i=0; i<4; i++)
    {
        if(node->path[i]!=NULL)
        {
        	int r=node->path[i]->cnt;
        	r=r*level;
            res=max(res,r);
            //error((char)(i+'A'),level)
            find_max(node->path[i],level+1);

           
        }
    }
}
void del(Trie *node)
{
    if(node==NULL)return;
    for(int i=0; i<26; i++)
    {
        del(node->path[i]);
    }
    delete(node);
 
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t=ini(),te=0;
    m['A']=0,m['C']=1,m['T']=2,m['G']=3;
	while(t--){
		int n=ini();
        Trie *root = new Trie();
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			insert(s,root);
		}
		res=0;
		find_max(root,1);
		printf("Case %d: %d\n",++te,res);

		delete(root);
	}

    return 0;
}
