
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

int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int ini()
{
	int x;
	scanf("%d", &x);
	return x;
}
long long inl()
{
	long long x;
	scanf("%lld", &x);
	return x;
}

int set_1(int n, int pos) {return n = (n | (1 << pos));}
int reset_0(int n, int pos) {return n = n & ~(1 << pos);}
bool check_bit(int n, int pos) {return n = n & (1 << pos);}

const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi = 2 * acos(0.0);


struct trie
{
	trie *path[26];
	trie() {
		for (int i = 0; i < 26; i++) {
			path[i] = NULL;
		}
	}
};
trie *root;

void insert(string s) {
	trie *node = root;

	for (int i = 0; s[i]; i++) {
		if (node->path[i] == NULL) {
			node->path[s[i] - 'a'] = new trie();
		}
		node = node->path[s[i] - 'a'];
	}
}
void print(string s) {
	trie *node = root;

	for (int i = 0; s[i]; i++) {
		if (node->path[s[i] - 'a'] == NULL) {
			return;
		}
		node = node->path[s[i] - 'a'];
	}
}
void del(trie *node) {
	if (node == NULL)return;
	for (int i = 0; i < 25; i++) {
		del(node->path[i]);
	}
	delete(node);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	root = new trie();
	string s;
	cin >> s;

	insert(s);
	print(s);

   // del(root);
   // print(s);
	return 0;
}
