
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

const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi = 2 * acos(0.0);
int a[N];

int kadane() {
	int max_ending_here = 0, ma = 0;
	for (int i = 1; i <= n; i++) {
		max_ending_here += a[i];

		if (max_ending_here < 0)max_ending_here = 0;

		if (max_ending_here > ma) {
			ma = max_ending_here;
		}
	}
	return ma;
}
int main()
{
	int n = ini(), c = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = ini();
		if (a[i] < 0)c++;
	}
	if (c == n) {
		sort(a + 1, a + n + 1);
		cout << a[n] << endl;
	}
	else {
		int max_ending_here = 0, ma = 0;
		for (int i = 1; i <= n; i++) {
			max_ending_here += a[i];

			if (max_ending_here < 0)max_ending_here = 0;

			if (max_ending_here > ma) {
				ma = max_ending_here;
			}
		}
		cout << ma << endl;
	}


	return 0;
}
