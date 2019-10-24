
#include<bits/stdc++.h>
using namespace std;
/**
********************************************************************
******************* Author:Bisnu sarkar ****************************
********************************************************************
**/
#define ui             unsigned int
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
void err(istream_iterator<string> it) {   cout << endl ;}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cerr << *it << " = " << a << ' ' ;
	err(++it, args...);
}
int ini() {int x; scanf("%d", &x); return x;}
long long inl() { long long x; scanf("%lld", &x); return x;}
double ind() {double x; scanf("%lf", &x); return x;}
#define Iin ini();
#define Lin inl();
#define Din ind();

int set_1(int n, int pos) {return n = (n | (1 << pos));}
int reset_0(int n, int pos) {return n = n & ~(1 << pos);}
bool check_bit(int n, int pos) {return n = n & (1 << pos);}

int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int N = (int) 1e8 + 5;
const int M = (int) 1e9 + 7;
const double pi = 2 * acos(0.0);

int status[N >> 5];
int prime[5761459];
int p = 0;
void sieve(int x) {
	prime[p]=2;
	++p;
	for (int i = 3 ; i * i <= x ; i += 2) {
		if (check_bit(status[i >> 5], i & 31) == 0) {
			for (int j = i * i ; j <= x ; j += i + i)status[j >> 5] = set_1(status[j >> 5], j & 31);
		}
	}
	for (int i = 3; i <= x; i += 2) {
		if (check_bit(status[i >> 5], i & 31) == 0) {
			prime[p] = i;++p;
		}
	}
}
ui dp[5761459];

ui cal(int x) {
	int k = sqrt(x);
	ui ans = 1;
	for (int i = 0; prime[i] <= k; i++) {
		int present = x / prime[i];
		ui xx=1;
		while (present >= prime[i]) {
			present /= prime[i];
			xx *= (ui)prime[i];
		}
		ans*=xx;
	}

	return ans;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	sieve(N);
	//prime[0]=2;
	
	dp[0] = 2;
	for (int i = 1; i < p; i++) {
		dp[i] = dp[i - 1] * (ui)prime[i];
	}

	int t = Iin;
	int te = 0;
	while (t--) {
		int n;
		scanf("%d", &n);
		ui res = cal(n);
		res *= dp[upper_bound(prime, prime + p, n) - prime - 1];
		printf("Case %d: ", ++te);
		printf("%u\n", res);
	}
	return 0;
}


