
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

vector<int>adj[N];
std::vector<int> res;
bool vis[7];
int used[10], num[10];
pii p[10];

void permutation(int at, int n) {
  if (at == n + 1) {
    std::vector<int> v;
    for (int i = 1; i <= n; i++) {
      v.push_back(num[i]);
      //error(num[i]);
    }
    bool f, f2;
    f = true;
    for (int k = 1; k <= 5; k++) {
      int x = p[k].first;
      int y = p[k].second;

      for (int i = 0; i < v.size(); i++) {
        if (v[i] == x) {
          f2 = false;
         // error(x, y);
          for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == y) {
              f2 = true;
              break;
            }
          }
          if (!f2) {
            f = false;
          }
          break;
        }
      }

    }
    if (f) {
      for (auto x : v) {
        char r = (char)(x - 1 + 'A');
        cout << r;
      }
      cout << endl;
      exit(0);
    }
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      used[i] = 1;
      num[at] = i;
      permutation(at + 1, n);
      used[i] = 0;
    }
  }
}


int main()
{

  for (int i = 1; i <= 5; i++) {
    char x1, c, x2;
    cin >> x1 >> c >> x2;

    if (c == '>') {
      p[i] = {x2 - 'A' + 1, x1 - 'A' + 1};
    }
    else {
      p[i] = {x1 - 'A' + 1, x2 - 'A' + 1};
    }
  }
  permutation(1, 5);

  cout << "impossible" << endl;

  return 0;
}
